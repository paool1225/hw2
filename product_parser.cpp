#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "product_parser.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"
using namespace std;


static std::string &trim(std::string &s);

ProductParser::ProductParser() 
{
 
}


ProductParser::~ProductParser()
{

}


Product* ProductParser::parse(string category,
			      istream& is,
			      bool& error,
			      string& errorMsg,
			      int& lineno)
{

  parseCommonProduct(is, error, errorMsg, lineno);
  if(error) return NULL;
  return parseSpecificProduct(category, is, error, errorMsg, lineno);
}

void ProductParser::parseCommonProduct(std::istream& is, 
				       bool& error,
				       string& errorMsg,
				       int& lineno)
  
{
  lineno++;
  string myline;
  getline(is, myline);
  myline = trim(myline);
  if(myline.size() == 0){
    error = true;
    errorMsg = "Unable to find a product name";
    return;
  }
  prodName_ = myline;
  
  lineno++;
  getline(is, myline);
  if(is.fail()){
    error = true;
    errorMsg = "Expected another line with the price";
    return;    
  }
  stringstream ss1(myline);
  ss1 >> price_;
  if( ss1.fail() ){
    error = true;
    errorMsg = "Unable to read price";
    return;
  }

  lineno++;
  getline(is, myline);
  if(is.fail()){
    error = true;
    errorMsg = "Expected another line with the quantity";
    return;    
  }
  stringstream ss2(myline);
  ss2 >> qty_;
  if( ss2.fail() ){
    error = true;
    errorMsg = "Unable to read quantity";
  }
}

static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// Definition of trim function
static inline std::string &trim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
    return s;
}

Product* ProductBookParser::parseSpecificProduct(std::string category,
                                                 std::istream& is,
                                                 bool& error,
                                                 std::string& errorMsg,
                                                 int& lineno)
{
    lineno++;
    string myline;
    getline(is, myline);
    stringstream ss3(myline);
    ss3 >> isbn_;
    if(ss3.fail()) {
        error = true;
        errorMsg = "Unable to read ISBN";
    }
  
    lineno++;
    getline(is, author_);
    if(is.fail()) {
        error = true;
        errorMsg = "Unable to read author";
    }
    
    if(error) {
        return nullptr;
    }
    
#ifdef DEBUG
    cout << "Making product " << prodName_ << endl;
#endif
    return makeProduct();    
}

std::string ProductBookParser::categoryID() {
    return "book";
}

Product* ProductBookParser::makeProduct() {
    return new Book(isbn_, author_, prodName_, price_, qty_);
}

// Implementation of ProductClothingParser methods
ProductClothingParser::ProductClothingParser() : ProductParser() {}

Product* ProductClothingParser::parseSpecificProduct(std::string category,
                                                     std::istream& is,
                                                     bool& error,
                                                     std::string& errorMsg,
                                                     int& lineno)
{
    lineno++;
    string myline;
    getline(is, myline);
    stringstream ss3(myline);
    ss3 >> size_;
    if(ss3.fail()) {
        error = true;
        errorMsg = "Unable to read size";
    }
  
    lineno++;
    getline(is, brand_);
    if(is.fail()) {
        error = true;
        errorMsg = "Unable to read brand";
    }
    
    if(error) {
        return nullptr;
    }
    
#ifdef DEBUG
    cout << "Making product " << prodName_ << endl;
#endif
    return makeProduct();    
}

std::string ProductClothingParser::categoryID() {
    return "clothing";
}

Product* ProductClothingParser::makeProduct() {
    return new Clothing(size_, brand_, prodName_, price_, qty_);
}

// Implementation of ProductMovieParser methods
ProductMovieParser::ProductMovieParser() : ProductParser() {}

Product* ProductMovieParser::parseSpecificProduct(std::string category,
                                                  std::istream& is,
                                                  bool& error,
                                                  std::string& errorMsg,
                                                  int& lineno)
{
    lineno++;
    string myline;
    getline(is, myline);
    stringstream ss3(myline);
    ss3 >> genre_;
    if(ss3.fail()) {
        error = true;
        errorMsg = "Unable to read genre";
    }
  
    lineno++;
    getline(is, myline);
    stringstream ss4(myline);
    ss4 >> rating_;
    if(ss4.fail()) {
        error = true;
        errorMsg = "Unable to read rating";
    }
    
    if(error) {
        return nullptr;
    }
    
#ifdef DEBUG
    cout << "Making product " << prodName_ << endl;
#endif
    return makeProduct();    
}

std::string ProductMovieParser::categoryID() {
    return "movie";
}

Product* ProductMovieParser::makeProduct() {
    return new Movie(genre_, rating_, prodName_, price_, qty_);
}