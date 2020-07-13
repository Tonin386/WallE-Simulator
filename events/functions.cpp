#include "functions.hpp"
#include <iostream>

using namespace std;
using namespace sf;

vector< vector<Tile*> > generateChunk()
{
	vector< vector<Tile*> > chunk;
	for(int i = 0; i < WIDTH/24; i++)
	{
		vector<Tile*> t;
		chunk.push_back(t);
		for(int j = 0; j < HEIGHT/24; j++)
		{
			Tile *tile;
			int dummy = rand()%100;
			if(dummy == 0) 
			{
				tile = new Tile(1, i, j, true);
			}
			else 
			{
				tile = new Tile(0, i, j, false);
			}

			chunk[i].push_back(tile);
		}
	}

	generateWaste(&chunk);

	return chunk;
}

void generateWaste(vector< vector<Tile*> > *m)
{
	int seedsNumber = 2 + (rand() % 9);
	for (int i = 0; i < seedsNumber; i++)
	{
		Vector2i coords(2 + (rand() % (WIDTH/24 - 2)), 2 + (rand() % (HEIGHT/24 - 2)));
		(*m)[coords.x + 0][coords.y + 0]->setId(2 * (rand() % 2));
		(*m)[coords.x + 0][coords.y - 1]->setId(2 * (rand() % 2));
		(*m)[coords.x + 1][coords.y - 1]->setId(2 * (rand() % 2));
		(*m)[coords.x + 1][coords.y + 0]->setId(2 * (rand() % 2));
		(*m)[coords.x + 1][coords.y + 1]->setId(2 * (rand() % 2));
		(*m)[coords.x + 0][coords.y + 1]->setId(2 * (rand() % 2));
		(*m)[coords.x - 1][coords.y + 1]->setId(2 * (rand() % 2));
		(*m)[coords.x - 1][coords.y + 0]->setId(2 * (rand() % 2));
		(*m)[coords.x - 1][coords.y + 1]->setId(2 * (rand() % 2));
	}
}

int movePlayer()
{
	double speedModifier = 1;
	double direction = 0;

	if(!KEYS_PRESSED[71] && !KEYS_PRESSED[72] && !KEYS_PRESSED[73] && !KEYS_PRESSED[74]) //0000 None
	{
		direction = -1;
	}
	else if(!KEYS_PRESSED[71] && !KEYS_PRESSED[72] && !KEYS_PRESSED[73] && KEYS_PRESSED[74]) //0001 Down
	{
		direction = PI / 2;
	}
	else if(!KEYS_PRESSED[71] && !KEYS_PRESSED[72] && KEYS_PRESSED[73] && !KEYS_PRESSED[74]) //0010 Up
	{
		direction = 3*PI / 2;
	}
	else if(!KEYS_PRESSED[71] && !KEYS_PRESSED[72] && KEYS_PRESSED[73] && KEYS_PRESSED[74]) //0011 Up & Down
	{
		direction = -1;
	}
	else if(!KEYS_PRESSED[71] && KEYS_PRESSED[72] && !KEYS_PRESSED[73] && !KEYS_PRESSED[74]) //0100 Right
	{
		direction = 0;
	}
	else if(!KEYS_PRESSED[71] && KEYS_PRESSED[72] && !KEYS_PRESSED[73] && KEYS_PRESSED[74]) //0101 Right & Down
	{
		direction = PI / 4;
	}
	else if(!KEYS_PRESSED[71] && KEYS_PRESSED[72] && KEYS_PRESSED[73] && !KEYS_PRESSED[74]) //0110 Right & Up
	{
		direction = 7*PI / 4;
	}
	else if(!KEYS_PRESSED[71] && KEYS_PRESSED[72] && KEYS_PRESSED[73] && KEYS_PRESSED[74]) //0111 Right & Up & Down
	{
		direction = -1;
	}
	else if(KEYS_PRESSED[71] && !KEYS_PRESSED[72] && !KEYS_PRESSED[73] && !KEYS_PRESSED[74]) //1000 Left
	{
		direction = PI;
	}
	else if(KEYS_PRESSED[71] && !KEYS_PRESSED[72] && !KEYS_PRESSED[73] && KEYS_PRESSED[74]) //1001 Left & Down
	{
		direction = 3*PI / 4;
	}
	else if(KEYS_PRESSED[71] && !KEYS_PRESSED[72] && KEYS_PRESSED[73] && !KEYS_PRESSED[74]) //1010 Left & Up
	{
		direction = 5*PI / 4;
	}
	else if(KEYS_PRESSED[71] && !KEYS_PRESSED[72] && KEYS_PRESSED[73] && KEYS_PRESSED[74]) //1011 Left & Up & Down
	{
		direction = -1;
	}
	else if(KEYS_PRESSED[71] && KEYS_PRESSED[72] && !KEYS_PRESSED[73] && !KEYS_PRESSED[74]) //1100 Left & Right
	{
		direction = -1;
	}
	else if(KEYS_PRESSED[71] && KEYS_PRESSED[72] && !KEYS_PRESSED[73] && KEYS_PRESSED[74]) //1101 Left & Right & Down
	{
		direction = -1;
	}
	else if(KEYS_PRESSED[71] && KEYS_PRESSED[72] && KEYS_PRESSED[73] && !KEYS_PRESSED[74]) //1110 Left & Right & Up
	{
		direction = -1;
	}
	else if(KEYS_PRESSED[71] && KEYS_PRESSED[72] && KEYS_PRESSED[73] && KEYS_PRESSED[74]) //1111 Left & Right &	 Up & Down
	{
		direction = -1;
	}

	if(direction != -1)
	{
		WALL_E->setDirection(direction);
		return WALL_E->move(currentChunk);
	}

	return -1;
}

