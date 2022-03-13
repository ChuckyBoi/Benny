#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include <iostream>

#include <stdio.h>      
#include <stdlib.h>   
#include <time.h>


using namespace sf;
using namespace std;

constexpr auto Width = 1920;
constexpr auto Height = 1080;


class Benny

{

private:

	int num = 0;

	int sebesseg = 0;
	int timer = 0;
	int level = 100;
	int ShootTimer = 0;

	bool hit = false;
	
	
	Vector2f playerCenter;
	Vector2f mousePosWindow;

	Vector2f aimDir;
	Vector2f aimDirNorm;

	

	int NumberOfEnemies = 0;

	//heart
	Texture PlayerT;
	//broken heart
	Texture BrokenT;
	//
	Texture EnemyT;

	
	//me
	RectangleShape Player;

//to not spawn right infront of you
CircleShape circle;

//the kelemens
Bullet b1;

	RectangleShape Enemy;
	vector<RectangleShape> enemies;


//scatman
	Music music;
//heart shatter
	SoundBuffer buffer;
	Sound sound;
//time
	Clock clock;
	Time elapsed1;
	Time elapsed2;

	
	Font arial;
	Text lbllevel = { "Difficulty " + to_string(NumberOfEnemies),arial,30 };


public:


	Benny()
	{
		
		PlayerT.loadFromFile("../Benny/images/heart.png");
		BrokenT.loadFromFile("../Benny/images/broken.png");
	    EnemyT.loadFromFile("../Benny/images/Tamass.png");
	//	EnemyT.loadFromFile("images/anna.png");
	  //  EnemyT.loadFromFile("images/simo.jpg");

		arial.loadFromFile("../Benny/arial.ttf");

		music.openFromFile("../Benny/Audio/benny.ogg");
	    buffer.loadFromFile("../Benny/Audio/okok.ogg");

		music.setVolume(50);
		music.play();

		sound.setBuffer(buffer);

	}
	void Setup();
	void draw(RenderWindow &window);
	void handleEvents(sf::Event& event);
	void update(RenderWindow &window);
	void end(RenderWindow &window);
	// setnumber(int a);
	//int getnumber();
};