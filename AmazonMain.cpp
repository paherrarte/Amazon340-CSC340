#include <iostream> 
#include <string>

// TO DO: #include any other libraries you need
#include "Amazon340.h"
#include "Vendor.h"
#include "Product.h"
#include "LinkedBag.h"




using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type Vendor
 * @param vendor object to interact with
 * 
 * */
void displayVendorMenu(Vendor& vendor){
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

		switch (vendorChoice) {
			case 1:{
				// TO DO: display vendor's profile information
                vendor.displayProfile();
				//      : e.g. vendor.displayProfile();
				break;
			}
			case 2: {
				// TO DO: ask for new password and update vendor's password
				string newPassword;
				cout << "Enter new password: ";
				cin >> newPassword;
				vendor.setPassword(newPassword);
				cout << "New password set successfully.\n";
				break;
			}
			case 3: {
				// TO DO: ask vendor to choose product type, then ask them to input product details.
				// Create the product and add it to the vendor's products
				string name, description;
				double rating;
				cout << "Enter product name: ";
				cin.ignore();
				getline(cin, name);
				cout << "Enter product description: ";
				getline(cin, description);
				cout << "Enter product's rating: ";
				cin >> rating;

				Product newProduct(name, description, rating);
				vendor.addProduct(newProduct);

				cout << "Product added successfully.\n";
				break;
			}
			case 4:{
				// TO DO: display all vendor's products
				//        You may re-use code from class demo
				vendor.displayAllProducts();
				break;
			}
			case 5: {
				// TO DO: ask the vendor for a value k
				// Find the Kth product, if k > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				int k;
				cout << "Enter product index: ";
				cin >> k;
				if (k < vendor.getProductCount()) {
					vendor.displayKthProduct(k);
				} else {
					cout << "Error: Index not in range. Max: " << vendor.getProductCount() - 1 << endl;
				}
				break;
			}
			case 6: {
				// TO DO: ask the vendor for the index of the product they want to modify.
				// Find the product, then prompt them for the new name and description.
				// Modify the product accordingly. 
				// If index > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				int index;
				string newName, newDesc;
				cout << "Enter product index to modify: ";
				cin >> index;
				cin.ignore();

				if (index < vendor.getProductCount()) {
					cout << "Enter new product name: ";
					getline(cin, newName);
					cout << "Enter new product description: ";
					getline(cin, newDesc);

					vendor.modifyProduct(index, newName, newDesc);
					cout << "Product modified successfully.\n";
				} else {
					cout << "Error: Index out of range. Max: " << vendor.getProductCount() - 1 << endl;
				}
				break;
			}
			case 7: {
				// TO DO: ask the vendor for the index of the product they want to sell 
				// Find the product, then sell the product. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
				int index;
				cout << "Enter product index you want to sell: ";
				cin >> index;

				if (index < vendor.getProductCount()) {
					vendor.sellProduct(index);
					cout << "Product sold successfully.\n";
				} else {
					cout << "Error: Index not in range.\n";
				}
				break;
			}
			case 8:{
				// TO DO: ask the vendor for the index of the product they want to delete 
				// Find the product, then remove it from the list. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
				int index;
				cout << "Enter product index to delete: ";
				cin >> index;

				if (index < vendor.getProductCount()) {
					vendor.deleteProduct(index);
					cout << "Product removed successfully.\n";
				} else {
					cout << "Error: Index not in range.\n";
				}
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


int main(){
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one vendor
	Amazon340 amazon340; 

	cout << "\n Welcome to Amazon340:" << endl;
	// TO DO: Ask the vendor to enter their information 
	//        Instantiate a new Vendor object
	string username, email, password;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter email: ";
	cin >> email;
	cout << "Enter password: ";
	cin >> password;


	// call amazon340 createVendor function 
	// replace /*...*/ with the right parameters
	amazon340.createVendor(username, email, password);

	// Retrieve the vendor 
	Vendor currentVendor = amazon340.getVendor();

	// Display the main menu
	displayVendorMenu(currentVendor);
				
	return 0;
}