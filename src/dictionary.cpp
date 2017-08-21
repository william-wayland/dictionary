#include "dictionary.h"

Dictionary::Dictionary():
  has_read_a_file(false)
{
}

Dictionary::Dictionary(const std::string& path_to_file)
{
  add_a_file(path_to_file);
}

bool Dictionary::does_contain(const std::string& word)
{
  if (has_read_a_file) {
    return words.count(word) > 0;
  }
  std::cerr << "I havn't loaded any words into the dictionary." << '\n';
  std::cerr << "Use \"Dictionary::add_a_file(path)\"." << '\n';
  return false;
}

void Dictionary::add_a_file(const std::string& path)
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
  has_read_a_file = true;
}
