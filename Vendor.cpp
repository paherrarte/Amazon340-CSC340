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
	if(index < 0 || index >= products.getCurrentSize()){
		cout << "Invalid index! Available products: " << products.getCurrentSize() << endl;
		return;
	}

	auto productNode = products.findKthItem(index);
	if (productNode) {
		auto product = productNode->getItem();
		products.remove(product);
		cout << "Product deleted successfully." << endl;
	}
}

void Vendor::modifyProduct(int index, string name, string description){
	if(index < 0 || index >= products.getCurrentSize()){
		cout << "Invalid index! Available products: " << products.getCurrentSize() << endl;
		return;
	}

	auto productNode = products.findKthItem(index);
	if (productNode) {
		auto product = productNode->getItem();
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
        cout << i + 1 << ". " << productList[i]->getName() << " - " << productList[i]->getDescription() << endl;
	}
}

void Vendor::displayKthProduct(int index) const{
    if (index < 0 || index >= products.getCurrentSize()) {
        cout << "Invalid index! Available products: " << products.getCurrentSize() << endl;
        return;
    }
    
    auto productNode = products.findKthItem(index);
    if (productNode) {
        auto product = productNode->getItem();
        cout << "Product Details: " << product->getName() << " - " << product->getDescription() << endl;
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
	cout << "Enter Vendor Information:\n";
	cout << "Username: ";
	getline(is, vendor.username);
	cout << "Email: ";
	getline(is, vendor.email);
	cout << "Password: ";
	getline(is, vendor.password);
	cout << "Bio: ";
	getline(is, vendor.bio);
	cout << "Profile Picture: ";
	getline(is, vendor.profilePicture);
	return is;
}

bool Vendor::operator==(const Vendor& otherVendor) const {
	return (username == otherVendor.username) && (email == otherVendor.email);
}


