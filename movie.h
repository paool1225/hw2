// movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"

class Movie : public Product {
public:
    Movie(const std::string& name, double price, int qty, const std::string& genre, const std::string& rating);
    virtual ~Movie();

    // Implementing the getInfo() function
    virtual std::string getInfo() const override;

private:
    std::string genre_;
    std::string rating_;
};

#endif
