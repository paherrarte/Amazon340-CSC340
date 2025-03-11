// TO DO: Implementation of Amazon340 functions
#include <iostream>
#include <string>
#include "Amazon340.h"

// TO DO: implement constructor
Amazon340::Amazon340() : vendor("", "", "", "", "") {}


void Amazon340::createVendor(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture){
	// TO DO: implement function
	vendor = Vendor(username, email, password, bio, profilePicture);
	cout << "Vendor profile created successfully!" << endl;
}

Vendor& Amazon340::getVendor() {
	// TO DO: implement function
	return vendor;
}