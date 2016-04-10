#include "Bullet.h"
#include <iostream>

Bullet::Bullet(GameSystem *owner, Vector2f pos, float ang, Vector2f size, Vector2f target)
{
	this->owner = owner;
	this->particle = this->owner->GetParticleSystem()->AddParticle(pos, size.Length()/2.0f);
	this->ang = ang;
	this->size = size;
	this->sprite = Sprite("data/flashlight2.png");
	this->pos = pos;
	this->target = target;

}

/*Vector2f Coord(GameSystem *owner, Rocket *rocket)
{
	float pi = 3.14;
	Vector2f xVector = Vector2f(owner->camera.ang);
	Vector2f yVector = Vector2f(owner->camera.ang + pi / 2.0);

	Vector2f delta1 = rocket->pos + owner->camera.pos;
	Vector2f localPos = Vector2f(xVector*delta1, yVector*delta1);

	Vector2f delta2 = rocket->target + owner->camera.pos;
	Vector2f localTarget = Vector2f(xVector*delta2, yVector*delta2);
}*/

void Bullet::Update(float dt)
{
	particle->prevPos = particle->pos;
	particle->pos = particle->pos + target *(speed *dt / target.Length());
}

void Bullet::Draw()
{
	sprite.DrawWorldspace(owner->GetWindow(), particle->pos, ang, size, owner->camera, "right");
}
