#ifndef MOVIE_H
#define MOVIE_H

#include "product.h"

class Movie : public Product {
public:
    // Constructor
    Movie(const std::string& genre, const std::string& rating, const std::string& name, double price, int qty);

    // Destructor
    ~Movie();

    // Returns keywords associated with the movie
    virtual std::set<std::string> keywords() const override;

    // Returns a string representation of the movie
    virtual std::string displayString() const override;

    // Outputs the movie's data to the provided output stream
    virtual void dump(std::ostream& os) const override;

    // Returns information about the movie
    virtual std::string getInfo() const override;

private:
    std::string genre_;
    std::string rating_;
};

#endif // MOVIE_H
