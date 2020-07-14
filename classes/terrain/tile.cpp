#include "tile.hpp"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace sf;
using namespace std;

Tile::Tile(int id, int x, int y, bool isObstacle) : _id(id), _coords(Vector2f(x,y)), _isObstacle(isObstacle)
{
	switch(_id)
	{
		case 0:
		_spriteMeta = rand()%9;
		break;

		case 2:
		_spriteMeta = 0;
		break;

		default:
		_spriteMeta = 0;
		break;
	}

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
	if(_id == 1 && id != 1) _isObstacle = false;

	_id = id;

	switch(_id)
	{
		case 0:
		_spriteMeta = rand()%10;
		break;

		case 2:
		_spriteMeta = 0;
		break;

		default:
		_spriteMeta = 0;
		break;
	}
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