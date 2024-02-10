#include "Book.h"
#include "util.h"
#include <sstream>

Book::Book(std::string ISBN, std::string author, std::string name, double price, int qty) : Product("book", name, price, qty)
{
  ISBN_ = ISBN;
  author_ = author;
}

Book::~Book()
{
}

std::set<std::string> Book::keywords() const
{
  std::set<std::string> keyWords = parseStringToWords(name_);
  keyWords.insert(ISBN_);

  std::set<std::string> parsedWords = parseStringToWords(author_);
  for (auto it = parsedWords.begin(); it != parsedWords.end(); ++it)
    keyWords.insert(*it);

  return keyWords;
}

std::string Book::displayString() const
{
  std::string display = name_ + "\n" +
                        "Author: " + author_ + " ISBN: " + ISBN_ + "\n";

  std::stringstream num;
  num << price_;
  display = display + num.str() + " ";
  num.str("");
  num << qty_;
  display = display + num.str() + " left.";

  return display;
}

void Book::dump(std::ostream& os) const
{
  Product::dump(os);
  os << ISBN_ << "\n" << author_ << std::endl;
}
