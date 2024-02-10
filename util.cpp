#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;

std::string convToLower(std::string src) 
{
  std::transform(src.begin(), src.end(), src.begin(), ::tolower);
  return src;
}

/** Complete the code to convert a string containing a rawWord 
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWord) 
{
  set<string> parsedWords;

  string tempWord;
  stringstream ss(rawWord);
  while (ss >> tempWord)
  {
    tempWord = convToLower(tempWord);
    string word;
    for (char& c : tempWord)
    {
      if (isalpha(c))
      {
        word += c;
      }
      else
      {
        if (word.size() >= 2)
        {
          parsedWords.insert(word);
        }
        word = "";
      }
    }
    if (word.size() >= 2)
    {
      parsedWords.insert(word);
    }
  }

  return parsedWords;
}
