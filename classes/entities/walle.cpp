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
	_speed = 3;
	_spriteState = 0;
	_wasteQuantity = 0;
	_maxWasteQuantity = 20;
	_recycling = 0;
	_recyclingState = 0;
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

void WallE::pickUpWaste(vector< vector<Tile*> > map)
{
	for(int i = 0; i < WIDTH/24; i++)
	{
		for(int j = 0; j < HEIGHT/24; j++)
		{
			if(map[i][j]->getId() == 2)
			{
				if(_hitbox.intersects(map[i][j]->getHitbox()))
				{
					if(_wasteQuantity+1<=_maxWasteQuantity) 
					{
						_wasteQuantity++;
						map[i][j]->setId(0);
					}
				}
			}
		}
	}
}

void WallE::updateSpriteState()
{
	_spriteState++;
	_spriteState %= 2;
}

View WallE::getView()
{
	Vector2f viewPosition(_position);
	Vector2f viewSize(WIDTH/4, HEIGHT/4);

	if(_position.x + viewSize.x/2 > WIDTH)
	{
		viewPosition.x = WIDTH - viewSize.x/2;
	}
	else if(_position.x - viewSize.x/2 < 0)
	{
		viewPosition.x = viewSize.x/2;
	}

	if(_position.y + viewSize.y/2 > HEIGHT)
	{
		viewPosition.y = HEIGHT - viewSize.y/2;
	}
	else if(_position.y - viewSize.y/2 < 0)
	{
		viewPosition.y = viewSize.y/2;
	}

	View view;
	view.setCenter(viewPosition);
	view.setSize(viewSize);

	return view;
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

void WallE::setWasteQuantity(double q)
{
	_wasteQuantity = q;
}

void WallE::setMaxWasteQuantity(double mq)
{
	_maxWasteQuantity = mq;
}

void WallE::setRecycling(bool recycling)
{
	_recycling = recycling;
}

void WallE::setRecyclingState(int recyclingState)
{
	_recyclingState = recyclingState;
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

double WallE::getWasteQuantity() const
{
	return _wasteQuantity;
}

double WallE::getMaxWasteQuantity() const
{
	return _maxWasteQuantity;
}

bool WallE::isRecycling() const
{
	return _recycling;
}

int WallE::getRecyclingState() const
{
	return _recyclingState;
}

int WallE::getSpriteState() const
{
	return _spriteState;
}

WallE::~WallE()
{
	
}