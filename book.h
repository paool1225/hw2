#ifndef BOOK_H
#define BOOK_H

#include "product.h"

class Book : public Product {
public:
    Book(const std::string& name, double price, int qty, const std::string& isbn, const std::string& author);
    virtual ~Book();

    // Implementing the getInfo() function
    virtual std::string getInfo() const override;

private:
    std::string isbn_;
    std::string author_;
};

#endif