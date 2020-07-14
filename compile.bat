g++ -c include/constants.cpp -std=c++11
g++ -c events/functions.hpp events/functions.cpp -std=c++11
g++ -c window/handling.cpp -std=c++11
g++ -c classes/entities/walle.hpp classes/entities/walle.cpp -std=c++11
g++ -c classes/terrain/tile.hpp classes/terrain/tile.cpp -std=c++11
g++ -c main.cpp -std=c++11
g++ tile.o walle.o functions.o constants.o main.o -o walle-simulator -lsfml-graphics -lsfml-window -lsfml-system -std=c++11