#include <iostream>
#include "GameSystem.h"
#include "Boy.h"
#include "Monster.h"
#include "Furniture.h"
#include "StaticObj.h"
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;


GameSystem::GameSystem(sf::RenderWindow *wnd, sf::Clock clock)
{
	sys = new ParticleSystem();
	this->wnd = wnd;
	this->clock = clock;

	StaticObj *newBackground = new StaticObj(this, Vector2f(500.0, 400.0), 0, Vector2f(500.0, 300.0));
	objects.push_back(newBackground);

	Furniture *newDesk = new Furniture(this, Vector2f(680.0, 600.0), 0, Vector2f(120.0, 70.0), "data/desk2.png");
	objects.push_back(newDesk);

	Furniture *newRose = new Furniture(this, Vector2f(610.0, 495.0), 0, Vector2f(30.0, 40.0), "data/rose2.png");
	objects.push_back(newRose);

	Furniture *newLaptop = new Furniture(this, Vector2f(720.0, 495.0), 0, Vector2f(70.0, 40.0), "data/laptop2.png");
	objects.push_back(newLaptop);

	Furniture *newBed = new Furniture(this, Vector2f(400.0, 600.0), 0, Vector2f(130.0, 80.0), "data/bed2.png");
	objects.push_back(newBed);

	Furniture *newCupboard = new Furniture(this, Vector2f(130.0, 500.0), 0, Vector2f(100.0, 175.0), "data/cupboard2.png");
	objects.push_back(newCupboard);

	Furniture *newPr = new Furniture(this, Vector2f(170.0, 284.0), 0, Vector2f(30.0, 45.0), "data/present2.png");
	objects.push_back(newPr);

	Furniture *newLamp = new Furniture(this, Vector2f(500.0, 240.0), 0, Vector2f(230.0, 140.0), "data/lamp2.png");
	objects.push_back(newLamp);

	Boy *newBoy = new Boy(this, Vector2f(350.0, 560.0), 0, Vector2f(80.0, 130.0));
	objects.push_back(newBoy);

	Monster *newMonster = new Monster(this, Vector2f(800.0, 200.0), 0, Vector2f(80.0, 80.0), "data/monster1.png" );
	objects.push_back(newMonster);

	

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

