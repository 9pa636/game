#include "Boy.h"
#include "StaticObj.h"
#include <iostream>

StaticObj::StaticObj(GameSystem *owner, Vector2f pos, float ang, Vector2f size)
{
	this->owner = owner;
	this->particle = this->owner->GetParticleSystem()->AddParticle(pos, size.Length() / 2.0f);
	this->ang = ang;
	this->size = size;
	this->pos = pos;
	this->sprite = Sprite("data/room2.png");

}

void StaticObj::Update(float dt)
{
	
}

void StaticObj::Draw()
{
	sprite.DrawWorldspace(owner->GetWindow(), particle->pos, ang, size, owner->camera);
	//	std::cout << "Ship draw";
	//	Sprite sprite1 = Sprite("data/space.jpg");
	//	sprite1.Draw(owner->GetWindow(), Vector2f(100.0, 100.0), 0, Vector2f(700.0, 700.0));
}

Vector2f StaticObj::GetPosition()
{
	return this->pos;
}