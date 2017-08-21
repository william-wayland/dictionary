#include <iostream>
#include <fstream>
#include <unordered_set>

class Dictionary
{
public:
	Dictionary();
	Dictionary(const std::string& path_to_file);
	void add_a_file(const std::string& path);
	bool does_contain(const std::string& word);
private:
	std::unordered_set<std::string> words;
	bool has_read_a_file;
};
