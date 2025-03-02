// TO DO: Implementation of Amazon340 functions
#include <iostream>
#include <string>
#include "Amazon340.h"

// TO DO: implement constructor
Amazon340::Amazon340() : vendor("", "", "", "", ""){} // You can initialize the vendor object if needed.


}
// TO DO: implement destructor
Amazon340::~Amazon340() { // If any dynamic memory allocation was used, deallocate here.


}
void Amazon340::createVendor(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture){
	// TO DO: implement function
	vendor = Vendor(username, email, password, bio, profilePicture);
}

Vendor Amazon340::getVendor() const{
	// TO DO: implement function\
	return vendor;
}
