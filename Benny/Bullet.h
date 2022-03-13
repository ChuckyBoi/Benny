#include "SFML/Graphics.hpp"
#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>


using namespace sf;
using namespace std;

class Bullet
{

public:

	CircleShape shape;

	Vector2f currVelocity;

	float maxSpeed;

	vector<Bullet>bullets;


	


	Bullet(float radius = 5.f)
		: currVelocity(0.f, 0.f), maxSpeed(15.f)
	{
		this->shape.setRadius(radius);
		this->shape.setFillColor(Color::Red);

	}

	void setup();
	void update( RenderWindow &window);
	void draw(RenderWindow &window);


	













};
