#include <iostream>
#include <SFML/Graphics.hpp>
#include "Objects.h"
//#include "Graphics.h"


int main()
{
	Boy boy;

	sf::RenderWindow window(sf::VideoMode(1000, 700), "game");
	
	sf::Texture Tex;
	Tex.loadFromFile("data/1.jpg");
	sf::Texture roomTex; 
	roomTex.loadFromFile("data/room1.png"); 
//	sf::Texture boyTex; 
//	boyTex.loadFromFile("data/boy.png"); 
	sf::Texture cupboardTex; 
	cupboardTex.loadFromFile("data/cupboard1.png"); 
	sf::Texture bedTex; 
	bedTex.loadFromFile("data/bed1.png"); 
	sf::Texture deskTex; 
	deskTex.loadFromFile("data/desk1.png"); 

	sf::Texture boyTex;
	boyTex.loadFromFile("data/2.png");

	sf::Shader shader;
	if (!shader.loadFromFile("data/Shaders/fragmentShader.frag", sf::Shader::Fragment))
	{
		std::cout << "fail";
	}
	else
	{
		std::cout << "sucsess";
	}
	Vector2f minPoint = Vector2f(-1.0, -1.0);
	Vector2f maxPoint = Vector2f(1.0, 1.0);

	sf::Clock clock;
	
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
		
		Vector2f delta = maxPoint - minPoint;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			minPoint.y += delta.y * 0.05f;
			maxPoint.y += delta.y * 0.05f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			minPoint.x -= delta.x * 0.05f;
			maxPoint.x -= delta.x * 0.05f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			minPoint.y -= delta.y * 0.05f;
			maxPoint.y -= delta.y * 0.05f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
		{
			minPoint.x += delta.x * 0.05f;
			maxPoint.x += delta.x * 0.05f;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
		{
			minPoint.x -= delta.x * 0.005f;
			maxPoint.x += delta.x * 0.005f;
			minPoint.y -= delta.y * 0.005f;
			maxPoint.y += delta.y * 0.005f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			minPoint.x += delta.x * 0.005f;
			maxPoint.x -= delta.x * 0.005f;
			minPoint.y += delta.y * 0.005f;
			maxPoint.y -= delta.y * 0.005f;
		}

		window.clear();
		/*
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
		*/

		sf::Vertex boyVer[4];
		Vector2f pos = boy.pos;
		boyVer[0].position = sf::Vector2f(pos.x, pos.y);
		boyVer[1].position = sf::Vector2f(pos.x, pos.y - 320);
		boyVer[2].position = sf::Vector2f(pos.x + 150, pos.y - 320);
		boyVer[3].position = sf::Vector2f(pos.x + 150, pos.y);
		boyVer[1].texCoords = sf::Vector2f(50, 100);
		boyVer[2].texCoords = sf::Vector2f(800, 100);
		boyVer[3].texCoords = sf::Vector2f(800, 1760);
		boyVer[0].texCoords = sf::Vector2f(50, 1760);

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

		sf::Vertex Ver[4];
		Ver[0].position = sf::Vector2f(0, 0);
		Ver[1].position = sf::Vector2f(1000, 0);
		Ver[2].position = sf::Vector2f(1000, 700);
		Ver[3].position = sf::Vector2f(0, 700);
		Ver[0].texCoords = sf::Vector2f(0, 0);
		Ver[1].texCoords = sf::Vector2f(1000, 0);
		Ver[2].texCoords = sf::Vector2f(1000, 700);
		Ver[3].texCoords = sf::Vector2f(0, 700);
		
		
		
		shader.setParameter("minPoint", sf::Vector2f(minPoint.x, minPoint.y));
		shader.setParameter("maxPoint", sf::Vector2f(maxPoint.x, maxPoint.y));
		shader.setParameter("time", clock.getElapsedTime().asSeconds());
	//	sf::Shader::bind(&shader);
						
		sf::Vertex whatever[4];
	/*	whatever[0].position = sf::Vector2f(800, 320);/door
		whatever[1].position = sf::Vector2f(900, 320);
		whatever[2].position = sf::Vector2f(900, 700);
		whatever[3].position = sf::Vector2f(800, 700);*/
/*		whatever[0].position = sf::Vector2f(300, 300);
		whatever[1].position = sf::Vector2f(600, 300);
		whatever[2].position = sf::Vector2f(600, 500);
		whatever[3].position = sf::Vector2f(300, 500);*/
/*		whatever[0].position = sf::Vector2f(25, 25);
		whatever[1].position = sf::Vector2f(975, 25);
		whatever[2].position = sf::Vector2f(975, 675);
		whatever[3].position = sf::Vector2f(25, 675);*/

		window.draw(Ver, 4, sf::Quads, &Tex);
		window.draw(roomVer, 4, sf::Quads, &roomTex);
//		window.draw(whatever, 4, sf::Quads, &shader);
		window.draw(cupboardVer, 4, sf::Quads, &cupboardTex);
		window.draw(bedVer, 4, sf::Quads, &bedTex);
		window.draw(deskVer, 4, sf::Quads, &deskTex);
		

		window.draw(boyVer, 4, sf::Quads, &boyTex);
		window.display();

	}
	return 0;
}