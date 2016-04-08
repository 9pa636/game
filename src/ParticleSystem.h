#pragma once
#include "Vector2f.h"
#include <math.h>

class Particle
{
public:
	void Integrate(float dt)
	{
		Vector2f currPos = pos;
		pos = pos + (pos - prevPos); // + acceleration * dt * dt;
		prevPos = currPos;
	}
	/*
	void IntegrateRocket(float dt, Vector2f target, Vector2f shipPos)
	{
	ang = atan2f(target.x - shipPos.x, -target.y + shipPos.y);
	//	prevPos = pos;
	Vector2f delta = Vector2f(target.x, target.y) - shipPos;
	pos = pos + delta * (speed / delta.Length());
	*/
	

	void Push(Vector2f force)
	{
		prevPos = prevPos - force;
	}
	float radius;
	Vector2f pos;
	Vector2f prevPos;
	Vector2f acceleration;

};
	struct Link
	{
		Link(){}
		Link(Particle *p0, Particle *p1, float stiffness)
		{
			this->p0 = p0;
			this->p1 = p1;
			this->stiffness = stiffness;
			this->defLength = (p0->pos - p1->pos).Length();
		}

		void Solve()
		{
			Vector2f delta = p1->pos - p0->pos;
			float deform = delta.Length() - this->defLength;
			p0->pos = p0->pos + delta.GetNorm() * deform * 0.5 * stiffness;
			p1->pos = p1->pos + delta.GetNorm() * deform * -0.5 * stiffness;

		}
		Particle *p0;
		Particle *p1;
		float stiffness;
		float defLength;
	};

	class VolumeLink
	{
	public:
		VolumeLink(){}
		VolumeLink(Particle **particles, int count)
		{
			for (int i = 0; i < count; i++)
				this->volumeParticles.push_back(particles[i]);
			this->currVolume = ComputeVolume();
			this->initialVolume = ComputeVolume();
			this->atmosphericPressure = 0.0005f;
			this->initialPressure = 0.0006f;
			this->pressureDiff = atmosphericPressure - initialPressure;

		}

		float ComputeVolume()
		{
			float volume = 0;
			for (size_t i = 0; i < volumeParticles.size(); i++)
				volume += volumeParticles[(i + 1) % volumeParticles.size()]->pos ^ volumeParticles[i]->pos * 0.5f;
			return volume;
		}

		float currVolume;
		float atmosphericPressure;
		float initialPressure;
		float initialVolume;
		float pressureDiff;

		void VolumeSolve()
		{
			currVolume = ComputeVolume();
			pressureDiff = (initialPressure * initialVolume / currVolume) - atmosphericPressure;
			for (size_t i = 0; i < volumeParticles.size(); i++)
			{
				Vector2f delta = volumeParticles[(i + 1) % volumeParticles.size()]->pos - volumeParticles[i]->pos;
				Vector2f force = Vector2f(delta.y, -delta.x) * pressureDiff;
				volumeParticles[(i + 1) % volumeParticles.size()]->pos = volumeParticles[(i + 1) % volumeParticles.size()]->pos + force;
				volumeParticles[i]->pos = volumeParticles[i]->pos + force;
			}

		}
	private:
		std::vector<Particle *> volumeParticles;
		float k = 0.00009f;
	};



	class ParticleSystem
	{
	public:
		ParticleSystem(){	}

		void Update()
		{
			for (size_t particleIndex = 0; particleIndex < particles.size(); particleIndex++)
			{
				particles[particleIndex]->Integrate(1e-2f);

				float floorLevel = 700.0f;
				float wall = 700.0f;
				if (particles[particleIndex]->pos.y > floorLevel)
				{
					particles[particleIndex]->pos.y = floorLevel;
					//			particles[particleIndex]->prevPos.x = particles[particleIndex]->pos.x;
				}
				if (particles[particleIndex]->pos.y < 0)
				{
					particles[particleIndex]->pos.y = 0;
					//			particles[particleIndex]->prevPos.x = particles[particleIndex]->pos.x;
				}
				if (particles[particleIndex]->pos.x < 0)
				{
					particles[particleIndex]->pos.x = 0;
					//			particles[particleIndex]->prevPos.y = particles[particleIndex]->pos.y;
				}
				if (particles[particleIndex]->pos.x > wall)
				{
					particles[particleIndex]->pos.x = wall;
					//			particles[particleIndex]->prevPos.y = particles[particleIndex]->pos.y;
				}
			}

			for (size_t linkIndex = 0; linkIndex < links.size(); linkIndex++)
			{
				links[linkIndex].Solve();
			}
			volumeLink.VolumeSolve();
		}

		Particle *AddParticle(Vector2f pos, float radius)
		{
			Particle *newbie = new Particle;
			newbie->pos = pos;
			newbie->prevPos = newbie->pos;
			newbie->acceleration = Vector2f(0.0f, 1.0f);
			newbie->radius = 20.0f;
			particles.push_back(newbie);

			//return particle[particle.size() - 1]; 1 способ
			return particles.back();
		}

		void AddLink(Particle *p0, Particle *p1, float stiffness)
		{
			Link link = Link(p0, p1, stiffness);
			links.push_back(link);
		}

		void AddVolumeLink(Particle ** particles, int size)
		{
			volumeLink = VolumeLink(particles, size);
		}

		void Right()
		{
			particles[0]->pos = particles[0]->pos + Vector2f(step, 0.0f);
		}
		void Left()
		{
			particles[0]->pos = particles[0]->pos + Vector2f(-step, 0.0f);
		}
		void Up()
		{
			particles[0]->pos = particles[0]->pos + Vector2f(0.0f, -step);
		}
		void Down()
		{
			particles[0]->pos = particles[0]->pos + Vector2f(0.0f, step);
		}
		size_t GetParticlesCount()
		{
			return particles.size();
		}
		Particle *GetParticle(int particleIndex)
		{
			return particles[particleIndex];
		}

	private:
		std::vector <Particle*> particles;
		std::vector <Link> links;
		float step = 0.005f;
		VolumeLink volumeLink;
	};




