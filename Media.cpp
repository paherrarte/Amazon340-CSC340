#include "Media.h"
#include <iostream>
using namespace std;

Media::Media(string name, string description, double rating, double price, string type, string targetAudience)
    : Product(name, description, rating, price), type(type), targetAudience(targetAudience) {}

// Getters
string Media::getType() const { return type; }
string Media::getTargetAudience() const { return targetAudience; }

// Setters
void Media::setType(string newType) { type = newType; }
void Media::setTargetAudience(string newTargetAudience) { targetAudience = newTargetAudience; }

// Sell function override
void Media::sell() {
    timesSold++;
    cout << "Sold media: " << name << " - Access Code: " << rand() % 10000 << endl;
}

// Display function
void Media::display(ostream& os) const {
    os << "Media: " << name << "\n"
       << "Description: " << description << "\n"
       << "Rating: " << rating << "\n"
       << "Price: $" << price << "\n"
       << "Type: " << type << "\n"
       << "Target Audience: " << targetAudience << "\n"
       << "Times Sold: " << timesSold;
}

// Input function
void Media::input(istream& is) {
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
        cout << "Enter media type: ";
    }
    getline(is, type);
    
    if (&is == &cin) {
        cout << "Enter target audience: ";
    }
    getline(is, targetAudience);
}

ostream& operator<<(ostream& os, const Media& media) {
    os << "Media Details:\n"
       << "Name: " << media.getName() << "\n"
       << "Description: " << media.getDescription() << "\n"
       << "Rating: " << media.getRating() << "\n"
       << "Price: $" << media.getPrice() << "\n"
       << "Times Sold: " << media.getTimesSold() << "\n"
       << "Type: " << media.getType() << "\n"
       << "Target Audience: " << media.getTargetAudience() << "\n";
    return os;
}

istream& operator>>(istream& is, Media& media) {
    string name, description, type, targetAudience;
    double rating, price;

    cout << "Enter Media Information:\n";
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
    cout << "Type: ";
    getline(is, type);
    cout << "Target Audience: ";
    getline(is, targetAudience);

    media.setName(name);
    media.setDescription(description);
    media.setRating(rating);
    media.setPrice(price);
    media.setType(type);
    media.setTargetAudience(targetAudience);

    return is;
}

