#include "Benny.h"


void Benny::Setup()
{
    Player.setSize(Vector2f(40, 40));
	Player.setTexture(&PlayerT);
	Player.setPosition(Vector2f(500, 500));
	
	
	

	
	Enemy.setSize(Vector2f(70, 80));
	Enemy.setTexture(&EnemyT);
	Enemy.setPosition(Vector2f(1500, 700));

	circle.setFillColor(Color::Red);
	circle.setRadius(200.f);
	circle.setPosition(Vector2f(500, 500));




	

	
	
	
	

	srand(time(NULL));




}


void Benny::update( RenderWindow &window)
{

	//window.setFramerateLimit(60);

	playerCenter = Vector2f(Player.getPosition().x + Player.getSize().x/2, Player.getPosition().y + Player.getSize().y/2);
	mousePosWindow = Vector2f(Mouse::getPosition(window));
	aimDir = mousePosWindow - playerCenter;

	aimDirNorm.x = aimDir.x / (sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));
	aimDirNorm.y = aimDir.y / (sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));

	//cout << aimDirNorm.x << " " << aimDirNorm.y << endl;

	
	//cout << aimDirNorm.x << " " << aimDirNorm.y << endl;

	if (Keyboard::isKeyPressed(Keyboard::LShift))
	{
		sebesseg = 20;
	}
	if (!Keyboard::isKeyPressed(Keyboard::LShift))
	{
		sebesseg = 10;
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		Player.move(-sebesseg, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		Player.move(sebesseg, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		Player.move(0, -sebesseg);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		Player.move(0, sebesseg);
	}


	


	if (Player.getPosition().x > Width- Player.getSize().x)
	{
		Player.setPosition(Width - Player.getSize().x, Player.getPosition().y);
	}
	if (Player.getPosition().x < 0)
	{
		Player.setPosition(0, Player.getPosition().y);
	}
	if (Player.getPosition().y < 0)
	{
		Player.setPosition(Player.getPosition().x, 0);
	}
	if (Player.getPosition().y > Height - Player.getSize().y)
	{
		Player.setPosition(Player.getPosition().x, Height - Player.getSize().y);
	}


	circle.setPosition(Player.getPosition().x - circle.getRadius(), Player.getPosition().y - circle.getRadius());

	if(timer < level)
	{
		timer++;
	}

	if ( timer >= level)
	{

		
		Vector2f RandomPos = Vector2f((rand() % int(Width)), rand() % int(Height));
		Enemy.setPosition(RandomPos);
		//enemy.setPosition(Vector2f(rand() % window.getSize().x, rand() % window.getSize().y));

		

		if(Enemy.getGlobalBounds().intersects(circle.getGlobalBounds()))
		{
			Enemy.setPosition(RandomPos.x-1000,RandomPos.y-600 );
		}

		
		enemies.push_back(RectangleShape(Enemy));
		NumberOfEnemies++;

	

		
		/*if (NumberOfEnemies % 10 == 0)
			{
			if (level>=50)
			{
					level = level / 2;
			}
				if(level< 25 && level>1)
				{
					level = level - 1;
				}
		}
		*/
		level = 10;
		lbllevel.setString("Difficulty " + to_string(NumberOfEnemies));

		timer = 0;

	}
	
		for (size_t i = 0; i < enemies.size(); i++)
		{
			

			if (Player.getGlobalBounds().intersects(enemies[i].getGlobalBounds()))
			{
				////////////////////////////////////////////////////////////////////////////////////////////////////
				music.stop();
				end(window);
			break;

				////////////////////////////////////////////////////////////////////////////////////////////////////
			}


				if (enemies[i].getPosition().x > Player.getPosition().x)
				{
					enemies[i].setPosition(enemies[i].getPosition().x - 2, enemies[i].getPosition().y);
				}

				if (enemies[i].getPosition().x < Player.getPosition().x)
				{
					enemies[i].setPosition(enemies[i].getPosition().x + 2, enemies[i].getPosition().y);
				}

				if (enemies[i].getPosition().y < Player.getPosition().y)
				{
						enemies[i].setPosition(enemies[i].getPosition().x, enemies[i].getPosition().y + 2);
				}
				if (enemies[i].getPosition().y > Player.getPosition().y)
				{
						enemies[i].setPosition(enemies[i].getPosition().x, enemies[i].getPosition().y - 2);
				}

				
		if (enemies[i].getPosition().y >Height)
		{
		enemies.erase(enemies.begin() + i);
		}
		if (enemies[i].getPosition().y < 0) 
		{
		//	enemies.erase(enemies.begin() + i);
		//	NumberOfEnemies--;
	    }

	    }



		for (size_t i = 0;i < b1.bullets.size();i++)
		{
			b1.bullets[i].shape.move(b1.bullets[i].currVelocity);


			if (b1.bullets[i].shape.getPosition().x < 0 || b1.bullets[i].shape.getPosition().x > window.getSize().x ||
				b1.bullets[i].shape.getPosition().y<0 || b1.bullets[i].shape.getPosition().y>window.getSize().y)
			{
				b1.bullets.erase(b1.bullets.begin() + i);

			}
			else
			{
				for (size_t k = 0; k < enemies.size();k++)
				{
					if (b1.bullets[i].shape.getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
					{
						b1.bullets.erase(b1.bullets.begin() + i);
						enemies.erase(enemies.begin() + k);
						break;
					}

				}
			}

			//cout << b1.bullets.size() << "\n";
		}

		

}

void Benny::draw(RenderWindow &window)
{
	
	for (size_t i = 0; i < enemies.size();i++)
	{
		window.draw(enemies[i]);

	}
	    window.draw(Player);
	    window.draw(lbllevel);
		b1.draw(window);
		

}
void Benny::handleEvents(sf::Event& event)
{

	if (ShootTimer <= 10)
	{
		ShootTimer++;
	}
	if (Mouse::isButtonPressed(Mouse::Left) && ShootTimer >= 10)
	{
		b1.shape.setPosition(playerCenter);
		b1.currVelocity = aimDirNorm * b1.maxSpeed;
		b1.bullets.push_back(Bullet(b1));
		ShootTimer = 0;
	}
}
void Benny::end(RenderWindow &window)
{

	
    elapsed2 = clock.getElapsedTime();
	elapsed2 = elapsed2 + seconds(2);

	Player.setTexture(&BrokenT);
	Player.setSize(Vector2f(200, 200));
	
	//////////////////////
	
	window.clear();
	window.draw(Player);
	window.draw(lbllevel);
	window.display();
	
	sound.play();
	
	
	while (elapsed1 <= elapsed2) {
		elapsed1 = clock.getElapsedTime();

		if(Keyboard::isKeyPressed(Keyboard::R))
		{
			
		}
		
	}


	window.close();
		//setnumber(33);

}
/*
void Benny::setnumber(int a)
{

    num = a;
 

}
int Benny::getnumber()
{
	return num;


}*/
