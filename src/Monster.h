#pragma once
#include "GameSystem.h"
#include "Sprite.h"
#include "ParticleSystem.h"
#include <string>
using namespace std;

class Monster : public GameObject //наследник
{
public:
	Monster(){}
	Monster(GameSystem *owner, Vector2f pos, float ang, Vector2f size, string a); 
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
};