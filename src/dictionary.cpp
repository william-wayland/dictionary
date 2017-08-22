#include "dictionary.h"

Dictionary::Dictionary():
  has_read_a_file(false),
  alpha("[^A-Za-z]")
{
}

Dictionary::Dictionary(
  const std::string& path_to_file,
  Punctuation punct):
  alpha("[^A-Za-z]")
{
  add_file(path_to_file, punct);
}

//! Searchs the container for a word
bool Dictionary::contains(const std::string& word)
{
  if (has_read_a_file)
  {
    return words.count(word) > 0;
  }
  std::cerr << "I haven't loaded any words into the dictionary." << '\n';
  std::cerr << "Use \"Dictionary::add_a_file(path)\"." << '\n';
  return false;
}

//! Reads a file from the path, and adds each word found into the container.
void Dictionary::add_file(
  const std::string& path,
  Punctuation punct)
{
  auto file = std::fstream();
  file.open(path);
  if (!file.is_open())
  {
    std::cerr << "Couldn't Read File At:" << path << std::endl;
    std::exit(-1);
  }

  //! Search through the file for words.
  auto word = std::string();
  while (file >> word)
  {
    if (punct == Punctuation::CompleteRemoval)
    {
      remove_puncuation(word);
    }
    words.emplace(std::move(word));
  }

  has_read_a_file = true;
}

//! Returns a unmutable reference to the dictionary's container -- safe
const std::unordered_set<std::string>& Dictionary::get_container_ref() {
  return words;
}
