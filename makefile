all: clean dict

pre:
	-mkdir bin
	-mkdir obj

dict: dictionary.o timer.o dict.o
	g++ obj/dict.o obj/timer.o obj/dictionary.o -o bin/dict
dict.o:
	g++ -Wall -Wextra -std=c++14 -c src/main.cpp -o obj/dict.o

timer.o:
	g++ -Wall -Wextra -std=c++14 -c src/timer.cpp -o obj/timer.o

dictionary.o:
	g++ -Wall -Wextra -std=c++14 -c src/dictionary.cpp -o obj/dictionary.o

clean:
	-rm -rf obj/*
	-rm -rf bin/*
