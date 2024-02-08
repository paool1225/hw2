#ifndef BOOK_H
#define BOOK_H

#include "product.h"

class Book : public Product {
public:
    // Constructor
    Book(const std::string& isbn, const std::string& author, const std::string& name, double price, int qty);

    // Destructor
    ~Book();

    // Returns keywords associated with the book
    virtual std::set<std::string> keywords() const override;

    // Returns a string representation of the book
    virtual std::string displayString() const override;

    // Outputs the book's data to the provided output stream
    virtual void dump(std::ostream& os) const override;

    // Returns information about the book
    virtual std::string getInfo() const override;

private:
    std::string isbn_;
    std::string author_;
};

#endif // BOOK_H
