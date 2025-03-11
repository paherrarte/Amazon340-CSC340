// TO DO: #include needed standard libraries and your own libraries here
#include "Vendor.h"
#include <iostream>
// TO DO: function implementations
using namespace std;  //check if needed

Vendor::Vendor(string user, string mail, string pass, string bio, string pic)
	: username(user), email(mail), password(pass), bio(bio), profilePicture(pic){}

void Vendor::displayProfile() const{
	cout << "Vendor: " << username << ", Email: " << email << ", Bio: " << bio << endl;
}

void Vendor::modifyPassword(const string& newPassword){
	password = newPassword;
	cout << "Password updated succesfully." << endl;
}

void Vendor::addProduct(Product* product){
	products.add(product);
	cout << "Product added successfully: " << product->getName() << endl;
}

void Vendor::deleteProduct(int index){
	if(index < 0 || index >= products.getCurrentSize()){
		cout << "Invalid index! Available products: " << products.getCurrentSize() << endl;
		return;
	}

    Node<Product*>* productNode = products.findKthItem(index);
    if (productNode) {
        Product* product = productNode->getItem();
        products.remove(product);
        delete product;
        cout << "Product deleted successfully." << endl;
    }
}

void Vendor::modifyProduct(int index, string name, string description){
	if(index < 0 || index >= products.getCurrentSize()){
		cout << "Invalid index! Available products: " << products.getCurrentSize() << endl;
		return;
	}

    Node<Product*>* productNode = products.findKthItem(index);
    if (productNode) {
        Product* product = productNode->getItem();
        product->setName(name);
        product->setDescription(description);
        cout << "Product modified successfully." << endl;
    }
}

void Vendor::sellProduct(int index){
	if(index < 0 || index >= products.getCurrentSize()){
        cout << "Invalid index! Available products: " << products.getCurrentSize() << endl;
        return;
	}

    Node<Product*>* productNode = products.findKthItem(index);
    if (productNode) {
        productNode->getItem()->sell();
    }
}

void Vendor::displayAllProducts() const {
	if(products.isEmpty()){
		cout << "No products available." << endl;
		return;
	}

	vector<Product*> productList = products.toVector();
	cout << "Vendor's Products:\n";
	for(size_t i=0; i < productList.size(); i++){
        cout << i + 1 << ". " << productList[i]->getName() << " - " << productList[i]->getDescription() << endl;
	}
}

void Vendor::displayKthProduct(int index) const{
    if (index < 0 || index >= products.getCurrentSize()) {
        cout << "Invalid index! Available products: " << products.getCurrentSize() << endl;
        return;
    }
    
    Node<Product*>* productNode = products.findKthItem(index);
    if (productNode) {
        Product* product = productNode->getItem();
        cout << "Product Details: " << product->getName() << " - " << product->getDescription() << endl;
    }
}

// Operator == overloading implementation
bool Vendor::operator==(const Vendor& otherVendor) const {
	return (username == otherVendor.username) && (email == otherVendor.email);
}


