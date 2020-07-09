#include "window/handling.cpp"
#include <iostream>

using namespace std;
using namespace sf;

extern const int HEIGHT, WIDTH, BITS, FRAMERATE;
extern Texture IMG_PLAINS[10];
extern Texture IMG_WALLE[9];
extern Texture IMG_ROCKS[4];

extern map<int, bool> KEYS_PRESSED;

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	int height = 33;
	int width = 1;
	for(int i = 0; i < 10; i++) 
	{
		IMG_PLAINS[i].loadFromFile("img/sprites/terrain/advance_wars.png", IntRect(width, height, 24, 24));
		if(i != 4) width += 25;
		else
		{
			width = 1;
			height += 25;
		}

		cout << "Sprite #" << i << " loaded" << endl;
	}

	for(int i = 0; i < 200; i++)
	{
		KEYS_PRESSED[i] = false;
	}

	IMG_WALLE[0].loadFromFile("img/sprites/characters/walle_eve_sprites.png", IntRect(5, 6, 34, 34));
	IMG_WALLE[1].loadFromFile("img/sprites/characters/walle_eve_sprites.png", IntRect(40, 6, 34, 34));
	IMG_WALLE[2].loadFromFile("img/sprites/characters/walle_eve_sprites.png", IntRect(76, 6, 34, 34));
	IMG_WALLE[3].loadFromFile("img/sprites/characters/walle_eve_sprites.png", IntRect(111, 6, 34, 34));
	IMG_WALLE[4].loadFromFile("img/sprites/characters/walle_eve_sprites.png", IntRect(147, 7, 35, 33));
	IMG_WALLE[5].loadFromFile("img/sprites/characters/walle_eve_sprites.png", IntRect(183, 7, 35, 33));
	IMG_WALLE[6].loadFromFile("img/sprites/characters/walle_eve_sprites.png", IntRect(5, 42, 32, 39));
	IMG_WALLE[7].loadFromFile("img/sprites/characters/walle_eve_sprites.png", IntRect(37, 42, 34, 39));
	IMG_WALLE[8].loadFromFile("img/sprites/characters/walle_eve_sprites.png", IntRect(72, 42, 27, 39));

	IMG_ROCKS[0].loadFromFile("img/sprites/terrain/advance_wars.png", IntRect(178, 33, 24, 48));
	IMG_ROCKS[1].loadFromFile("img/sprites/terrain/advance_wars.png", IntRect(203, 33, 24, 48));
	IMG_ROCKS[2].loadFromFile("img/sprites/terrain/advance_wars.png", IntRect(228, 33, 24, 48));
	IMG_ROCKS[3].loadFromFile("img/sprites/terrain/advance_wars.png", IntRect(253, 33, 24, 48));

	RenderWindow window(VideoMode(WIDTH, HEIGHT, BITS), "WallE-Simulator", Style::Fullscreen);
	WindowHandling(&window);

	return 0;
}