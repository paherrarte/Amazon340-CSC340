// TO DO: #include needed standard libraries and your own libraries here
#include "Vendor.h"
#include <iostream>
// TO DO: function implementations
using namespace std;  //check if needed

// Display vendor profile
void Vendor::displayProfile() const {
	cout << "Vendor: " << username << ", Email: " << email << "Bio: " << bio << endl;
}

// Modify vendor password
void Vendor::modifyPassword(string newPassword) {
	password = newPassword;
	cout << "Password updated successfully" << endl;
}

// Add a product to the vendor's product list
void Vendor::addProduct(Product* product) {
	products.add(product);
	cout << "Product added successfully" << endl;
}

// Delete a product from the vendor's product list
void Vendor::deleteProduct(int index) {
    if (index < products.getCurrentSize()) {
    	products.remove(products.findKthItem(index));
    	cout << "Product deleted successfully" << endl;
	} else {
		cout << "Error: Invalid index. The maximum index is " << products.getCurrentSize() << endl;
	}
}

// Modify a product's name and description
void Vendor::modifyProduct(int index, string name, string description) {
	if (index < products.getCurrentSize()) {
		Product* product = products.findKthItem(index);
		product->setName(name);
		product->setDescription(description);
		cout << "Product modified successfully" << endl;
	} else {
		cout << "Invalid index! Available products: " << products.getCurrentSize() << endl;
	}
}

// Sell a product by calling its `sell` function
void Vendor::sellProduct(int index) {
	if (index < products.getCurrentSize()) {
		products.findKthItem(index)->sell();
		cout << "Product sold successfully" << endl;
	} else {
		cout << "Invalid index! Available products: " << products.getCurrentSize() << endl;
	}
}
// Operator == overloading implementation
bool Vendor::operator==(const Vendor& otherVendor) const {
	return (username == otherVendor.username) && (email == otherVendor.email);

}
