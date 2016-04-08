#include "Boy.h"
#include <iostream>
#include <windows.h>

Boy::Boy(GameSystem *owner, Vector2f pos, float ang, Vector2f size)
{
	this->owner = owner;
	this->particle = this->owner->GetParticleSystem()->AddParticle(pos, size.Length()/2.0f);
	this->ang = ang;
	this->size = size;
	this->pos = pos;
	this->sprite = Sprite("data/2.png");
	this->time = 0;
}

void Boy::Update(float dt)
{
	float force = 0.0001;
	float angStep = 0.003;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		this->particle->Push(Vector2f(sinf(ang)*force, -cosf(ang)*force));
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		this->particle->Push(Vector2f(-sinf(ang)*force, cosf(ang)*force));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		this->ang += angStep;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		this->ang -= angStep;
	}
	this->particle->Integrate(dt);

/*	if (owner->GetTime() - this->time > 0.6)
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			Rocket *newRocket = new Rocket(this->owner, particle->pos, ang, Vector2f(5.0, 10.0));
			owner->AddObject(newRocket);
			this->time = owner->GetTime();
		}*/
	
	/*    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		
		{
			Rocket *newRocket = new Rocket(this->owner, particle->pos, ang, Vector2f(5.0, 10.0), Vector2f(sf::Mouse::getPosition(*owner->GetWindow()).x, sf::Mouse::getPosition(*owner->GetWindow()).y));
			owner->AddObject(newRocket);
			this->time = owner->GetTime();
		}*/

}

void Boy::Draw()
{
	sprite.DrawWorldspace(owner->GetWindow(), particle->pos, ang, size, owner->camera);
}

Vector2f Boy::GetPosition()
{
	return this->pos;
}