#include <sstream>
#include "clothing.h"

// Constructor
Clothing::Clothing(const std::string& size, const std::string& brand, const std::string& name, double price, int qty)
    : Product("clothing", name, price, qty), size_(size), brand_(brand) {}

// Destructor
Clothing::~Clothing() {}

// Returns keywords associated with the clothing
std::set<std::string> Clothing::keywords() const {
    std::set<std::string> clothingKeywords;
    clothingKeywords.insert(size_);
    clothingKeywords.insert(brand_);
    return clothingKeywords;
}

// Returns a string representation of the clothing
std::string Clothing::displayString() const {
    std::string display = Product::displayString() + "\nSize: " + size_ + "\nBrand: " + brand_;
    return display;
}

// Outputs the clothing's data to the provided output stream
void Clothing::dump(std::ostream& os) const {
    os << "clothing" << std::endl;
    Product::dump(os);
    os << size_ << std::endl;
    os << brand_ << std::endl;
}

// Returns information about the clothing
std::string Clothing::getInfo() const {
    std::stringstream info;
    info << "Category: Clothing" << std::endl;
    info << "Name: " << name_ << std::endl;
    info << "Price: $" << price_ << std::endl;
    info << "Quantity: " << qty_ << std::endl;
    info << "Size: " << size_ << std::endl;
    info << "Brand: " << brand_ << std::endl;
    return info.str();
}
