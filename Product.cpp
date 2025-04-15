// TO DO: #include all the standard libraries and your own libraries here
// TO DO: function implementations
#include "Product.h"
#include <iostream>
using namespace std;
// ------------------------------------------------------------------------------
Product::Product(string name, string description, double rating, double price)
	:name(name), description(description), rating(rating), price(price), timesSold(0){}

//getters
string Product::getName() const {return name;}
string Product::getDescription() const {return description;}
double Product::getRating() const {return rating;}
int Product::getTimesSold() const {return timesSold;}
double Product::getPrice() const { return price; }

//setters
void Product::setName(string newName) {name = newName;}
void Product::setDescription(string newDescription) {description = newDescription;}
void Product::setRating(double newRating) {rating = newRating;}
void Product::setPrice(double newPrice) { price = newPrice; }

// I/O Operator Overloading
ostream& operator<<(ostream& os, const Product& product) {
	product.display(os);
	return os;
}

istream& operator>>(istream& is, Product& product) {
	product.input(is);
	return is;
}

// Operator overloading implementation
bool Product::operator==(const Product& otherProduct) const {
	return Product::name == otherProduct.name;
}




