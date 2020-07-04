#ifndef WALLE_HPP
#define WALLE_HPP

#include "SFML/Graphics.hpp"
#include <vector>

extern const int WIDTH;
extern const int HEIGHT;
extern const int BITS;
extern const double PI;

class Tile;

class WallE {

public:
	WallE();

	virtual void			move(std::vector<Tile> map, double speedModifier = 1);

	virtual void 			updateSpriteState();

	virtual void 			setPosition(int x, int y);
	virtual void 			setHitboxRect(int w, int h);
	virtual void 			setDirection(double direction);
	virtual void 			setSpeed(double speed);
	virtual void 			setSpriteState(int spriteState);

	virtual sf::Vector2f 	getPosition() 		const;
	virtual sf::Vector2f 	getHitboxRect() 	const;
	virtual double 			getDirection() 		const;
	virtual double 			getSpeed() 			const;
	virtual int 			getSpriteState() 	const;

	~WallE();

protected:
private:

	/*** ENGINE ***/

	sf::Vector2f _position;
	sf::Vector2f _hitboxRect;
	double _direction; //in degrees
	double _speed;

	/*** VISUAL ***/

	int _spriteState;
};

#endif