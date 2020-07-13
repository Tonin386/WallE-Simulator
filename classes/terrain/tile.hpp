#ifndef TILE_HPP
#define TILE_HPP

#include "SFML/Graphics.hpp"

class Tile {

public:
	Tile(int id, int x = 0, int y = 0, bool isObstacle = false);


	virtual int				getId()				const;
	virtual bool			getIsObstacle() 	const;
	virtual bool			getShowBorders()	const;
	virtual sf::Vector2f	getCoords()			const;
	virtual sf::FloatRect	getHitbox()			const;
	virtual int				getSpriteMeta()		const;

	virtual void			setId(int id);
	virtual void			setObstacle(bool o);
	virtual void			setShowBorders(bool b);
	virtual void			setCoords(int x, int y);
	virtual void			setHitbox(sf::FloatRect hitbox);
	virtual void			setSpriteMeta(int meta);
	
	virtual					~Tile();

protected:
private:
	bool _isObstacle;
	bool _showBorders;

	sf::Vector2f _coords;
	sf::FloatRect _hitbox;

	int _id;
	int _spriteMeta;
};

#endif