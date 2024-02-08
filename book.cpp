#include <sstream>
#include "book.h"

// Constructor
Book::Book(const std::string& isbn, const std::string& author, const std::string& name, double price, int qty)
    : Product("book", name, price, qty), isbn_(isbn), author_(author) {}

// Destructor
Book::~Book() {}

// Returns keywords associated with the book
std::set<std::string> Book::keywords() const {
    std::set<std::string> bookKeywords;
    bookKeywords.insert(author_);
    return bookKeywords;
}

// Returns a string representation of the book
std::string Book::displayString() const {
    std::string display = Product::displayString() + "\nAuthor: " + author_ + "\nISBN: " + isbn_;
    return display;
}

// Outputs the book's data to the provided output stream
void Book::dump(std::ostream& os) const {
    os << "book" << std::endl;
    Product::dump(os);
    os << isbn_ << std::endl;
    os << author_ << std::endl;
}

// Returns information about the book
// Returns information about the book
std::string Book::getInfo() const {
    std::stringstream info;
    info << "Category: Book" << std::endl;
    info << "Name: " << name_ << std::endl;
    info << "Price: $" << price_ << std::endl;
    info << "Quantity: " << qty_ << std::endl;
    info << "ISBN: " << isbn_ << std::endl;
    info << "Author: " << author_ << std::endl;
    return info.str();
}

