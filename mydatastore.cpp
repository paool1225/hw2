#include <sstream>
#include "mydatastore.h"

MyDataStore::MyDataStore() {
    // Constructor implementation
}

MyDataStore::~MyDataStore() {
    // Destructor implementation
    // Deallocate memory for products, users, and carts
    for (auto it = users_.begin(); it != users_.end(); ++it) {
        delete it->second;
    }
    for (auto it = carts_.begin(); it != carts_.end(); ++it) {
        for (size_t i = 0; i < it->second.size(); ++i) {
            delete it->second[i];
        }
    }
}

void MyDataStore::addProduct(Product* p) {
    // Add product to the keywords map for searching
    std::set<std::string> productKeywords = p->keywords();
    for (const auto& keyword : productKeywords) {
        keywords_[keyword].insert(p);
    }
}

void MyDataStore::addUser(User* u) {
    // Add user to the users map
    users_[u->getName()] = u;
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
    // Search for products based on search terms and type
    return searchHelper(terms, type);
}

void MyDataStore::addToCart(std::string username, Product* p) {
    // Add product to user's cart
    carts_[username].push_back(p);
}

void MyDataStore::viewCart(std::string username) {
    // Display products in user's cart
    std::vector<Product*> cart = carts_[username];
    for (size_t i = 0; i < cart.size(); ++i) {
        std::cout << "[" << i+1 << "] " << cart[i]->displayString() << std::endl;
    }
}

void MyDataStore::buyCart(std::string username) {
    // Process buying the products in user's cart
    std::vector<Product*>& cart = carts_[username];
    double totalCost = 0.0;

    for (size_t i = 0; i < cart.size(); ++i) {
        Product* product = cart[i];
        if (product->getQty() > 0 && users_[username]->getBalance() >= product->getPrice()) {
            product->subtractQty(1);
            users_[username]->deductAmount(product->getPrice());
            totalCost += product->getPrice();
        }
    }
    // Clear the user's cart after purchase
    carts_[username].clear();
}

void MyDataStore::quit(std::string filename) {
    // Save the updated database to a file
    std::ofstream ofs(filename);
    if (!ofs) {
        std::cerr << "Error: Unable to open file " << filename << " for writing" << std::endl;
        return;
    }

    // Save products to the file
    ofs << "<products>" << std::endl;
    for (const auto& pair : keywords_) {
        for (Product* p : pair.second) {
            ofs << p->getName() << std::endl;
            ofs << p->getPrice() << std::endl;
            ofs << p->getQty() << std::endl;
            ofs << p->getInfo() << std::endl;
        }
    }
    ofs << "</products>" << std::endl;

    // Save users to the file
    ofs << "<users>" << std::endl;
    for (const auto& pair : users_) {
        ofs << pair.second->getName() << " " << pair.second->getBalance() << std::endl;
    }
    ofs << "</users>" << std::endl;

    ofs.close();
}

std::set<std::string> MyDataStore::extractKeywords(std::string text) {
    // Extract keywords from the given text
    std::set<std::string> keywords;
    std::istringstream iss(text);
    std::string word;
    while (iss >> word) {
        // Convert word to lowercase and remove punctuation
        word = convToLower(trim(word));
        keywords.insert(word);
    }
    return keywords;
}

std::vector<Product*> MyDataStore::searchHelper(std::vector<std::string>& terms, int type) {
    // Search for products based on search terms and type
    std::vector<Product*> results;
    std::set<Product*> tempSet;

    // Extract keywords from each search term
    for (size_t i = 0; i < terms.size(); ++i) {
        std::string term = terms[i];
        std::set<std::string> keywords = extractKeywords(term);

        // Perform intersection or union based on type
        if (type == 0) { // AND search
            if (i == 0) {
                tempSet = keywords_[*keywords.begin()];
            } else {
                std::set<Product*> resultSet;
                std::set_intersection(tempSet.begin(), tempSet.end(), keywords_[*keywords.begin()].begin(), keywords_[*keywords.begin()].end(), std::inserter(resultSet, resultSet.begin()));
                tempSet = resultSet;
            }
        } else { // OR search
            for (const auto& keyword : keywords) {
                std::set<Product*> keywordSet = keywords_[keyword];
                tempSet.insert(keywordSet.begin(), keywordSet.end());
            }
        }
    }

    // Convert set to vector
    for (const auto& product : tempSet) {
        results.push_back(product);
    }

    return results;
}
void MyDataStore::dump(std::ostream& ofile) {
    // Dump products
    ofile << "<products>" << std::endl;
    for (const auto& pair : keywords_) {
        for (Product* p : pair.second) {
            ofile << p->getName() << std::endl;
            ofile << p->getPrice() << std::endl;
            ofile << p->getQty() << std::endl;
            ofile << p->getInfo() << std::endl;
        }
    }
    ofile << "</products>" << std::endl;

    // Dump users
    ofile << "<users>" << std::endl;
    for (const auto& pair : users_) {
        ofile << pair.second->getName() << " " << pair.second->getBalance() << std::endl;
    }
    ofile << "</users>" << std::endl;
}

std::vector<Product*> MyDataStore::getHits() {
    // Retrieve and return hits from the data store
    std::vector<Product*> hits;

    for (const auto& pair : keywords_) {
        for (Product* p : pair.second) {
            hits.push_back(p);
        }
    }

    return hits;
}
