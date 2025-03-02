// TO DO: #include all the standard libraries and your own libraries here
#ifndef VENDOR_H
#define VENDOR_H

#include <iostream>
#include <string>
#include "LinkedBag.h"
#include "Product.h"

// To DO: define the class Vendor with the necessary functions and data fields
using namespace std;

class Vendor {
private:
    string username;
    string email;
    string password;
    string bio;
    string profilePicture;
    LinkedBag<Product*> products; // Stores vendor’s products
public:
    // Constructor
    Vendor(string user, string mail, string pass, string bio, string pic)
        : username(user), email(mail), password(pass), bio(bio), profilePicture(pic) {}

    // Display vendor profile
    void displayProfile()const;

    // Product management
    void addProduct(Product* product);
    void deleteProduct(int index);
    void modifyProduct(int index, string name, string desc);
    void sellProduct(int index);

// This is a function that allows you to compare two vendors based on their username and email address.  
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator == overloading function prototype:
    bool operator==(const Vendor& otherVendor) const;

    string getUsername() const { return username; }
    string getEmail() const { return email; }
};

#endif
