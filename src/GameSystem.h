#pragma once
#include <vector>
#include "ParticleSystem.h"
#include <SFML/Graphics.hpp>
#include "Sprite.h"

class GameObject
{
public:
	virtual void Update(float dt) = 0;
	virtual void Draw() = 0;
};

class GameSystem
{
public:
	GameSystem(){};
	GameSystem(sf::RenderWindow *wnd, sf::Clock clock);
	void Update(float dt);
	void Draw();
	ParticleSystem *GetParticleSystem();
	sf::RenderWindow *GetWindow();
	Camera camera;
	void AddObject(GameObject* newObject);
	float GetTime();
private:
	std::vector<GameObject *> objects;
	ParticleSystem * sys;
	sf::RenderWindow *wnd;
	sf::Clock clock;
};

