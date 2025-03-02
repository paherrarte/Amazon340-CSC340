#include "LinkedBagDS/LinkedBag.h"
// TO DO include necessary libraries
#ifndef AMAZON340_H
#define AMAZON340_H

#include "Vendor.h"
 

// This class only contains a vendor
class Amazon340 {
	private:
		Vendor vendor;

	public:
		Amazon340();

		void createVendor(string username, string email, string password, string bio, string profilePicture);

		Vendor getVendor() const;
};

#endif
