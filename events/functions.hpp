#include "../classes/entities/walle.hpp"
#include "../classes/terrain/tile.hpp"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <map>

extern const int HEIGHT, WIDTH, BITS, FRAMERATE;
extern const double PI;

extern std::map<int, bool> KEYS_PRESSED;

extern sf::Texture IMG_PLAINS[10];
extern sf::Texture IMG_WALLE[9];
extern sf::Texture IMG_ROCKS[4];

extern std::vector< std::vector<Tile*> > currentChunk;
extern std::vector< std::vector< std::vector <Tile*> > > chunks;

extern sf::Clock TICK_CLOCK;
extern sf::Clock ANIM_CLOCKS[1];

extern WallE *WALL_E;

void generateChunk();
bool movePlayer();
void drawMap(sf::RenderWindow *window);
void drawRocks(sf::RenderWindow *window);