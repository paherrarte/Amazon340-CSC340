#include <iostream>
#include <string>
#include <memory>
#include "Amazon340.h"
#include "Goods.h"
#include "Media.h"

using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type Vendor
 * @param vendor object to interact with
 * 
 * */
void displayVendorMenu(Vendor& vendor) {
	int vendorChoice = 0;
	do {
		cout << "\n Hi, "<< vendor.getUsername() <<", what would you like to do:\n"
		<< "1. Display Profile\n"
		<< "2. Modify Password\n"
		<< "3. Create Product\n"
		<< "4. Display All Products\n"
		<< "5. Display Kth Product\n"
		<< "6. Modify Product\n"
		<< "7. Sell Product\n"
		<< "8. Delete Product\n"
		<< "0. Logout\n"
		<< "Choice: ";
		cin >> vendorChoice;
		cin.ignore();

		switch (vendorChoice) {
			case 1: {
				cout << vendor;
				break;
			}
			case 2: {
				string newPass;
				cout << "Enter New Password: ";
				getline(cin, newPass);
				vendor.modifyPassword(newPass);
				break;
			}
			case 3: {
				int productType;
				cout << "Enter Product Type:\n1. Goods\n2. Media\nChoice: ";
				cin >> productType;
				cin.ignore();

				if (productType == 1) {
					auto goods = make_shared<Goods>("", "", 0.0, "", 0);
					cin >> *goods;
					vendor.addProduct(goods);
				} else if (productType == 2) {
					auto media = make_shared<Media>("", "", 0.0, "", "");
					cin >> *media;
					vendor.addProduct(media);
				} else {
					cout << "Invalid Product Type!" << endl;
				}
				break;
			}
			case 4: {
				vendor.displayAllProducts();
				break;
			}
			case 5: {
				int k;
				cout << "Enter Product Index: ";
				cin >> k;
				vendor.displayKthProduct(k);
				break;
			}
			case 6: {
				int index;
				string newName, newDescription;
				cout << "Enter Product Index to Modify: ";
				cin >> index;
				cin.ignore();

				cout << "Enter New Product Name: ";
				getline(cin, newName);
				cout << "Enter New Product Description: ";
				getline(cin, newDescription);

				vendor.modifyProduct(index, newName, newDescription);
				break;
			}
			case 7: {
				int index;
				cout << "Enter Product Index to Sell: ";
				cin >> index;
				vendor.sellProduct(index);
				break;
			}
			case 8: {
				int index;
				cout << "Enter Index of Product to Delete: ";
				cin >> index;
				vendor.deleteProduct(index);
				break;
			}
			case 0: {
				cout << "Logging you out." << endl;
				break;
			}
			default:
				cout << "Invalid choice. Please try again." << endl;
		}
	} while (vendorChoice != 0);
}

int main() {
	Amazon340 amazon340;
	cout << amazon340 << endl;

	Vendor currentVendor("", "", "", "", "");
	cin >> currentVendor;
	amazon340.createVendor(currentVendor.getUsername(), currentVendor.getEmail(),
						  currentVendor.getPassword(), currentVendor.getBio(),
						  currentVendor.getProfilePicture());

	currentVendor = amazon340.getVendor();
	displayVendorMenu(currentVendor);

	return 0;
}