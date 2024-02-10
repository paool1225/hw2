CXX=g++
CXXFLAGS=-g -Wall -std=c++11

# Add the missing implementation files to OBJS
OBJS=amazon.o user.o db_parser.o product.o product_parser.o util.o Book.o Clothing.o Movie.o mydatastore.o

# The main target
all: amazon

# The executable linking rule
amazon: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Rule for compiling amazon.cpp
amazon.o: amazon.cpp db_parser.h datastore.h product_parser.h mydatastore.h
	$(CXX) $(CXXFLAGS) -c amazon.cpp

# Rules for compiling other source files
user.o: user.cpp user.h 
	$(CXX) $(CXXFLAGS) -c user.cpp

db_parser.o: db_parser.cpp db_parser.h product.h product_parser.h user.h mydatastore.h 
	$(CXX) $(CXXFLAGS) -c db_parser.cpp

product.o: product.cpp product.h 
	$(CXX) $(CXXFLAGS) -c product.cpp

product_parser.o: product_parser.cpp product_parser.h product.h 
	$(CXX) $(CXXFLAGS) -c product_parser.cpp

util.o: util.cpp util.h
	$(CXX) $(CXXFLAGS) -c util.cpp

# Add rules for compiling the missing implementation files
Book.o: Book.cpp Book.h product.h
	$(CXX) $(CXXFLAGS) -c Book.cpp

Clothing.o: Clothing.cpp Clothing.h product.h
	$(CXX) $(CXXFLAGS) -c Clothing.cpp

Movie.o: Movie.cpp Movie.h product.h
	$(CXX) $(CXXFLAGS) -c Movie.cpp

mydatastore.o: mydatastore.cpp mydatastore.h
	$(CXX) $(CXXFLAGS) -c mydatastore.cpp

# Clean rule
clean:
	rm -f *.o amazon
