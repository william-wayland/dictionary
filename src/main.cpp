#include <string>
#include "timer.h"
#include "dictionary.h"
#include "cxxopts.hpp"

void load_dictionary(const cxxopts::Options& options, Dictionary& dictionary);
void load_arguments(cxxopts::Options& options, int argc, char** argv);

int main(int argc, char** argv)
{
	cxxopts::Options options("Spell Checker", "A C++ Implementation.");
	load_arguments(options, argc, argv);

	if (options["h"].count() > 0)
	{
		std::cout << "HELP" << std::endl;
	}

	auto dictionary = Dictionary();
	load_dictionary(options, dictionary);

	//! Default spelling cheaker -- user types in a word.
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

void load_arguments(cxxopts::Options& options, int argc, char** argv)
{
	options.add_options()
		("d,dictionary", "Point The Program To Your Own Dictionary", cxxopts::value<std::string>())
		("f,file", "File For Program To Sheck",cxxopts::value<std::string>())
		("h,help", "Help The User")
	;
	options.parse(argc, argv);
}

void load_dictionary(const cxxopts::Options& options, Dictionary& dictionary)
{
	//! Looking for a non-default dictionary.
	if (options["d"].count() > 0)
	{
		std::string dict_path = options["d"].as<std::string>();
		std::cout << "Looking for your custom dictionary...\n";
		if(dictionary.add_file(dict_path, Punctuation::Keep))
		{
			std::cout << "Found." << '\n';
		}
		else
		{
			std::cerr
				<< "Couldn't read the dictionary. Are you sure that "
				<< dict_path << " is right?" << '\n';
			std::exit(-1);
		}
	}
	//! Using default dictionary words.txt
	else
	{
		std::string dict_path = "words.txt";
		if(!dictionary.add_file(dict_path, Punctuation::Keep))
		{
			std::cerr
				<< "Couldn't read the default dictionary.\n"
			  << "The default file should be words.txt" << '\n';
			std::exit(-1);
		}
	}
}
