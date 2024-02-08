#ifndef CLOTHING_H
#define CLOTHING_H

#include "product.h"

class Clothing : public Product {
public:
    // Constructor
    Clothing(const std::string& size, const std::string& brand, const std::string& name, double price, int qty);

    // Destructor
    ~Clothing();

    // Returns keywords associated with the clothing
    virtual std::set<std::string> keywords() const override;

    // Returns a string representation of the clothing
    virtual std::string displayString() const override;

    // Outputs the clothing's data to the provided output stream
    virtual void dump(std::ostream& os) const override;

    // Returns information about the clothing
    virtual std::string getInfo() const override;

private:
    std::string size_;
    std::string brand_;
};

#endif // CLOTHING_H
