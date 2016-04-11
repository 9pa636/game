#include "Boy.h"
#include <iostream>
#include <windows.h>
#include <map>
#include <string>
using namespace std;

string getTex(int a)
{
	std::map<int, std::string> boyTex;
	boyTex[0] = "data/boy/0.png";
	boyTex[1] = "data/boy/1.png";
	boyTex[2] = "data/boy/2.png";
	boyTex[3] = "data/boy/3.png";
	boyTex[4] = "data/boy/4.png";
	boyTex[5] = "data/boy/5.png";
	boyTex[6] = "data/boy/6.png";
	boyTex[7] = "data/boy/7.png";
	boyTex[8] = "data/boy/8.png";
	boyTex[9] = "data/boy/9.png";
	boyTex[10] = "data/boy/10.png";
	boyTex[0] = "data/boy/0.png";
/*	boyTex[1] = "data/boy/1.gif";
	boyTex[2] = "data/boy/2.gif";
	boyTex[3] = "data/boy/3.gif";
	boyTex[4] = "data/boy/4.gif";
	boyTex[5] = "data/boy/5.gif";
	boyTex[6] = "data/boy/6.gif";
	boyTex[7] = "data/boy/7.gif";
	boyTex[8] = "data/boy/8.gif";
	boyTex[9] = "data/boy/9.gif";
	boyTex[10] = "data/boy/10.gif";*/
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
	this->sprite = Sprite("data/boy/0.png");
	this->time = owner->GetTime();
	this->n = 0;
	this->orientation = "right";
}

void Boy::Update(float dt)
{
	float force = 0.0001;
	float step = 0.1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->particle->Push(Vector2f(sinf(ang)*force, -cosf(ang)*force));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->particle->Push(Vector2f(-sinf(ang)*force, cosf(ang)*force));
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
					this->sprite = Sprite(getTex(this->n));
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
						this->sprite = Sprite(getTex(this->n));
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

