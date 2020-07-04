#include "WallE.hpp"
#include "../terrain/tile.hpp"
#include <cmath>

using namespace std;
using namespace sf;

WallE::WallE()
{
	_position = Vector2f(100,100);
	_hitboxRect = Vector2f(35,35);
	_direction = 0;
	_speed = 5;
	_spriteState = 0;
}

void WallE::move(vector<Tile> map, double speedModifier) 
{
	_position.x += _speed * cos(_direction);
	_position.y += _speed * sin(_direction);

	if(_position.x > WIDTH)
	{
		_position.x -= WIDTH;
	}

	if(_position.x < 0)
	{
		_position.x += WIDTH;
	}

	if(_position.y > HEIGHT)
	{
		_position.y -= HEIGHT;
	}

	if(_position.y < 0)
	{
		_position.y += HEIGHT;
	}
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

void WallE::setHitboxRect(int w, int h)
{
	_hitboxRect = Vector2f(w,h);
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

Vector2f WallE::getHitboxRect() const
{
	return _hitboxRect;
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