#ifndef GOODS_H
#define GOODS_H

#include "Product.h"
#include <iostream>
using namespace std;

class Goods : public Product {
private:
    string expirationDate;
    int quantity; // Stock count

public:
    // Constructor
    Goods(string name, string description, double rating, string expirationDate, int quantity);

    // BIG 3
    ~Goods() override = default;
    Goods(const Goods& other) = default;
    Goods& operator=(const Goods& other) = default;

    // Getters and Setters
    string getExpirationDate() const;
    int getQuantity() const;
    void setExpirationDate(string newDate);
    void setQuantity(int newQuantity);

    // Virtual function overrides
    void sell() override;
    void display(ostream& os) const override;
    void input(istream& is) override;

    // Friend functions for I/O
    friend ostream& operator<<(ostream& os, const Goods& goods);
    friend istream& operator>>(istream& is, Goods& goods);
};

#endif