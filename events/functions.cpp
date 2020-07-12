#include "functions.hpp"
#include <iostream>

using namespace std;
using namespace sf;

vector< vector<Tile*> > generateChunk()
{
	vector< vector<Tile*> > chunk;
	cout << WIDTH/24 << endl << HEIGHT/24 << endl;
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

	return chunk;
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