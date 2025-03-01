// TO DO: #include needed standard libraries and your own libraries here
#include "Vendor.h"
#include <iostream>
// TO DO: function implementations
using namespace std;

// Display vendor profile
void Vendor::displayProfile() {
	cout << "Vendor: " << username << ", Email: " << email << endl;
}

// Add a product to the vendor's product list
void Vendor::addProduct(Product* product) {
	products.add(product);
}

// Delete a product from the vendor's product list
void Vendor::deleteProduct(int index) {
	if (index >= 0 && index < products.getCurrentSize()) {
		products.remove(products.toVector()[index]);
	} else {
		cout << "Error: Invalid index. The maximum index is " << products.getCurrentSize() - 1 << endl;
	}
}

// Modify a product's name and description
void Vendor::modifyProduct(int index, string name, string desc) {
	if (index >= 0 && index < products.getCurrentSize()) {
		vector<Product*> productList = products.toVector();
		productList[index]->setName(name);
		productList[index]->setDescription(desc);
	} else {
		cout << "Error: Invalid index. The maximum index is " << products.getCurrentSize() - 1 << endl;
	}
}

// Sell a product by calling its `sell` function
void Vendor::sellProduct(int index) {
	if (index >= 0 && index < products.getCurrentSize()) {
		vector<Product*> productList = products.toVector();
		productList[index]->sell();
	} else {
		cout << "Error: Invalid index. The maximum index is " << products.getCurrentSize() - 1 << endl;
	}
}
// Operator == overloading implementation
bool Vendor::operator==(const Vendor& otherVendor) const {
	return (Vendor::username == otherVendor.username) && (Vendor::email == otherVendor.email);
}
