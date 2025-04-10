#ifndef AMAZON340_H
#define AMAZON340_H

#include "LinkedBagDS/LinkedBag.h"
// TO DO include necessary libraries
#include <iostream>
#include <string>
#include "Vendor.h"
 
using namespace std;
// This class only contains a vendor
class Amazon340 {
	private:
		Vendor vendor;

	public:
		// Constructor
		Amazon340();

		// BIG 3
		~Amazon340() = default;
		Amazon340(const Amazon340& other) = default;
		Amazon340& operator=(const Amazon340& other) = default;

		// Member functions
		void createVendor(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture);

		Vendor& getVendor();

		// Friend function for output
		friend ostream& operator<<(ostream& os, const Amazon340& amazon);
};

#endif