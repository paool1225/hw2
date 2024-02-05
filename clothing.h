// clothing.h
#ifndef CLOTHING_H
#define CLOTHING_H

#include "product.h"

class Clothing : public Product {
public:
    Clothing(const std::string& name, double price, int qty, const std::string& size, const std::string& brand);
    virtual ~Clothing();

    // Implementing the getInfo() function
    virtual std::string getInfo() const override;

private:
    std::string size_;
    std::string brand_;
};

#endif
