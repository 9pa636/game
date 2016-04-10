#include "Monster.h"
#include "Bullet.h"
//#include "Rocket.h"
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

Monster::Monster(GameSystem *owner, Vector2f pos, float ang, Vector2f size, string a)
{
	this->owner = owner;
	this->particle = this->owner->GetParticleSystem()->AddParticle(pos, size.Length()/2.0f);
	this->ang = ang;
	this->size = size;
	this->pos = pos;
	this->sprite = Sprite(a);
	this->time = 0;
}

void Monster::Update(float dt)
{
	
//	this->particle->Integrate(dt);
	float speed = 1;
	float x = owner->GetParticleSystem()->GetParticle(8)->pos.x - particle->pos.x;
	float y = owner->GetParticleSystem()->GetParticle(8)->pos.y - particle->pos.y;
	Vector2f target = Vector2f(x, y);
	particle->prevPos = particle->pos;
	particle->pos = particle->pos + target *(speed *dt / target.Length());
	if (owner->GetTime() - this->time > 5)
	{
		
		float x = owner->GetParticleSystem()->GetParticle(8)->pos.x - particle->pos.x;
		float y = owner->GetParticleSystem()->GetParticle(8)->pos.y - particle->pos.y;
		Vector2f target = Vector2f(x, y);
		Bullet *newBullet = new Bullet(this->owner, particle->pos + target*(120/target.Length()), atan2f(-x, y), Vector2f(15.0, 30.0), target);
		owner->AddObject(newBullet);		
		this->time = owner->GetTime();
	}
}

void Monster::Draw()
{
	sprite.DrawWorldspace(owner->GetWindow(), particle->pos, ang, size, owner->camera, "right");
}

Vector2f Monster::GetPosition()
{
	return this->pos;
}