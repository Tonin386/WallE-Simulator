g++ -c include/constants.cpp
g++ -c events/functions.hpp events/functions.cpp
g++ -c window/handling.cpp
g++ -c classes/entities/walle.hpp classes/entities/walle.cpp
g++ -c classes/terrain/tile.hpp classes/terrain/tile.cpp
g++ -c main.cpp
g++ tile.o walle.o functions.o constants.o main.o -o walle-simulator -lsfml-graphics -lsfml-window -lsfml-system