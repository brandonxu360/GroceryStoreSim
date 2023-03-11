/*
* Name: Brandon Xu
* Project: GroceryStoreSim
* File: linkedlist.hpp
* Date: 3/6/23
* Description: Source file for the LinkedList class, which will hold the LinkedListNode objects that represent grovery items
*/

#include "linkedlist.hpp"

// Default constructor
LinkedList::LinkedList() {
	//initialize list to empty
	mPHead = nullptr;
	mPTail = nullptr;
	mSize = 0;
}

// Constructor for random linked list containing items from inputted string array (random size and items)
LinkedList::LinkedList(std::string (&itemArray)[25], int maxSize) {
	//initialize list to empty
	mPHead = nullptr;
	mPTail = nullptr;
	mSize = 0;

	int size = rand() % maxSize + 1; // Random size from 1 to the inputted maxSize

	for (int i = 0; i < size; i++) { // Loop until list is of the random size 
		this->insertAtEnd(itemArray[rand() % itemArray->length()]); // Insert node containing random item from itemArray
	}
}

// Destructor (deletes all nodes)
LinkedList::~LinkedList() {
	LinkedListNode* curr = mPHead; // Create iterator and set it to head

	while (curr != nullptr) { // Iterate through entire list
		LinkedListNode* next = curr->getPNext(); // Store next node before deleting current node

		std::cout << "Deleting " << curr->getItem() << " node" << std::endl;
		delete curr; // Delete the current node

		curr = next; // Move onto next node
	}
}

// Getters
int LinkedList::getSize() {
	return mSize;
}
LinkedListNode* LinkedList::getPHead() {
	return mPHead;
}
LinkedListNode* LinkedList::getPTail() {
	return mPTail;
}

// Insert a node containing newItem at the end of the list
bool LinkedList::insertAtEnd(std::string newItem) {
	bool success = false;

	// Allocate space for and initialize new node with newItem value
	LinkedListNode* newNode = new LinkedListNode(newItem);

	if (newNode != nullptr) { // Check if memory was successfully allocated
		success = true;

		if (mPHead == nullptr) { // Empty list
			mPHead = mPTail = newNode;
		}

		else { // Nonempty list
			mPTail->setPNext(newNode); // Set current last node to point to newNode
			mPTail = newNode; // Set tail to newNode

		}

		mSize++;
	}

	return success;
}

// Overloaded stream insertion operator for displaying the contents of a LinkedList
std::ostream& operator<<(std::ostream& os, LinkedList& list) {
	LinkedListNode* curr = list.getPHead(); // Iterator

	os << "["; // Start of list bracket
	while (curr != list.getPTail()) { // Iterate through entire list
		os << curr->getItem() << ", ";
		curr = curr->getPNext();
	}
	os << curr->getItem() << "]" << std::endl << std::endl; // Print last time and close the list bracket

	return os;
}