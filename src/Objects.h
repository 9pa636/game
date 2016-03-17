#include "Vector2f.h"
#include <math.h>

class Boy
{
public:
	Boy()
	{
		pos.x = 600;
		pos.y = 690;
		prevPos.x = 600;
		prevPos.y = 690;
	}
	void Update()
	{
		Integrate(1e-2f);
		float floorLevel = 690.0f;
		float wall = 1000.0f;
		if (pos.y > floorLevel)
		{
			pos.y = floorLevel;
	//		prevPos.x = pos.x;
		}
		if (pos.y < 0)
		{
			pos.y = 0;
			prevPos.x = pos.x;
		}
		if (pos.x < 0)
		{
			pos.x = 0;
			prevPos.y = pos.y;
		}
		if (pos.x > wall-100)
		{
			pos.x = wall-100;
			prevPos.y = pos.y;
		}
	}
	void Right()
	{
		pos = pos + Vector2f(step, 0.0f);
	}
	void Left()
	{
		pos = pos + Vector2f(-step, 0.0f);
	}
	void Up()
	{
	//	pos = pos + Vector2f(0.0f, -step);
	}
	void Integrate(float dt)
	{
		Vector2f currPos = pos;
		pos = pos + (pos - prevPos) + acceleration * dt * dt;
		prevPos = currPos;
	}

	Vector2f pos;
	Vector2f prevPos;
	Vector2f acceleration = Vector2f(0.0f, 2.0f);
	float step = 0.0005f;
};