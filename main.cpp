#include "window/handling.cpp"
#include <iostream>

using namespace std;
using namespace sf;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	
	int height = 33;
	int width = 1;
	for(int i = 0; i < 10; i++) //25*25 sprites, 1px apart
	{
		img_plains[i].loadFromFile("img/sprites/terrain/advance_wars.png", IntRect(width, height, 24, 24));
		if(i != 4) width += 25;
		else
		{
			width = 1;
			height += 25;
		}

		cout << "Sprite #" << i << " loaded" << endl;
	}

	RenderWindow window(VideoMode(WIDTH, HEIGHT, BITS), "WallE-Simulator"/*, Style::Fullscreen*/);
	WindowHandling(&window);

	return 0;
}