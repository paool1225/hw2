#include <sstream>
#include "movie.h"

// Constructor
Movie::Movie(const std::string& genre, const std::string& rating, const std::string& name, double price, int qty)
    : Product("movie", name, price, qty), genre_(genre), rating_(rating) {}

// Destructor
Movie::~Movie() {}

// Returns keywords associated with the movie
std::set<std::string> Movie::keywords() const {
    std::set<std::string> movieKeywords;
    movieKeywords.insert(genre_);
    movieKeywords.insert(rating_);
    return movieKeywords;
}

// Returns a string representation of the movie
std::string Movie::displayString() const {
    std::string display = Product::displayString() + "\nGenre: " + genre_ + "\nRating: " + rating_;
    return display;
}

// Outputs the movie's data to the provided output stream
void Movie::dump(std::ostream& os) const {
    os << "movie" << std::endl;
    Product::dump(os);
    os << genre_ << std::endl;
    os << rating_ << std::endl;
}

// Returns information about the movie
std::string Movie::getInfo() const {
    std::stringstream info;
    info << "Category: Movie" << std::endl;
    info << "Name: " << name_ << std::endl;
    info << "Price: $" << price_ << std::endl;
    info << "Quantity: " << qty_ << std::endl;
    info << "Genre: " << genre_ << std::endl;
    info << "Rating: " << rating_ << std::endl;
    return info.str();
}
