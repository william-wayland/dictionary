#include <string>
#include "timer.h"
#include "dictionary.h"

int main()
{
	auto dictionary = Dictionary("alice.txt", Punctuation::Remove);
	dictionary.add_file("words.txt", Punctuation::Keep);

	auto users_word = std::string();
	while(true) {
		std::cout << "> ";
		std::getline(std::cin, users_word);
		if (users_word == ".")
		{
			break;
		}
		else if (users_word == "")
		{
			continue;
		}

		if (dictionary.contains(users_word))
		{
			std::cout << " \"" << users_word << "\" is a word." << "\n\n";
		}
		else
		{
			std::cout << " \"" << users_word << "\" is not a word." << "\n\n";
		}
	}
}
