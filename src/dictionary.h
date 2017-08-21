#include <iostream>
#include <fstream>
#include <unordered_set>
#include <algorithm>

enum class Punctuation{
	Remove,
	Keep
};

class Dictionary
{
public:
	Dictionary();
	Dictionary(
    const std::string& path_to_file,
    Punctuation punct = Punctuation::Remove);

	void add_file(
    const std::string& path,
    Punctuation punct = Punctuation::Remove);

	bool does_contain(const std::string& word);
	const std::unordered_set<std::string>& borrow_container();


private:
	std::unordered_set<std::string> words;
	bool has_read_a_file;
};
