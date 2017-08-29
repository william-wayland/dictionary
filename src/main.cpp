#include <string>
#include <fstream>
#include "timer.h"
#include "dictionary.h"
#include "cxxopts.hpp"
#include "utility.h"

//! load_dictionary
//! Uses the arguments to find what file the user wants to act as a dictionary
//! And load it into memory.
void load_dictionary(const cxxopts::Options& options, Dictionary& dictionary);

//! load_arguments loads some pre-defined arguments
void load_arguments(cxxopts::Options& options, int argc, char** argv);

//! loop_user_input takes in user input from stdin (or > )
//! and tells the user if the word is in the dictionary.
void loop_user_input(const Dictionary& dictionary);

//! check_file_for_errors goes through a file provided by the user
//! and checks each word against the dictionary.
void check_file_for_errors(const Dictionary& dictionary, const std::string& path);


int main(int argc, char** argv)
{
	cxxopts::Options options("spch", "Spell Checker: A C++ implementation of a spelling checker.");
	load_arguments(options, argc, argv);

	//! If the user asks for help.
	if (options["h"].count() > 0)
	{
		std::cout << options.help({"", "Group"}) << std::endl;
		std::exit(-1);
	}

	//! load the dictionary
	auto dictionary = Dictionary();
	load_dictionary(options, dictionary);

	//! User is providing a file to check for errors.
	if (options["f"].count() > 0)
	{
		check_file_for_errors(dictionary, options["f"].as<std::string>());
	}
	//! use stdin for words to check.
	else
	{
		loop_user_input(dictionary);
	}
}

void check_file_for_errors(const Dictionary& dictionary, const std::string& path)
{
	std::string line;
	std::fstream file;
	int line_number = 1;
	file.open(path);
	if (file.is_open())
	{
		while(std::getline(file, line))
		{
			auto word_list = std::vector<std::string>();
			util::split(line, ' ', word_list);
			for(auto& word: word_list)
			{
				util::remove_puncuation(word);
				if (!dictionary.contains(word))
				{
					std::cout << "Found error in line: " << line_number << "\n";
					std::cout << "The word \"" << word << "\" was not reconised.\n\n";
				}
			}
			line_number++;
		}
	}
}

void loop_user_input(const Dictionary& dictionary)
{
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
	options.add_options("Group")
		("d,dictionary", "The file you want to program to load its dictionary from.", cxxopts::value<std::string>())
		("f,file", "The file you want the program to check.",cxxopts::value<std::string>())
		("h,help", "Get this message again...")
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
		if(dictionary.add_file(dict_path, Punctuation::CompleteRemoval))
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
		if(dictionary.add_file(dict_path, Punctuation::Keep))
		{
			std::cout << "Reading from standard dictionary." << '\n';
		}
		else
		{
			std::cerr
				<< "Couldn't read the default dictionary.\n"
			  << "The default file should be words.txt" << '\n';
			std::exit(-1);
		}
	}
}
