#include "mydatastore.h"
#include "util.h"
#include <iostream>

using namespace std;

MyDataStore::MyDataStore() {
    keyLinkUpdated_ = true;
}

MyDataStore::~MyDataStore() {
    // Delete dynamically allocated users
    for (auto it = users_.begin(); it != users_.end(); ++it)
        delete it->second;
    
    // Delete dynamically allocated products
    for (auto it = products_.begin(); it != products_.end(); ++it)
        delete *it;
}

void MyDataStore::addProduct(Product* p) {
    products_.insert(p);
    keyLinkUpdated_ = false;
}

void MyDataStore::addUser(User* u) {
    users_.insert(make_pair(u->getName(), u));
    // Initialize the user's cart as an empty queue
    userCarts_[u->getName()] = queue<Product*>();
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type) {
    if (!keyLinkUpdated_)
        updateKeywords();

    set<Product*> matches;

    for (auto term : terms) {
        if (keyWordLink_.find(term) != keyWordLink_.end()) {
            if (type == 0) {
                if (matches.empty())
                    matches = keyWordLink_[term];
                else
                    matches = setIntersection(keyWordLink_[term], matches);
            } else {
                matches = setUnion(keyWordLink_[term], matches);
            }
        }
    }

    vector<Product*> results(matches.begin(), matches.end());
    return results;
}

void MyDataStore::dump(ostream& ofile) {
    ofile << "<products>" << endl;
    for (auto it = products_.begin(); it != products_.end(); ++it)
        (*it)->dump(ofile);
    ofile << "</products>" << endl;

    ofile << "<users>" << endl;
    for (auto it = users_.begin(); it != users_.end(); ++it)
        it->second->dump(ofile);
    ofile << "</users>";
}

void MyDataStore::addToCart(string userName, Product* p) {
    if (users_.find(userName) != users_.end() && products_.find(p) != products_.end()) {
        // Add the product to the user's cart (queue)
        userCarts_[userName].push(p);
    }
}

void MyDataStore::viewCart(string userName) {
    if (userCarts_.find(userName) != userCarts_.end()) {
        int itemCount = 1;
        queue<Product*> userCart = userCarts_[userName];
        while (!userCart.empty()) {
            Product* item = userCart.front();
            cout << "Item " << itemCount++ << endl;
            cout << item->displayString() << endl;
            userCart.pop();
        }
    }
}

void MyDataStore::buyCart(string userName) {
    if (userCarts_.find(userName) != userCarts_.end()) {
        queue<Product*>& userCart = userCarts_[userName];
        while (!userCart.empty()) {
            Product* item = userCart.front();
            if (item->getQty() >= 1 && users_[userName]->getBalance() >= item->getPrice()) {
                item->subtractQty(1);
                users_[userName]->deductAmount(item->getPrice());
                userCart.pop();
            } else {
                break; // Stop processing the cart if user can't buy the next item
            }
        }
    }
}

void MyDataStore::updateKeywords() {
    for (auto product : products_) {
        set<string> keywords = product->keywords();
        for (auto keyword : keywords) {
            if (keyWordLink_.find(keyword) != keyWordLink_.end()) {
                keyWordLink_[keyword].insert(product);
            } else {
                keyWordLink_[keyword] = set<Product*>{product};
            }
        }
    }
}
