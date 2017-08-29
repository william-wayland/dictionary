#include "dictionary.h"

Dictionary::Dictionary():
  has_read_a_file(false)
{
}

Dictionary::Dictionary(
  const std::string& path_to_file,
  Punctuation punct)
{
  add_file(path_to_file, punct);
}

//! Searchs the container for a word
bool Dictionary::contains(const std::string& word) const
{
  if (!has_read_a_file)
  {
    std::cerr << "I haven't loaded any words into the dictionary." << '\n';
    std::cerr << "Use \"Dictionary::add_a_file(path)\"." << '\n';
    return false;
  }

  if (words.count(word) > 0)
  {
    return true;
  }

  //! try searching my lowering the case - requires a copy
  auto copy = word;
  util::lower_first_char(copy);
  return words.count(copy) > 0;
}

//! Reads a file from the path, and adds each word found into the container.
bool Dictionary::add_file(
  const std::string& path,
  Punctuation punct)
{
  auto file = std::fstream();
  file.open(path);
  if (!file.is_open())
  {
    return false;
  }

  //! Search through the file for words.
  auto word = std::string();
  while (file >> word)
  {
    if (punct == Punctuation::CompleteRemoval)
    {
      util::remove_puncuation(word);
    }
    words.emplace(std::move(word));
  }
  has_read_a_file = true;
  return true;
}

//! Returns a unmutable reference to the dictionary's container -- safe
const std::unordered_set<std::string>& Dictionary::inner_immutable_ref() const {
  return words;
}
