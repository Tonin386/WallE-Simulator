#include "tile.hpp"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace sf;
using namespace std;

Tile::Tile(int id, int x, int y, bool isObstacle) : _id(id), _coords(Vector2f(x,y)), _isObstacle(isObstacle)
{
	if(_id == 0) _spriteMeta = rand()%10;
	else _spriteMeta = 0;

	_hitbox.left = -1;
	_hitbox.top = -1;
}

int Tile::getId() const
{
	return _id;
}

bool Tile::getIsObstacle() const
{
	return _isObstacle;
}

bool Tile::getShowBorders() const
{
	return _showBorders;
}

Vector2f Tile::getCoords() const
{
	return _coords;
}

FloatRect Tile::getHitbox() const
{
	return _hitbox;
}

int Tile::getSpriteMeta() const
{
	return _spriteMeta;
}

void Tile::setId(int id)
{
	_id = id;
}

void Tile::setObstacle(bool o)
{
	_isObstacle = o;
}

void Tile::setShowBorders(bool b)
{
	_showBorders = b;
}

void Tile::setCoords(int x, int y)
{
	_coords.x = x;
	_coords.y = y;
}

void Tile::setHitbox(FloatRect hitbox)
{
	if(_id == 1)
	{
		hitbox.top += 5;
		hitbox.height -= 10;
	}
	_hitbox = hitbox;
}

void Tile::setSpriteMeta(int meta)
{
	_spriteMeta = meta;
}

Tile::~Tile()
{
	
}