#include <iostream> 
#include <string>

// TO DO: #include any other libraries you need
#include "Amazon340.h"


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
				//      : e.g. vendor.displayProfile();
				vendor.displayProfile();
				break;
			}
			case 2: {
				// TO DO: ask for new password and update vendor's password
				string newPass;
				cout << "Enter New Password: ";
				cin >> newPass;
				vendor.modifyPassword(newPass);
				break;
			}
			case 3: {
				// TO DO: ask vendor to choose product type, then ask them to input product details.
				// Create the product and add it to the vendor's products
				int productType;
				string name, description;
				double rating;

				cout << "Enter Product Type:\n1. Goods\n2. Media\nChoice: ";
				cin >> productType;
				cin.ignore();
				
				cout << "Enter Product Name: ";
				getline(cin, name);

				cout << "Enter Product Description: ";
				getline(cin, description);

				cout << "Enter Product Rating (0-5): ";
				cin >> rating;
				cin.ignore();

				if(productType == 1){
					string expirationDate;
					int quantity;
					cout << "Enter Expiration Date: ";
					getline(cin, expirationDate);
					cout << "Enter Quantity: ";
					cin >> quantity;

					vendor.addProduct(new Goods(name, description, rating, expirationDate, quantity));
				} else if(productType == 2){
					string type, targetAudience;
					cout << "Enter media type (e.g., Movie, Book, Music): ";
                    getline(cin, type);
                    cout << "Enter target audience: ";
                    getline(cin, targetAudience);

					vendor.addProduct(new Media(name, description, rating, type, targetAudience));
				} else{
					cout << "Invalid Product Type!" << endl;
				}
				
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
				cout << "Enter Product Index: ";
				cin >> k;
				vendor.displayKthProduct(k);
				break;
			}
			case 6: {
				// TO DO: ask the vendor for the index of the product they want to modify.
				// Find the product, then prompt them for the new name and description.
				// Modify the product accordingly. 
				// If index > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
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
				// TO DO: ask the vendor for the index of the product they want to sell 
				// Find the product, then sell the product. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
				int index;
				cout << "Enter Product Index to Sell: ";
				cin >> index; 
				vendor.sellProduct(index);
				break;
			}
			case 8:{
				// TO DO: ask the vendor for the index of the product they want to delete 
				// Find the product, then remove it from the list. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
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


int main(){
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one vendor
	Amazon340 amazon340; 

	cout << "\n Welcome to Amazon340:" << endl;
	// TO DO: Ask the vendor to enter their information 
	//        Instantiate a new Vendor object
	string username, email, password, bio, profilePicture;
	cout << "Enter Username: ";
	getline(cin, username);
	cout << "Enter Email: ";
	getline(cin, email);
	cout << "Enter Password: ";
	getline(cin, password);
	cout << "Enter Bio: ";
	getline(cin, bio);
	cout << "Enter Profile Picture Path: ";
	getline(cin, profilePicture);

	// call amazon340 createVendor function 
	// replace /*...*/ with the right parameters
	amazon340.createVendor(username, email, password, bio, profilePicture);

	// Retrieve the vendor 
	Vendor currentVendor = amazon340.getVendor();

	// Display the main menu
	displayVendorMenu(currentVendor);
				
	return 0;
}