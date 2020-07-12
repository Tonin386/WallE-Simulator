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
extern std::map<std::pair<int,int>, std::vector< std::vector <Tile*> > > chunks;
extern sf::Vector2f currentChunkCoords;

extern sf::Clock TICK_CLOCK;
extern sf::Clock ANIM_CLOCKS[1];

extern WallE *WALL_E;

std::vector< std::vector<Tile*> > generateChunk();
int movePlayer(); //-1 Error | 0 In same chunk | 1 Chunk top | 2 Chunk right | 3 Chunk bottom | 4 Chunk left
void drawMap(sf::RenderWindow *window);
void drawRocks(sf::RenderWindow *window);