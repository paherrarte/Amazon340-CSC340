// TO DO: #include all the standard libraries and your own libraries here
#include <iostream>
#include <string>
// To DO: define the class Product with the necessary functions' prototypes and data fields
#ifndef PRODUCT_H
#define PRODUCT_H
// This is a function that allows you to compare two products based on their name. 
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator overloading function prototype:
using namespace std;

class Product{
    string name;
    string description;
    double rating; 
    int timesSold;

    public:
    Product(string name, string description, double rating);

    virtual ~Product(){}

    //Getters
    string getName() const;
    string getDescription() const;
    double getRating() const;
    int getTimesSold() const;

    //setters
    void setName(string newName);
    void setDescription(string newDescription);
    void setRating(double newRating);

    //sell function
    virtual void sell() = 0;

    //operator overload
    bool operator==(const Product& otherProduct) const; 

};

#endif 

