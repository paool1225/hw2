// movie.cpp
#include "movie.h"

Movie::Movie(const std::string& name, double price, int qty, const std::string& genre, const std::string& rating)
    : Product("movie", name, price, qty), genre_(genre), rating_(rating) {}

Movie::~Movie() {}

std::string Movie::getInfo() const {
    // Return information about the movie
    std::string info = "Genre: " + genre_ + ", Rating: " + rating_;
    return info;
}
