#ifndef MEDIA_H
#define MEDIA_H

#include "Product.h"

class Media : public Product{
private:
    string type;
    string targetAudience;

public:
    //constructor
    Media(string name, string description, double rating, string type, string targetAudience);

    // Getter and setter
    string getType() const;
    string getTargetAudience() const;
    void setType(string newType);
    void setTargetAudience(string newAudience);

    //sell function (override)
    void sell() override;
};

#endif