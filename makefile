all: pre clean dict

pre: clean
	-mkdir bin
	-mkdir obj
dict: dict.o
	g++ -o bin/dict obj/dict.o
dict.o:
	g++ -Wall -Wextra -std=c++14 -c src/main.cpp -o obj/dict.o

clean:
	-rm -rf obj/*
