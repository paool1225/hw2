#ifndef MY_DATASTORE_H
#define MY_DATASTORE_H 

#include "datastore.h"
#include <map>
#include <queue>

class MyDataStore : public DataStore
{
public:
    MyDataStore(); // Constructor
    ~MyDataStore(); // Destructor

    void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void dump(std::ostream& ofile);
    void addToCart(std::string userName, Product* p);
    void viewCart(std::string userName);
    void buyCart(std::string userName);

protected:
    void updateKeywords();

private:
    std::map<std::string, User*> users_;
    std::set<Product*> products_;
    std::map<std::string, std::queue<Product*>> userCarts_; // Using a queue for each user's cart
    std::map<std::string, std::set<Product*>> keyWordLink_;
    bool keyLinkUpdated_;
};

#endif
