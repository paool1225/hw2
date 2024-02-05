#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include "util.h"
#include "product.h"
#include "user.h"
#include <map>
#include <set>
#include <vector>
#include <fstream>

class MyDataStore : public DataStore {
public:
    MyDataStore();
    ~MyDataStore();

    void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> getHits(); // Declaration of getHits() function
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void addToCart(std::string username, Product* p);
    void viewCart(std::string username);
    void buyCart(std::string username);
    void quit(std::string filename);
    void dump(std::ostream& ofile) override;

private:
    std::map<std::string, std::set<Product*>> keywords_;
    std::map<std::string, User*> users_;
    std::map<std::string, std::vector<Product*>> carts_;

    std::set<std::string> extractKeywords(std::string text);
    std::vector<Product*> searchHelper(std::vector<std::string>& terms, int type);
};

#endif // MYDATASTORE_H
