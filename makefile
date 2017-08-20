all: clean dict

pre:
	-mkdir bin
	-mkdir obj

dict: timer.o dict.o
	g++ obj/dict.o obj/timer.o -o bin/dict
dict.o:
	g++ -Wall -Wextra -std=c++14 -c src/main.cpp -o obj/dict.o

timer.o:
	g++ -Wall -Wextra -std=c++14 -c src/timer.cpp -o obj/timer.o

clean:
	-rm -rf obj/*
	-rm -rf bin/*
