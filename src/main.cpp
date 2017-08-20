#include <iostream>
#include <fstream>
#include <memory>
#include <unordered_set>
#include <string>
#include "timer.h"

auto read_file(const std::string& path)
{
	auto file = std::fstream();
	file.open(path);
	if (!file.is_open())
	{
		std::cerr << "Couldn't Read File At:" << path << std::endl;
		std::exit(-1);
	}

 	auto file_data = std::unordered_set<std::string>();
	while (!file.eof())
	{
		std::string s;
		std::getline(file, s);
		file_data.emplace(std::move(s));
	}

	return std::make_unique<std::unordered_set<std::string>>
		(std::move(file_data));
}


int main()
{
	auto dictionary = read_file("words.txt");

	std::string users_word;
	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, users_word);
		if (dictionary->count(users_word) > 0)
		{
			std::cout << "That's a word." << "\n";
		}
		else
		{
			std::cout << "That's not a word." << "\n";
		}
	}
}
