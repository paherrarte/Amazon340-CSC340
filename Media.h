#ifndef MEDIA_H
#define MEDIA_H

#include "Product.h"
#include <iostream>
using namespace std;

class Media : public Product {
private:
    string type;
    string targetAudience;

public:
    // Constructor
    Media(string name, string description, double rating, string type, string targetAudience);

    // BIG 3
    ~Media() override = default;
    Media(const Media& other) = default;
    Media& operator=(const Media& other) = default;

    // Getters and Setters
    string getType() const;
    string getTargetAudience() const;
    void setType(string newType);
    void setTargetAudience(string newAudience);

    // Virtual function overrides
    void sell() override;
    void display(ostream& os) const override;
    void input(istream& is) override;

    // Friend functions for I/O
    friend ostream& operator<<(ostream& os, const Media& media);
    friend istream& operator>>(istream& is, Media& media);
};

#endif