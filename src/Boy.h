#pragma once
#include "GameSystem.h"
#include "Sprite.h"
#include "ParticleSystem.h"
#include <map>

class Boy : public GameObject 
{
public:
	Boy(){}
	Boy(GameSystem *owner, Vector2f pos, float ang, Vector2f size); 
	void Update(float dt);
	void Draw();
	Vector2f GetPosition();
	

private:
	Sprite sprite;
	Particle *particle;
	GameSystem *owner;
	float ang;
	Vector2f size;
	Vector2f pos;
	float time;
	float time1;
	int n;
	string orientation;
	
};