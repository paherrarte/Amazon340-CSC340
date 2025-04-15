// TO DO: #include needed standard libraries and your own libraries here
#include "Vendor.h"
#include <iostream>
#include <memory>
// TO DO: function implementations
using namespace std;  //check if needed

Vendor::Vendor(string user, string mail, string pass, string bio, string pic)
	: username(user), email(mail), password(pass), bio(bio), profilePicture(pic){}

// BIG 3 Implementation
Vendor::~Vendor() {
	// No need to manually delete products as shared_ptr handles memory management
}

Vendor::Vendor(const Vendor& other)
	: username(other.username), email(other.email), password(other.password),
	  bio(other.bio), profilePicture(other.profilePicture) {
	// Copy products using shared_ptr
	vector<shared_ptr<Product>> productList = other.products.toVector();
	for (const auto& product : productList) {
		products.add(product);
	}
}

Vendor& Vendor::operator=(const Vendor& other) {
	if (this != &other) {
		username = other.username;
		email = other.email;
		password = other.password;
		bio = other.bio;
		profilePicture = other.profilePicture;
		
		// Clear existing products
		while (!products.isEmpty()) {
			products.remove(products.findKthItem(0)->getItem());
		}
		
		// Copy products
		vector<shared_ptr<Product>> productList = other.products.toVector();
		for (const auto& product : productList) {
			products.add(product);
		}
	}
	return *this;
}

void Vendor::displayProfile() const{
	cout << "Vendor: " << username << ", Email: " << email << ", Bio: " << bio << endl;
}

void Vendor::modifyPassword(const string& newPassword){
	password = newPassword;
	cout << "Password updated successfully." << endl;
}

void Vendor::addProduct(shared_ptr<Product> product){
	products.add(product);
	cout << "Product added successfully: " << product->getName() << endl;
}

void Vendor::deleteProduct(int index){
	// Convert from 1-based to 0-based indexing
	index--;
	
	if(index < 0 || index >= products.getCurrentSize()){
		cout << "Invalid index! Please enter a number between 1 and " << products.getCurrentSize() << endl;
		return;
	}

	auto productNode = products.findKthItem(index);
	if (productNode) {
		auto product = productNode->getItem();
		products.remove(product);
		cout << "Product deleted successfully." << endl;
	}
}

void Vendor::modifyProduct(int index, string name, string description, double price) {
	// Convert from 1-based to 0-based indexing
	index--;
	
	if(index < 0 || index >= products.getCurrentSize()){
		cout << "Invalid index! Please enter a number between 1 and " << products.getCurrentSize() << endl;
		return;
	}

	auto productNode = products.findKthItem(index);
	if (productNode) {
		auto product = productNode->getItem();
		product->setName(name);
		product->setDescription(description);
		product->setPrice(price);
		cout << "Product modified successfully." << endl;
	}
}

void Vendor::sellProduct(int index){
	// Convert from 1-based to 0-based indexing
	index--;
	
	if(index < 0 || index >= products.getCurrentSize()){
		cout << "Invalid index! Please enter a number between 1 and " << products.getCurrentSize() << endl;
		return;
	}

	auto productNode = products.findKthItem(index);
	if (productNode) {
		productNode->getItem()->sell();
	}
}

void Vendor::displayAllProducts() const {
	if(products.isEmpty()){
		cout << "No products available." << endl;
		return;
	}

	vector<shared_ptr<Product>> productList = products.toVector();
	cout << "Vendor's Products:\n";
	for(size_t i=0; i < productList.size(); i++){
        cout << i + 1 << ". " << productList[i]->getName() << " - " << productList[i]->getDescription() << " - $" << productList[i]->getPrice() << endl;
	}
}

void Vendor::displayKthProduct(int index) const{
	// Convert from 1-based to 0-based indexing
	index--;
	
	if (index < 0 || index >= products.getCurrentSize()) {
		cout << "Invalid index! Please enter a number between 1 and " << products.getCurrentSize() << endl;
		return;
	}
	
	auto productNode = products.findKthItem(index);
	if (productNode) {
		auto product = productNode->getItem();
		cout << "Product Details: " << product->getName() << " - " << product->getDescription() << " - $" << product->getPrice() << endl;
	}
}

// I/O Operator Overloading
ostream& operator<<(ostream& os, const Vendor& vendor) {
	os << "Vendor Profile:\n"
	   << "Username: " << vendor.username << "\n"
	   << "Email: " << vendor.email << "\n"
	   << "Bio: " << vendor.bio << "\n"
	   << "Profile Picture: " << vendor.profilePicture << "\n"
	   << "Number of Products: " << vendor.products.getCurrentSize() << "\n";
	return os;
}

istream& operator>>(istream& is, Vendor& vendor) {
	if (&is == &cin) {
		cout << "Enter Vendor Information:\n";
		cout << "Username: ";
	}
	getline(is, vendor.username);
	
	if (&is == &cin) {
		cout << "Email: ";
	}
	getline(is, vendor.email);
	
	if (&is == &cin) {
		cout << "Password: ";
	}
	getline(is, vendor.password);
	
	if (&is == &cin) {
		cout << "Bio: ";
	}
	getline(is, vendor.bio);
	
	if (&is == &cin) {
		cout << "Profile Picture: ";
	}
	getline(is, vendor.profilePicture);
	return is;
}

bool Vendor::operator==(const Vendor& otherVendor) const {
	return (username == otherVendor.username) && (email == otherVendor.email);
}


