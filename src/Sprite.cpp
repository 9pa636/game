#include "Vector2f.h"
#include <SFML/Graphics.hpp>
#include "Sprite.h"

std::map<std::string, sf::Texture *> Sprite::textures;

Sprite::Sprite(std::string filename)
{
	if (Sprite::textures.find(filename) == textures.end())
	{
		Sprite::textures[filename] = new sf::Texture;
		Sprite::textures[filename]->loadFromFile(filename);
	}
	this->tex = textures[filename];

	//	this->tex = new sf::Texture;
	//	this->tex->loadFromFile(filename);
};

void Sprite::DrawScreenspace(
	sf::RenderWindow *wnd,
	Vector2f pos,
	float ang,
	Vector2f size,
	string orientation
	)
{
	sf::Vertex vertices[4];
	Vector2f vertexPos;
	tex->setRepeated(true);

	Vector2f xVector = Vector2f(cosf(ang), sinf(ang));
	Vector2f yVector = xVector.GetPerpendicular();

	vertexPos = pos + xVector*size.x + yVector * size.y;
	vertices[0].position = sf::Vector2f(vertexPos.x, vertexPos.y);

	vertexPos = pos + xVector*size.x - yVector * size.y;
	vertices[1].position = sf::Vector2f(vertexPos.x, vertexPos.y);

	vertexPos = pos - xVector*size.x - yVector * size.y;
	vertices[2].position = sf::Vector2f(vertexPos.x, vertexPos.y);

	vertexPos = pos - xVector*size.x + yVector * size.y;
	vertices[3].position = sf::Vector2f(vertexPos.x, vertexPos.y);
	
	if (orientation == "right")
	{
		vertices[0].texCoords = sf::Vector2f(tex->getSize().x, tex->getSize().y);
		vertices[1].texCoords = sf::Vector2f(tex->getSize().x, 0.0f);
		vertices[2].texCoords = sf::Vector2f(0.0f, 0.0f);
		vertices[3].texCoords = sf::Vector2f(0.0f, tex->getSize().y);
	}
	else
	{
		vertices[3].texCoords = sf::Vector2f(tex->getSize().x, tex->getSize().y); 
		vertices[2].texCoords = sf::Vector2f(tex->getSize().x, 0.0f);
		vertices[1].texCoords = sf::Vector2f(0.0f, 0.0f);
		vertices[0].texCoords = sf::Vector2f(0.0f, tex->getSize().y);
	}
	
	wnd->draw(vertices, 4, sf::Quads, tex);
}

void Sprite::DrawWorldspace(
	sf::RenderWindow *wnd,
	Vector2f pos,
	float ang,
	Vector2f size,
	Camera cam,
	string orientation
	)
{
	float pi = 3.14;
	Vector2f xVector = Vector2f(cam.ang);
	Vector2f yVector = Vector2f(cam.ang + pi / 2.0);

	Vector2f delta = pos - cam.pos;
	Vector2f localPos = Vector2f(xVector*delta, yVector*delta);

	Vector2f screenPos;
	float fovx = cam.fieldOfView;
	float fovy = fovx * wnd->getSize().y / wnd->getSize().x;
	screenPos.x = (localPos.x / fovx  + 0.5f) * float(wnd->getSize().x);
	screenPos.y = (localPos.y / fovy + 0.5f) * float(wnd->getSize().y);

	float screenAng = ang - cam.ang;
	Vector2f screenSize = size * (wnd->getSize().x / fovx);
	this->DrawScreenspace(wnd, screenPos, screenAng, screenSize, orientation);
}