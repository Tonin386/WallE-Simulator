g++ -c include/constants.hpp
g++ -c window/handling.cpp
g++ -c classes/entities/walle.hpp
g++ -c classes/entities/walle.cpp
g++ -c classes/terrain/tile.hpp
g++ -c classes/terrain/tile.cpp
g++ -c main.cpp
g++ main.o -o walle-simulator -lsfml-graphics -lsfml-window -lsfml-system