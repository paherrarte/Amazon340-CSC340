#include "Goods.h"
#include <iostream>

using namespace std;

//Constructor
Goods::Goods(string name, string description, double rating, double price, string expirationDate, int quantity)
    : Product(name, description, rating, price), expirationDate(expirationDate), quantity(quantity) {}

//Getters
string Goods::getExpirationDate() const {return expirationDate;}
int Goods::getQuantity() const {return quantity;}

//Setters
void Goods::setExpirationDate(string newDate) {expirationDate = newDate;}
void Goods::setQuantity(int newQuantity) {quantity = newQuantity;}

//Sell function
void Goods::sell(){
    if(quantity > 0){
        quantity--;
        timesSold++;
        cout << "Sold one unit of " << name << ". Remaining stock: " << quantity << endl;
    }else{
        cout << "Error: " << name << " is sold out." << endl;
    }
}

// Display function
void Goods::display(ostream& os) const {
    os << "Goods: " << name << "\n"
       << "Description: " << description << "\n"
       << "Rating: " << rating << "\n"
       << "Price: $" << price << "\n"
       << "Expiration Date: " << expirationDate << "\n"
       << "Quantity: " << quantity << "\n"
       << "Times Sold: " << timesSold;
}

// Input function
void Goods::input(istream& is) {
    if (&is == &cin) {
        cout << "Enter product name: ";
    }
    getline(is, name);
    
    if (&is == &cin) {
        cout << "Enter description: ";
    }
    getline(is, description);
    
    if (&is == &cin) {
        cout << "Enter rating (0-5): ";
    }
    is >> rating;
    is.ignore();
    
    if (&is == &cin) {
        cout << "Enter price: $";
    }
    is >> price;
    is.ignore();
    
    if (&is == &cin) {
        cout << "Enter expiration date: ";
    }
    getline(is, expirationDate);
    
    if (&is == &cin) {
        cout << "Enter quantity: ";
    }
    is >> quantity;
    is.ignore();
}

ostream& operator<<(ostream& os, const Goods& goods) {
    os << "Goods Details:\n"
       << "Name: " << goods.getName() << "\n"
       << "Description: " << goods.getDescription() << "\n"
       << "Rating: " << goods.getRating() << "\n"
       << "Price: $" << goods.getPrice() << "\n"
       << "Times Sold: " << goods.getTimesSold() << "\n"
       << "Expiration Date: " << goods.getExpirationDate() << "\n"
       << "Quantity: " << goods.getQuantity() << "\n";
    return os;
}

istream& operator>>(istream& is, Goods& goods) {
    string name, description, expirationDate;
    double rating, price;
    int quantity;

    cout << "Enter Goods Information:\n";
    cout << "Name: ";
    getline(is, name);
    cout << "Description: ";
    getline(is, description);
    cout << "Rating: ";
    is >> rating;
    is.ignore();
    cout << "Price: $";
    is >> price;
    is.ignore();
    cout << "Expiration Date: ";
    getline(is, expirationDate);
    cout << "Quantity: ";
    is >> quantity;
    is.ignore();

    goods.setName(name);
    goods.setDescription(description);
    goods.setRating(rating);
    goods.setPrice(price);
    goods.setExpirationDate(expirationDate);
    goods.setQuantity(quantity);

    return is;
}