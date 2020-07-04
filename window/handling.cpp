#include "../events/functions.hpp"

#include <iostream>

using namespace std;
using namespace sf;

int EventHandling(RenderWindow *window, Event e)
{
	int code;
	switch(e.type)
	{
		case Event::Closed: //Window related events from 0 to 99
		window->close();
		code = 0;
		break;

		case Event::KeyPressed: //KeyPressed events from 100 to 999
		KEYS_PRESSED[e.key.code] = true;
		code = 100 + e.key.code;

		/**
		71 -> Left 
		72 -> Right
		73 -> Up
		74 -> Down

		**/

		break;

		case Event::KeyReleased: //1000 to 1899
		KEYS_PRESSED[e.key.code] = false;
		code = 1000 + e.key.code;
		break;

		default: //if event isn't handled
		code = -1;
		break;
	}

	return code;
}

int WindowHandling(RenderWindow *window)
{
	Sprite sprites[(WIDTH * HEIGHT) / (24 * 24)];
	for(int i = 0; i < WIDTH / 24; i++)
	{
		for(int j = 0; j < HEIGHT / 24; j++)
		{
			sprites[(j * WIDTH / 24) + i].setTexture(IMG_PLAINS[rand()%10]);
			sprites[(j * WIDTH / 24) + i].setPosition(Vector2f(i * 24, j * 24));
		}
	}

	Sprite spr_walle;
	spr_walle.setPosition(WALL_E->getPosition());
	spr_walle.setTexture(IMG_WALLE[0]);
	spr_walle.setOrigin(spr_walle.getTextureRect().width/2, spr_walle.getTextureRect().height/2);

	int code = 0;
	bool moving = false;

	while(window->isOpen())
	{
		if(KEYS_PRESSED[71] || KEYS_PRESSED[72] || KEYS_PRESSED[73] || KEYS_PRESSED[74]) moving = true;
		else moving = false;

		Event e;
		while(window->pollEvent(e))
		{
			code = EventHandling(window, e);
			if(code == 1036) window->close();
		}

		if(TICK_CLOCK.getElapsedTime().asMilliseconds() > 10)
		{
			TICK_CLOCK.restart();
			moveEntities();

			Vector2f walleScale(1.75,1.75);
			spr_walle.setPosition(WALL_E->getPosition());
			if(PI / 2 < WALL_E->getDirection() && WALL_E->getDirection() <= 3*PI / 2) walleScale = Vector2f(-1.75,1.75);
			spr_walle.setScale(walleScale);
		}

		if(ANIM_CLOCKS[0].getElapsedTime().asMilliseconds() > 250 && moving)
		{
			ANIM_CLOCKS[0].restart();
			WALL_E->updateSpriteState();
			switch(WALL_E->getSpriteState())
			{
				default:
				case 0:
				spr_walle.setTexture(IMG_WALLE[4]);
				break;

				case 1:
				spr_walle.setTexture(IMG_WALLE[5]);
				break;
			}
		}

		if(!moving)
		{
			spr_walle.setTexture(IMG_WALLE[0]);
		}

		window->clear();

		/** DEBUG **/

		for(int i = 0; i < WIDTH / 24; i++)
		{
			for(int j = 0; j < HEIGHT / 24; j++)
			{
				window->draw(sprites[(i * HEIGHT / 24) + j]);
			}
		}

	 	/** END DEBUG **/

		window->draw(spr_walle);
		window->display();
	}

	return 0;
}