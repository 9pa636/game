#include <iostream>
#include "GameSystem.h"
#include "Boy.h"
#include "StaticObj.h"
#include <SFML/Graphics.hpp>


GameSystem::GameSystem(sf::RenderWindow *wnd, sf::Clock clock)
{
	sys = new ParticleSystem();
	this->wnd = wnd;
	this->clock = clock;

	StaticObj *newBackground = new StaticObj(this, Vector2f(500.0, 350.0), 0, Vector2f(500.0, 350.0));
	objects.push_back(newBackground);

	Boy *newBoy = new Boy(this, Vector2f(350.0, 560.0), 0, Vector2f(80.0, 130.0));
	objects.push_back(newBoy);

	this->camera.pos.x = wnd->getSize().x / 2.0;
	this->camera.pos.y = wnd->getSize().y / 2.0;
	this->camera.fieldOfView = wnd->getSize().x;
	this->camera.ang = 0.0;

	
}


void GameSystem::Update(float dt)
{
	
	for (size_t i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(dt);
	}
	float step = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->camera.pos.y -= step;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->camera.pos.y += step;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->camera.pos.x -= step;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->camera.pos.x += step;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		this->camera.fieldOfView -= step;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		this->camera.fieldOfView += step;
	}
}

ParticleSystem *GameSystem::GetParticleSystem()
{
	return this->sys;
}

sf::RenderWindow *GameSystem::GetWindow()
{
	return this->wnd;
}

void GameSystem::Draw(){
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Draw();
	}
}

float GameSystem::GetTime()
{
	return this->clock.getElapsedTime().asSeconds();
}


void GameSystem::AddObject(GameObject* newObject) 
{
	objects.push_back(newObject);
}

