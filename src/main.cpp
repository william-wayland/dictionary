#include <string>
#include "timer.h"
#include "dictionary.h"

int main()
{
	//! We could say true to alice because its a book,
	//! and as . " ! ? , all though it.
	auto dictionary = Dictionary("alice.txt", Punctuation::Remove);

	//! We would say false to words because its a clean list
	//! So we might want "can't" and other words like that
	dictionary.add_a_file("words.txt", Punctuation::Keep);

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
