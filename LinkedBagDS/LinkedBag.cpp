//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
	 @file LinkedBag.cpp */

#include "LinkedBag.h"
#include <cstddef>
#include <memory>

// Assignment 2 functions -------------------------------------------
template<class ItemType>
bool LinkedBag<ItemType>::appendK(const ItemType& newEntry, const int& k) {
    if (k <= 0 || headPtr == nullptr) {
        return add(newEntry);
    }
    Node<ItemType>* prevPtr = nullptr;
    Node<ItemType>* curPtr = headPtr;
    int index = 0;
    while (curPtr != nullptr && index < k) {
        prevPtr = curPtr;
        curPtr = curPtr->getNext();
        index++;
    }
    Node<ItemType>* newNode = new Node<ItemType>(newEntry, curPtr);
    if (prevPtr != nullptr) {
        prevPtr->setNext(newNode);
    } else {
        headPtr = newNode;
    }
    itemCount++;
    return true;
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::reverseFindKthItem(const int& k) {
    if (k <= 0 || k > itemCount) {
        return nullptr;
    }
    Node<ItemType>* leadPtr = headPtr;
    Node<ItemType>* followPtr = headPtr;
    for (int i = 0; i < k; i++) {
        if (leadPtr == nullptr) return nullptr;
        leadPtr = leadPtr->getNext();
    }
    while (leadPtr != nullptr) {
        leadPtr = leadPtr->getNext();
        followPtr = followPtr->getNext();
    }
    return followPtr;
}

template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::findKthItem(const int& k) const {
    if (k < 0 || k >= itemCount) {
        return nullptr;
    }
    Node<ItemType>* curPtr = headPtr;
    for (int i = 0; i < k && curPtr != nullptr; i++) {
        curPtr = curPtr->getNext();
    }
    return curPtr;
}

// ------------------------------------------------------------------

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0) {}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag) {
    itemCount = aBag.itemCount;
    Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
    
    if (origChainPtr == nullptr)
        headPtr = nullptr;  // Original bag is empty
    else {
        // Copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());
        
        // Copy remaining nodes
        Node<ItemType>* newChainPtr = headPtr;		// Points to last node in new chain
        origChainPtr = origChainPtr->getNext();	  // Advance original-chain pointer
        
        while (origChainPtr != nullptr) {
            // Get next item from original chain
            ItemType nextItem = origChainPtr->getItem();
            
            // Create a new node containing the next item
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
            
            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);
            
            // Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();

            // Advance original-chain pointer
            origChainPtr = origChainPtr->getNext();
        }  // end while
        
        newChainPtr->setNext(nullptr);				  // Flag end of chain
    }  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag() {
    clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
    return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
    return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry) {
    // Add to beginning of chain: new node references rest of chain;
    // (headPtr is null if chain is empty)		  
    Node<ItemType>* nextNodePtr = new Node<ItemType>();
    nextNodePtr->setItem(newEntry);
    nextNodePtr->setNext(headPtr);  // New node points to chain
    headPtr = nextNodePtr;			// New node is now first node
    itemCount++;
    
    return true;
}  // end add

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const {
    std::vector<ItemType> bagContents;
    Node<ItemType>* curPtr = headPtr;
    int counter = 0;
    while ((curPtr != nullptr) && (counter < itemCount)) {
        bagContents.push_back(curPtr->getItem());
        curPtr = curPtr->getNext();
        counter++;
    }  // end while
    
    return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry) {
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
    if (canRemoveItem) {
        // Copy data from first node to located node
        entryNodePtr->setItem(headPtr->getItem());
        
        // Delete first node
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();
        
        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        
        itemCount--;
    } // end if
    
    return canRemoveItem;
}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear() {
    Node<ItemType>* nodeToDeletePtr = headPtr;
    while (headPtr != nullptr) {
        headPtr = headPtr->getNext();

        // Return node to the system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        
        nodeToDeletePtr = headPtr;
    }  // end while
    // headPtr is nullptr; nodeToDeletePtr is nullptr
    
    itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
    int frequency = 0;
    int counter = 0;
    Node<ItemType>* curPtr = headPtr;
    while ((curPtr != nullptr) && (counter < itemCount)) {
        if (anEntry == curPtr->getItem()) {
            frequency++;
        } // end if
        
        counter++;
        curPtr = curPtr->getNext();
    } // end while
    
    return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const {
    return (getPointerTo(anEntry) != nullptr);
}  // end contains

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const {
    bool found = false;
    Node<ItemType>* curPtr = headPtr;
    
    while (!found && (curPtr != nullptr)) {
        if (anEntry == curPtr->getItem())
            found = true;
        else
            curPtr = curPtr->getNext();
    } // end while
    
    return curPtr;
} // end getPointerTo

template<class ItemType>
LinkedBag<ItemType>& LinkedBag<ItemType>::operator=(const LinkedBag<ItemType>& aBag) {
    if (this != &aBag) {
        clear();  // Remove current contents

        // Copy item count
        itemCount = aBag.itemCount;

        // Copy linked list nodes
        if (aBag.headPtr == nullptr) {
            headPtr = nullptr;
        } else {
            // Copy first node
            headPtr = new Node<ItemType>();
            headPtr->setItem(aBag.headPtr->getItem());

            // Traverse both lists
            Node<ItemType>* newChainPtr = headPtr;
            Node<ItemType>* origChainPtr = aBag.headPtr->getNext();

            while (origChainPtr != nullptr) {
                ItemType nextItem = origChainPtr->getItem();
                Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
                newChainPtr->setNext(newNodePtr);

                newChainPtr = newChainPtr->getNext();
                origChainPtr = origChainPtr->getNext();
            }
            newChainPtr->setNext(nullptr);
        }
    }
    return *this;
}


// Template instantiations
template class LinkedBag<std::shared_ptr<Product>>;

     