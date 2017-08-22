all: clean dict

pre:
	-mkdir bin
	-mkdir obj

dict: dictionary.o timer.o dict.o
	g++ obj/main.o obj/timer.o obj/dictionary.o -o bin/dict
dict.o:
	g++ -Wall -Wextra -std=c++17 -c src/main.cpp -o obj/main.o

timer.o:
	g++ -Wall -Wextra -std=c++17 -c src/timer.cpp -o obj/timer.o

dictionary.o:
	g++ -Wall -Wextra -std=c++17 -c src/dictionary.cpp -o obj/dictionary.o

clean:
	-rm -rf bin/*
