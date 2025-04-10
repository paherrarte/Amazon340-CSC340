#include "Media.h"
#include <iostream>
using namespace std;

Media::Media(string name, string description, double rating, string type, string targetAudience)
    : Product(name, description, rating), type(type), targetAudience(targetAudience) {}

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
       << "Type: " << type << "\n"
       << "Target Audience: " << targetAudience << "\n"
       << "Times Sold: " << timesSold;
}

// Input function
void Media::input(istream& is) {
    cout << "Enter product name: ";
    getline(is, name);
    cout << "Enter description: ";
    getline(is, description);
    cout << "Enter rating (0-5): ";
    is >> rating;
    is.ignore();
    cout << "Enter media type: ";
    getline(is, type);
    cout << "Enter target audience: ";
    getline(is, targetAudience);
}

