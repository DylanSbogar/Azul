.default: all

all: Azul

clean:
	rm -f Azul *.o

Azul: main.o factories.o factory.o gameEngine.o mosaic.o player.o tile.o tileBag.o utils.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
