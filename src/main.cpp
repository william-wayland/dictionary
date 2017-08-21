#include <string>
#include "timer.h"
#include "dictionary.h"

int main()
{
	auto dictionary = Dictionary("words.txt");
	auto users_word = std::string();


	do {
		std::cout << "> ";
		std::getline(std::cin, users_word);
		if (dictionary.does_contain(users_word))
		{
			std::cout << "That's a word." << "\n";
		}
		else
		{
			std::cout << "That's not a word." << "\n";
		}
	} while (users_word != ".");
}
