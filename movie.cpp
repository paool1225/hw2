#include "Movie.h"
#include "util.h"
#include <sstream>

Movie::Movie(std::string genre, std::string rating, std::string name, double price, int qty)
    : Product("movie", name, price, qty), genre_(genre), rating_(rating) {}

Movie::~Movie() {}

std::set<std::string> Movie::keywords() const {
    std::set<std::string> keyWords = parseStringToWords(name_);
    keyWords.insert(convToLower(genre_));

    return keyWords;
}

std::string Movie::displayString() const {
    std::string display = name_ + "\n" +
                          "Genre: " + genre_ + " Rating: " + rating_ + "\n";

    std::stringstream num;
    num << price_;
    display = display + num.str() + " ";
    num.str("");
    num << qty_;
    display = display + num.str() + " left.";

    return display;
}

void Movie::dump(std::ostream& os) const {
    Product::dump(os);
    os << genre_ << "\n" << rating_ << std::endl;
}
