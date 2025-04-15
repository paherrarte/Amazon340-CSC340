// TO DO: #include all the standard libraries and your own libraries here
#include <iostream>
#include <string>
// To DO: define the class Product with the necessary functions' prototypes and data fields
#ifndef PRODUCT_H
#define PRODUCT_H
using namespace std;

class Product{
    protected:
    string name;
    string description;
    double rating; 
    int timesSold;
    double price;

    public:
    // Constructor
    Product(string name, string description, double rating, double price);

    // BIG 3
    virtual ~Product() = default;
    Product(const Product& other) = default;
    Product& operator=(const Product& other) = default;

    //Getters
    string getName() const;
    string getDescription() const;
    double getRating() const;
    int getTimesSold() const;
    double getPrice() const;

    //setters
    void setName(string newName);
    void setDescription(string newDescription);
    void setRating(double newRating);
    void setPrice(double newPrice);

    //sell function
    virtual void sell() = 0;

    // Virtual functions
    virtual void display(ostream& os) const = 0;
    virtual void input(istream& is) = 0;

    // Friend functions for I/O
    friend ostream& operator<<(ostream& os, const Product& product);
    friend istream& operator>>(istream& is, Product& product);

    //operator overload
    bool operator==(const Product& otherProduct) const; 

};

#endif 

