#include <iostream>
#include <fstream>
#include <unordered_set>
#include <algorithm>
#include <regex>

enum class Punctuation{
	Keep,
	CompleteRemoval
};

class Dictionary
{
public:
	Dictionary();
	Dictionary(
    const std::string& path_to_file,
    Punctuation punct = Punctuation::CompleteRemoval);

	bool add_file(
    const std::string& path,
    Punctuation punct = Punctuation::CompleteRemoval);

	bool contains(const std::string& word);
	const std::unordered_set<std::string>& inner_immutable_ref() const;

private:
	void remove_puncuation(std::string& s)
	{
		s = std::regex_replace(s, alpha, "");
	}

	std::unordered_set<std::string> words;
	bool has_read_a_file;
	std::regex alpha;
};
