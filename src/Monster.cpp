#include "Monster.h"
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
	
	this->particle->Integrate(dt);

}

void Monster::Draw()
{
	sprite.DrawWorldspace(owner->GetWindow(), particle->pos, ang, size, owner->camera);
}

Vector2f Monster::GetPosition()
{
	return this->pos;
}