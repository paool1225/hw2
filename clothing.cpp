#include "Clothing.h"
#include "util.h"
#include <sstream>

Clothing::Clothing(std::string size, std::string brand, std::string name, double price, int qty)
    : Product("clothing", name, price, qty), size_(size), brand_(brand) {}

Clothing::~Clothing() {}

std::set<std::string> Clothing::keywords() const {
    std::set<std::string> keyWords = parseStringToWords(name_);

    std::set<std::string> parsedWords = parseStringToWords(brand_);
    for (auto it = parsedWords.begin(); it != parsedWords.end(); ++it)
        keyWords.insert(*it);

    return keyWords;
}

std::string Clothing::displayString() const {
    std::string display = name_ + "\n" +
                          "Brand: " + brand_ + " Size: " + size_ + "\n";

    std::stringstream num;
    num << price_;
    display = display + num.str() + " ";
    num.str("");
    num << qty_;
    display = display + num.str() + " left.";

    return display;
}

void Clothing::dump(std::ostream& os) const {
    Product::dump(os);
    os << size_ << "\n" << brand_ << std::endl;
}
