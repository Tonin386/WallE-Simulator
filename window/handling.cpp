#include "../include/constants.hpp"

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
		code = 100;
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
			sprites[(j * WIDTH / 24) + i].setTexture(img_plains[rand()%10]);
			sprites[(j * WIDTH / 24) + i].setPosition(Vector2f(i * 24, j * 24));
			window->draw(sprites[(j * WIDTH / 24) + i]);
		}
	}

	while(window->isOpen())
	{
		Event e;
		while(window->pollEvent(e))
		{
			EventHandling(window, e);
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

		window->display();
	}

	return 0;
}