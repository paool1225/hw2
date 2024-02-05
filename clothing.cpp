// clothing.cpp
#include "clothing.h"

Clothing::Clothing(const std::string& name, double price, int qty, const std::string& size, const std::string& brand)
    : Product("clothing", name, price, qty), size_(size), brand_(brand) {}

Clothing::~Clothing() {}

std::string Clothing::getInfo() const {
    // Return information about the clothing
    std::string info = "Size: " + size_ + ", Brand: " + brand_;
    return info;
}
