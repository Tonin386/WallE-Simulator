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

	virtual int				move(std::vector< std::vector<Tile*> > map, double speedModifier = 1);
	virtual void			pickUpWaste(std::vector< std::vector<Tile*> > map);

	virtual void			updateSpriteState();

	virtual void			setPosition(int x, int y);
	virtual void			setHitbox(sf::FloatRect hitbox);
	virtual void			setDirection(double direction);
	virtual void			setSpeed(double speed);
	virtual void			setWasteQuantity(double q);
	virtual void			setMaxWasteQuantity(double mq);
	virtual void			setRecycling(bool recycling);
	virtual void			setRecyclingState(int recyclingState);
	virtual void			setSpriteState(int spriteState);

	virtual sf::Vector2f	getPosition()			const;
	virtual sf::FloatRect	getHitbox()				const;
	virtual double			getDirection()			const;
	virtual double			getSpeed()				const;
	virtual double			getWasteQuantity()		const;
	virtual double			getMaxWasteQuantity() 	const;
	virtual bool			isRecycling()			const;
	virtual int				getRecyclingState()		const;
	virtual int				getSpriteState()		const;

	virtual					~WallE();

protected:
private:

	/*** ENGINE ***/

	sf::Vector2f _position;
	sf::FloatRect _hitbox;
	double _direction; //in degrees
	double _speed;

	/*** GAME ***/

	double _wasteQuantity;
	double _maxWasteQuantity;
	bool _recycling;
	int _recyclingState;

	/*** VISUAL ***/

	int _spriteState;
};

#endif