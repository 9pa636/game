#pragma once
#include "Vector2f.h"
#include <SFML/Graphics.hpp>
#include <map>

class Camera
{
public:
	Vector2f pos;
	float ang;
	float fieldOfView;

};


class Sprite
{
public:
	Sprite(){}
	Sprite(std::string filename);
	
	/*void RenderWorldspace(
		sf::RenderWindow *wnd,
		Vector2f pos,
		float ang,
		Vector2f size
		);*/
	void DrawScreenspace(
		sf::RenderWindow *wnd,
		Vector2f screenPospos,
		float screenAng,
		Vector2f screenSize
		);
	void DrawWorldspace(
		sf::RenderWindow *wnd,
		Vector2f pos,
		float ang,
		Vector2f size,
		Camera cam);
private:

	static std::map<std::string, sf::Texture *> textures;
	sf::Texture *tex;

};