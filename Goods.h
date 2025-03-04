#ifndef GOODS_H
#define GOODS_H

#include "Product.h"

class Goods : public Product {
private:
    string expirationDate;
    int quantity; //Stock count

public:
    //Constructor
    Goods(string name, string description, double rating, string expirationDate, int quantity);

    //Getter and Setter
    string getExpirationDate() const;
    int getQuantity() const; 
    void setExpirationDate(string newDate);
    void setQuantity(int newQuantity);

    //Sell function override
    void sell() override;
};

#endif