#include <iostream>
#include <SFML/Graphics.hpp>
#include "Objects.h"



int main()
{
	Boy boy;

	sf::RenderWindow window(sf::VideoMode(1000, 700), "game");
	
	sf::Texture roomTex;
	roomTex.loadFromFile("data/room.png");

	sf::Texture boyTex;
	boyTex.loadFromFile("data/boy.png");

	sf::Texture cupboardTex;
	cupboardTex.loadFromFile("data/cupboard.png");

	sf::Texture bedTex;
	bedTex.loadFromFile("data/bed.png");

	sf::Texture deskTex;
	deskTex.loadFromFile("data/desk.png");

/*	sf::Shader shader;
	if (!shader.loadFromFile("data/Shaders/fragmentShader.frag", sf::Shader::Fragment))
	{
		std::cout << "fail";
	}
	else
	{
		std::cout << "sucsess";
	}
	Vector2f minPoint = Vector2f(-0.5, -0.5);
	Vector2f maxPoint = Vector2f(1.0, 1.0);

	sf::Clock clock;*/
	
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
		boy.Update();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			boy.Up();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			boy.Left();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			boy.Right();
		
		window.clear();

		sf::Vertex boyVer[4];
		Vector2f pos = boy.pos;

		boyVer[0].position = sf::Vector2f(pos.x, pos.y);
		boyVer[1].position = sf::Vector2f(pos.x, pos.y - 200);
		boyVer[2].position = sf::Vector2f(pos.x + 100, pos.y - 200);
		boyVer[3].position = sf::Vector2f(pos.x + 100, pos.y);

		boyVer[0].texCoords = sf::Vector2f(700, 1190);
		boyVer[1].texCoords = sf::Vector2f(700, 880);
		boyVer[2].texCoords = sf::Vector2f(840, 880);
		boyVer[3].texCoords = sf::Vector2f(840, 1190);
		
		sf::Vertex roomVer[4];

		roomVer[0].position = sf::Vector2f(0, 0);
		roomVer[1].position = sf::Vector2f(1000, 0);
		roomVer[2].position = sf::Vector2f(1000, 700);
		roomVer[3].position = sf::Vector2f(0, 700);

		roomVer[0].texCoords = sf::Vector2f(0, 290);
		roomVer[1].texCoords = sf::Vector2f(2000, 290);
		roomVer[2].texCoords = sf::Vector2f(2000, 1464);
		roomVer[3].texCoords = sf::Vector2f(0, 1464);

		sf::Vertex cupboardVer[4];

		cupboardVer[0].position = sf::Vector2f(50, 300);
		cupboardVer[1].position = sf::Vector2f(250, 300);
		cupboardVer[2].position = sf::Vector2f(250, 675);
		cupboardVer[3].position = sf::Vector2f(50, 675);

		cupboardVer[0].texCoords = sf::Vector2f(100, 730);
		cupboardVer[1].texCoords = sf::Vector2f(520, 730);
		cupboardVer[2].texCoords = sf::Vector2f(520, 1410);
		cupboardVer[3].texCoords = sf::Vector2f(100, 1410);
		
		sf::Vertex bedVer[4];

		bedVer[0].position = sf::Vector2f(275, 500);
		bedVer[1].position = sf::Vector2f(550, 500);
		bedVer[2].position = sf::Vector2f(550, 680);
		bedVer[3].position = sf::Vector2f(275, 680);

		bedVer[0].texCoords = sf::Vector2f(545, 1095);
		bedVer[1].texCoords = sf::Vector2f(1092, 1095);
		bedVer[2].texCoords = sf::Vector2f(1092, 1400);
		bedVer[3].texCoords = sf::Vector2f(545, 1400);

		sf::Vertex deskVer[4];

		deskVer[0].position = sf::Vector2f(580, 520);
		deskVer[1].position = sf::Vector2f(750, 520);
		deskVer[2].position = sf::Vector2f(750, 672);
		deskVer[3].position = sf::Vector2f(580, 672);

		deskVer[0].texCoords = sf::Vector2f(1130, 1112);
		deskVer[1].texCoords = sf::Vector2f(1486, 1112);
		deskVer[2].texCoords = sf::Vector2f(1486, 1413);
		deskVer[3].texCoords = sf::Vector2f(1130, 1413);

		window.draw(roomVer, 4, sf::Quads, &roomTex);
		window.draw(cupboardVer, 4, sf::Quads, &cupboardTex);
		window.draw(bedVer, 4, sf::Quads, &bedTex);
		window.draw(deskVer, 4, sf::Quads, &deskTex);
		window.draw(boyVer, 4, sf::Quads, &boyTex);
		
		
	/*	shader.setParameter("minPoint", sf::Vector2f(minPoint.x, minPoint.y));
		shader.setParameter("maxPoint", sf::Vector2f(maxPoint.x, maxPoint.y));
		shader.setParameter("time", clock.getElapsedTime().asSeconds());
		sf::Shader::bind(&shader);
			*/			


		window.display();

	}
	return 0;
}