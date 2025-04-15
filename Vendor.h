// TO DO: #include all the standard libraries and your own libraries here
#ifndef VENDOR_H
#define VENDOR_H

#include <iostream>
#include <string>
#include <memory>
#include "Product.h"
#include "Goods.h"
#include "Media.h"
#include "LinkedBagDS/LinkedBag.h"

// To DO: define the class Vendor with the necessary functions and data fields
using namespace std;

class Vendor {
private:
    string username;
    string email;
    string password;
    string bio;
    string profilePicture;
    LinkedBag<shared_ptr<Product>> products; // Using smart pointers instead of raw pointers

public:
    // Constructor
    Vendor(string user, string mail, string pass, string bio, string pic);
    
    // BIG 3
    ~Vendor(); // Destructor
    Vendor(const Vendor& other); // Copy constructor
    Vendor& operator=(const Vendor& other); // Assignment operator

    // Display vendor profile
    void displayProfile() const;
    void modifyPassword(const string& newPassword);

    // Product management
    void addProduct(shared_ptr<Product> product);
    void deleteProduct(int index);
    void modifyProduct(int index, string name, string desc, double price);
    void sellProduct(int index);

    //Display products
    void displayAllProducts() const;
    void displayKthProduct(int index) const;

    //Getters
    string getUsername() const { return username; }
    string getEmail() const { return email; }
    string getPassword() const { return password; }
    string getBio() const { return bio; }
    string getProfilePicture() const { return profilePicture; }
    int getProductCount() const { return products.getCurrentSize(); }

    // Friend functions for I/O
    friend ostream& operator<<(ostream& os, const Vendor& vendor);
    friend istream& operator>>(istream& is, Vendor& vendor);

    // Operator == overloading
    bool operator==(const Vendor& otherVendor) const;
};

#endif
