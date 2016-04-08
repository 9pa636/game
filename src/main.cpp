#include <iostream>
#include <SFML/Graphics.hpp>
#include "ParticleSystem.h"
#include "GameSystem.h"
#include <map>

int main()
{
	sf::Clock clock;
	
	sf::RenderWindow window(sf::VideoMode(1000, 701), "Game");
	GameSystem sys = GameSystem(&window, clock);
	
	while (window.isOpen())
	{
		sf::Event evt;
		while (window.pollEvent(evt))
		{
			if (evt.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		
		window.clear();
		sys.Update(1e-2f);
		sys.Draw();
		window.display();

	}
	return 0;
}