#include <vector>
#include <iostream>
#include <string>
#include <math.h>


void Print(int val) // Function overload: same names, different arguments
{
        std::cout << val << "\n";
}

void Print(float val)
{
        std::cout << val << "\n";
}

struct Vector2f 
{
        Vector2f() // Constructor
        {
           //     std::cout << "Constructor called\n";
                x = 0.0f;
                y = 0.0f;
        }
        Vector2f(float _x, float _y) // Constructor overload
        {
           //     std::cout << "Constructor called\n";
                x = _x;
                this->y = _y; // Possible if we don't want "_"
        }
        ~Vector2f() // Destructor
        {
  //              std::cout << "Destructor called\n";
        }

        void Print()
        {
                std::cout <<
                        "x: " << x << "\n" <<
                        "y: " << y << "\n";
        }
		float Length()
		{
			return sqrtf(x * x + y * y);
		}

		Vector2f GetNorm()
		{
			return Vector2f(x / Length(), y / Length());
		}
		float x, y;
};

Vector2f operator +(Vector2f v0, Vector2f v1) // Operator overloadff
{
        return Vector2f(v0.x + v1.x, v0.y + v1.y);
}

Vector2f operator -(Vector2f v0, Vector2f v1) // Operator overloadff
{
        return Vector2f(v0.x - v1.x, v0.y - v1.y);
}

Vector2f operator *(Vector2f v0, float a) // Operator overloadff
{
        return Vector2f(v0.x * a, v0.y * a);
}

Vector2f operator /(Vector2f v0, float a) // Operator overloadff
{
	return Vector2f(v0.x / a, v0.y / a);
}

