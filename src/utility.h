//! Usefull String Utility Funtions (USUF)
#ifndef UTILITY_H
#define UTILITY_H

#pragma once
#include <string>
#include <regex>
#include <vector>
#include <sstream>

namespace util {

  static std::regex alpha("[^A-Za-z]");

  static void remove_puncuation(std::string& s)
  {
    s = std::regex_replace(s, alpha, "");
  }

  static void split(const std::string& s, char delim, std::vector<std::string>& v)
  {
    std::stringstream ss(s);
    std::string temp;
    while(std::getline(ss, temp, delim))
    {
      v.push_back(temp);
    }
  }

  static void lower_first_char(std::string& s)
  {
    s[0] = tolower(s[0]);
  }
}

#endif
