#include "Goods.h"
#include <iostream>

using namespace std;

//Constructor
Goods::Goods(string name, string description, double rating, string expirationDate, int quantity)
    : Product(name, description, rating), expirationDate(expirationDate), quantity(quantity) {}

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
       << "Expiration Date: " << expirationDate << "\n"
       << "Quantity: " << quantity << "\n"
       << "Times Sold: " << timesSold;
}

// Input function
void Goods::input(istream& is) {
    cout << "Enter product name: ";
    getline(is, name);
    cout << "Enter description: ";
    getline(is, description);
    cout << "Enter rating (0-5): ";
    is >> rating;
    is.ignore();
    cout << "Enter expiration date: ";
    getline(is, expirationDate);
    cout << "Enter quantity: ";
    is >> quantity;
    is.ignore();
}