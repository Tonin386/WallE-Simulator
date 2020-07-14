#include "../classes/entities/walle.hpp"
#include "../classes/terrain/tile.hpp"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <map>

const int WIDTH = 1920;
const int HEIGHT = 1080;
const int BITS = 32;
const double PI = 3.14159265;
const int FRAMERATE = 120;

sf::Texture IMG_PLAINS[10];
sf::Texture IMG_WALLE[9];
sf::Texture IMG_ROCKS[4];
sf::Texture IMG_WASTE[7];

sf::Font walle_font;

std::map<int, bool> KEYS_PRESSED;

std::vector< std::vector<Tile*> > currentChunk;
std::map<std::pair<int,int>, std::vector< std::vector <Tile*> > > chunks;
sf::Vector2f currentChunkCoords;

sf::Clock TICK_CLOCK;
sf::Clock ANIM_CLOCKS[1];
//0 is for Wall-E animations;

WallE *WALL_E = new WallE();