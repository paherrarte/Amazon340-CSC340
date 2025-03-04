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