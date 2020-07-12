#include "WallE.hpp"
#include "../terrain/tile.hpp"
#include <cmath>
#include <iostream>

using namespace std;
using namespace sf;

WallE::WallE()
{
	_position = Vector2f(100,100);
	_direction = 0;
	_speed = 5;
	_spriteState = 0;
}

int WallE::move(vector< vector<Tile*> > map, double speedModifier) 
{
	Vector2f oldPos = _position;
	Vector2f vectorMove = Vector2f(_speed * cos(_direction), _speed * sin(_direction));

	bool blocked = false;

	FloatRect tempHitbox = _hitbox;
	tempHitbox.left += vectorMove.x;
	tempHitbox.top += vectorMove.y;

	for(int i = 0; i < WIDTH/24; i++)
	{
		for(int j = 0; j < HEIGHT/24; j++)
		{
			if(map[i][j]->getIsObstacle())
			{
				if(tempHitbox.intersects(map[i][j]->getHitbox()))
				{
					return -1;
				}
			}
		}
	}

	_position.x += vectorMove.x;

	if(_position.x > WIDTH)
	{
		return 2;
	}
	else if (_position.x < 0)
	{
		return 4;
	}

	_position.y += vectorMove.y;

	if(_position.y > HEIGHT)
	{
		return 3;
	}
	else if(_position.y < 0)
	{
		return 1;
	}


	return 0;
}

void WallE::updateSpriteState()
{
	_spriteState++;
	_spriteState %= 2;
}

void WallE::setPosition(int x, int y)
{
	_position = Vector2f(x,y);
}

void WallE::setHitbox(FloatRect hitbox)
{
	hitbox.top += 20;
	hitbox.height -= 30;
	_hitbox = hitbox;
}

void WallE::setDirection(double direction)
{
	_direction = direction;
}

void WallE::setSpeed(double speed)
{
	_speed = speed;
}

void WallE::setSpriteState(int spriteState)
{
	_spriteState = spriteState;
}

Vector2f WallE::getPosition() const
{
	return _position;
}

FloatRect WallE::getHitbox() const
{
	return _hitbox;
}

double WallE::getDirection() const
{
	return _direction;
}

double WallE::getSpeed() const
{
	return _speed;
}

int WallE::getSpriteState() const
{
	return _spriteState;
}

WallE::~WallE()
{
	
}