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
	Sprite spr_walle;
	spr_walle.setPosition(WALL_E->getPosition());
	spr_walle.setTexture(IMG_WALLE[0]);
	spr_walle.setOrigin(spr_walle.getTextureRect().width/2, spr_walle.getTextureRect().height/2);

	int code = 0;
	bool moving = false;

	generateChunk();

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
			const bool moved = movePlayer();


			Vector2f walleScale(1.25,1.25);
			spr_walle.setPosition(WALL_E->getPosition());
			if(PI / 2 < WALL_E->getDirection() && WALL_E->getDirection() <= 3*PI / 2) walleScale = Vector2f(-1.25,1.25);
			spr_walle.setScale(walleScale);
			WALL_E->setHitbox(spr_walle.getGlobalBounds());
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
		drawMap(window);
		drawRocks(window);
		window->draw(spr_walle);
		window->display();
	}

	return 0;
}