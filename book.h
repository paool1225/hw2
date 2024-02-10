#ifndef BOOK_H
#define BOOK_H
#include "product.h"

class Book : public Product
{
public:
  Book(std::string ISBN, std::string author, std::string name, double price, int qty);
  ~Book();

  std::set<std::string> keywords() const override;
  std::string displayString() const override;
  void dump(std::ostream& os) const override;

private:
  std::string ISBN_;
  std::string author_;
};
#endif
