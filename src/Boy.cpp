#include "Boy.h"
#include <iostream>
#include <windows.h>
#include <map>
#include <string>
using namespace std;

string getTex(int a, string move)
{
	std::map<int, std::string> boyTex;

	if (move == "walk")
	{
		boyTex[0] = "data/walk/00.png";
		boyTex[1] = "data/walk/01.png";
		boyTex[2] = "data/walk/02.png";
		boyTex[3] = "data/walk/03.png";
		boyTex[4] = "data/walk/04.png";
		boyTex[5] = "data/walk/05.png";
		boyTex[6] = "data/walk/06.png";
		boyTex[7] = "data/walk/07.png";
		boyTex[8] = "data/walk/08.png";
		boyTex[9] = "data/walk/09.png";
		boyTex[10] = "data/walk/010.png";
	}
	else
	{
//		boyTex[0] = "data/jump/00.png";
		boyTex[1] = "data/jump/1.png";
		boyTex[2] = "data/jump/2.png";
		boyTex[3] = "data/jump/3.png";
		boyTex[4] = "data/jump/4.png";
		boyTex[5] = "data/jump/5.png";
		boyTex[6] = "data/jump/6.png";
		boyTex[7] = "data/jump/7.png";
		boyTex[8] = "data/jump/8.png";
		boyTex[9] = "data/jump/9.png";
		boyTex[10] = "data/jump/10.png";
		boyTex[11] = "data/jump/11.png";
		boyTex[12] = "data/jump/12.png";
		boyTex[13] = "data/jump/13.png";
	}

	return boyTex[a];
}

Boy::Boy(GameSystem *owner, Vector2f pos, float ang, Vector2f size)
{
	

/*	if (marks.find("s") != marks.end())
	{
		//element present
	}
*/

	this->owner = owner;
	this->particle = this->owner->GetParticleSystem()->AddParticle(pos, size.Length()/2.0f);
	this->ang = ang;
	this->size = size;
	this->pos = pos;
	this->sprite = Sprite("data/walk/00.png");
	this->time = owner->GetTime();
	this->n = 0;
	this->orientation = "right";
}

void Boy::Update(float dt)
{
	float force = 0.00001;
	float step = 0.1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
//		this->orientation = "right";
		if (owner->GetTime() - this->time1 > 0.0008)
		{
			if (owner->GetTime() - this->time > 0.1)
			{
				if (this->n <= 13)
				{
					this->sprite = Sprite(getTex(this->n, "jump"));
					n++;
				}
				else
					this->n = 1;
				this->time = owner->GetTime();
			}
			
		//	this->particle->pos.y -= force;
		//	this->particle->Integrate(dt);
			this->time1 = owner->GetTime();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->orientation = "right";
		if (owner->GetTime() - this->time1 > 0.0008)
		{
			if (owner->GetTime() - this->time > 0.1)
			{		
				if (this->n <= 10)
				{
					this->sprite = Sprite(getTex(this->n, "walk"));
					n++;
				}
				else
					this->n = 1;
				this->time = owner->GetTime();
			}
			this->particle->pos.x += step;
			this->time1 = owner->GetTime();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		{
			this->orientation = "left";
			if (owner->GetTime() - this->time1 > 0.0008)
			{
				if (owner->GetTime() - this->time > 0.1)
				{
					if (this->n <= 10)
					{
						this->sprite = Sprite(getTex(this->n, "walk"));
						n++;
					}
					else
						this->n = 1;
					this->time = owner->GetTime();
				}
				this->particle->pos.x -= step;
				this->time1 = owner->GetTime();
			}
		}
	}

}

void Boy::Draw()
{
	sprite.DrawWorldspace(owner->GetWindow(), particle->pos, ang, size, owner->camera, orientation);
}

Vector2f Boy::GetPosition()
{
	return this->pos;
}

