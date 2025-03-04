#include "Media.h"
#include<iostream>

Media::Media(string name, string description, double rating, string type, string targetAudience)
    : Product(name, description, rating), type(type), targetAudience(targetAudience){}

//Getters
string Media::getType() const {return type;}
string Media::getTargetAudience() const {return targetAudience;}

//Setters
void Media::setType(string newType) {type = newType;}
void Media::setTargetAudience(string newTargetAudience){targetAudience = newTargetAudience;}

//Sell function override
void Media::sell(){
    timesSold++;
    cout << "Sold media: " << name << " - Access Code: " << rand() % 10000 << endl;
}

