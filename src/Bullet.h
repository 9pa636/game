#pragma once
#include "GameSystem.h"
#include "Sprite.h"
#include "ParticleSystem.h"

class Bullet : public GameObject 
{
public:
	Bullet(){}
	Bullet(GameSystem *owner, Vector2f pos, float ang, Vector2f size, Vector2f target);
	void Update(float dt);
	void Draw();
	Vector2f pos;
	Vector2f target;
private:
	Sprite sprite;
	Particle *particle;
	GameSystem *owner;
	float ang;
	Vector2f size;
	float speed = 20.0;
};