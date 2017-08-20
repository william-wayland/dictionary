#include <iostream>
#include <fstream>
#include <memory>
#include <unordered_set>
#include <string>
#include "timer.h"

class Dictionary
{
public:
	Dictionary():
		has_read_from_file(false)
	{

	}
	Dictionary(const std::string& path_to_file)
	{
		read_file(path_to_file);
	}

	void read_file(const std::string& path)
	{
		auto file = std::fstream();
		file.open(path);
		if (!file.is_open())
		{
			std::cerr << "Couldn't Read File At:" << path << std::endl;
			std::exit(-1);
		}

		while (!file.eof())
		{
			std::string s;
			std::getline(file, s);
			words.emplace(std::move(s));
		}
		has_read_from_file = true;
	}

	bool does_contain(const std::string& word)
	{
		return words.count(word) > 0;
	}

	~Dictionary() = default;
	Dictionary(const Dictionary& other) = default;
	Dictionary(Dictionary&& other) = default;
	Dictionary& operator=(const Dictionary& other) = default;
	Dictionary& operator=(Dictionary&& other) = default;

private:
	std::unordered_set<std::string> words;
	bool has_read_from_file;
};

int main()
{
	auto dictionary = Dictionary("words.txt");

	std::string users_word;
	while (true)
	{
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
	}
}