void drawMap(RenderWindow *window)
{
	int n_tilesOnWidth(currentChunk.size()), n_tilesOnHeight;

	for(int i = 0; i < n_tilesOnWidth; i++)
	{
		n_tilesOnHeight = currentChunk[i].size();
		for(int j = 0; j < n_tilesOnHeight; j++)
		{
			Tile *t = currentChunk[i][j];
			Sprite sprite;

			sprite.setPosition(Vector2f(i * 24, j * 24));
			sprite.setTexture(IMG_PLAINS[t->getSpriteMeta()]);
			switch(t->getId())
			{	
				default:
				case 0: //plain
				window->draw(sprite);
				break;
			}
		}
	}
}

void drawRocks(RenderWindow * window)
{
	int n_tilesOnWidth(currentChunk.size()), n_tilesOnHeight;

	for(int i = 0; i < n_tilesOnWidth; i++)
	{
		n_tilesOnHeight = currentChunk[i].size();
		for(int j = 0; j < n_tilesOnHeight; j++)
		{
			Tile *t = currentChunk[i][j];
			Sprite sprite;

			sprite.setPosition(i*24, j*24);
			sprite.setTexture(IMG_ROCKS[3]);
			sprite.setOrigin(0,48);
			sprite.move(Vector2f(0,38));
			sprite.setScale(Vector2f(1,0.75));

			t->setHitbox(sprite.getGlobalBounds());
			switch(t->getId())
			{
				case 1:
				window->draw(sprite);
				break;
			}
		}
	}
}

void drawWaste(RenderWindow * window)
{
	int n_tilesOnWidth(currentChunk.size()), n_tilesOnHeight;

	for(int i = 0; i < n_tilesOnWidth; i++)
	{
		n_tilesOnHeight = currentChunk[i].size();
		for(int j = 0; j < n_tilesOnHeight; j++)
		{
			Tile *t = currentChunk[i][j];
			if(t->getId() == 2)
			{
				Sprite sprite;

				sprite.setPosition(i*24, j*24);
				sprite.setTexture(IMG_WASTE[t->getSpriteMeta()]);

				window->draw(sprite);
			}
		}
	}
}

void drawUi(RenderWindow *window)
{
	double walleLoad = WALL_E->getWasteQuantity() / WALL_E->getMaxWasteQuantity();
	cout << WALL_E->getWasteQuantity() << endl;
	Vector2f progressbarBackgroundSize(WIDTH/6, 25);
	Vector2f progressbarBackgroundCoords(5 * WIDTH / 6 - 50, HEIGHT - 50);
	Vector2f progressBarSize((WIDTH/6 - 10) * walleLoad, 15);
	Vector2f progressBarCoords(5 * WIDTH / 6 - 45, HEIGHT - 45);

	VertexArray progressBar(Quads, 8);

	progressBar[0].position = Vector2f(progressbarBackgroundCoords.x, progressbarBackgroundCoords.y);
	progressBar[1].position = Vector2f(progressbarBackgroundCoords.x + progressbarBackgroundSize.x, progressbarBackgroundCoords.y);
	progressBar[2].position = Vector2f(progressbarBackgroundCoords.x + progressbarBackgroundSize.x, progressbarBackgroundCoords.y + progressbarBackgroundSize.y);
	progressBar[3].position = Vector2f(progressbarBackgroundCoords.x, progressbarBackgroundCoords.y + progressbarBackgroundSize.y);

	progressBar[4].position = Vector2f(progressBarCoords.x, progressBarCoords.y);
	progressBar[5].position = Vector2f(progressBarCoords.x + progressBarSize.x, progressBarCoords.y);
	progressBar[6].position = Vector2f(progressBarCoords.x + progressBarSize.x, progressBarCoords.y + progressBarSize.y);
	progressBar[7].position = Vector2f(progressBarCoords.x, progressBarCoords.y + progressBarSize.y);

	progressBar[0].color = Color(0, 0, 0, 150);
	progressBar[1].color = Color(0, 0, 0, 150);
	progressBar[2].color = Color(0, 0, 0, 150);
	progressBar[3].color = Color(0, 0, 0, 150);

	progressBar[4].color = Color(237, 147, 12);
	progressBar[5].color = Color(255, 251, 56);
	progressBar[6].color = Color(255, 251, 56);
	progressBar[7].color = Color(237, 147, 12);

	window->draw(progressBar);
}