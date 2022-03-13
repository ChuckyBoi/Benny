#include "Bullet.h"

void Bullet::setup()
{
	//bullets.push_back(Bullet());





}
void  Bullet::update(RenderWindow &window)
{



}
void Bullet::draw(RenderWindow &window)
{
	for (size_t i = 0;i < bullets.size();i++)
	{
		window.draw(bullets[i].shape);
	}

}