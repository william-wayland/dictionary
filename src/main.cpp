#include <string>
#include "timer.h"
#include "dictionary.h"

int main()
{
	auto dictionary = Dictionary("alice.txt", true);

	auto users_word = std::string();
	while(true) {
		std::cout << "> ";
		std::getline(std::cin, users_word);
		if (users_word == ".")
		{
			break;
		}
		if (dictionary.does_contain(users_word))
		{
			std::cout << "\"" << users_word << "\" is a word." << "\n\n";
		}
		else
		{
			std::cout << "\"" << users_word << "\" is not a word." << "\n\n";
		}
	}
}
