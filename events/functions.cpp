#include "functions.hpp"

void moveEntities()
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
	else if(KEYS_PRESSED[71] && KEYS_PRESSED[72] && KEYS_PRESSED[73] && KEYS_PRESSED[74]) //1111 Left & Right & Up & Down
	{
		direction = -1;
	}

	if(direction != -1)
	{
		WALL_E->setDirection(direction);
		WALL_E->move(currentChunk);
	}
}

