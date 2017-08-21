#include "dictionary.h"

Dictionary::Dictionary():
  has_read_a_file(false)
{
}

Dictionary::Dictionary(
  const std::string& path_to_file,
  bool remove_punctuations)
{
  add_a_file(path_to_file, remove_punctuations);
}

//! Searchs the container for a word
bool Dictionary::does_contain(const std::string& word)
{
  if (has_read_a_file) {
    return words.count(word) > 0;
  }
  std::cerr << "I havn't loaded any words into the dictionary." << '\n';
  std::cerr << "Use \"Dictionary::add_a_file(path)\"." << '\n';
  return false;
}

//! Reads a file from the path, and adds each word found into the container.
void Dictionary::add_a_file(
  const std::string& path,
  bool remove_punctuations)
{
  auto file = std::fstream();
  file.open(path);
  if (!file.is_open())
  {
    std::cerr << "Couldn't Read File At:" << path << std::endl;
    std::exit(-1);
  }

  //! Search through the file for words.
  while (true)
  {
    auto word = std::string();
    if (file >> word)
    {
      if (remove_punctuations) {
        word.erase(std::remove(word.begin(), word.end(), '.'), word.end());
        word.erase(std::remove(word.begin(), word.end(), ','), word.end());
        word.erase(std::remove(word.begin(), word.end(), ';'), word.end());
        word.erase(std::remove(word.begin(), word.end(), '?'), word.end());
        word.erase(std::remove(word.begin(), word.end(), '!'), word.end());
        word.erase(std::remove(word.begin(), word.end(), ':'), word.end());
        word.erase(std::remove(word.begin(), word.end(), '('), word.end());
        word.erase(std::remove(word.begin(), word.end(), ')'), word.end());
      }
      words.emplace(std::move(word));
    }
    else
    {
      break;
    }
  }

  //! Perform a check for each word (there may have been a hash-collision).
  for (const auto& word: words) {
		if (!does_contain(word)) {
			std::cerr << "Missing word " << word << "\n";
		}
	}

  has_read_a_file = true;
}

//! Returns a unmutable reference to the dictionary's container
const std::unordered_set<std::string>& Dictionary::borrow_container() {
  return words;
}
