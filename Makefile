.default: all

all: Azul

clean:
	rm -f Azul *.o

Azul: main.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
