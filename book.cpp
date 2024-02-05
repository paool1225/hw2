#include "book.h"

Book::Book(const std::string& name, double price, int qty, const std::string& isbn, const std::string& author)
    : Product("book", name, price, qty), isbn_(isbn), author_(author) {}

Book::~Book() {}

std::string Book::getInfo() const {
    // Return information about the book
    std::string info = "ISBN: " + isbn_ + ", Author: " + author_;
    return info;
}