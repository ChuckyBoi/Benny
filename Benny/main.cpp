#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Benny.h"



#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


using namespace sf;
using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(1920,1080), "TESTING");

	Benny benny;
	benny.Setup();
	window.setFramerateLimit(60);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		benny.handleEvents(event);

		window.clear();
		benny.update( window);
		benny.draw(window);
		window.display();
	  //	if (benny.getnumber())
		//{
		//	window.close();
		//}
	}

	return 0;
}