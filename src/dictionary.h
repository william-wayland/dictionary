#include <iostream>
#include <fstream>
#include <unordered_set>
#include <algorithm>

class Dictionary
{
public:
	Dictionary();
	Dictionary(
    const std::string& path_to_file,
    bool remove_punctuations = true);

	void add_a_file(
    const std::string& path,
    bool remove_punctuations = true);

	bool does_contain(const std::string& word);
  const std::unordered_set<std::string>& borrow_container();
private:
	std::unordered_set<std::string> words;
	bool has_read_a_file;
};
