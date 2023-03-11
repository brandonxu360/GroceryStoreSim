/*
* Name: Brandon Xu
* Project: GroceryStoreSim
* File: linkedlist.hpp
* Date: 3/6/23
* Description: Header file for the LinkedList class, which will hold the LinkedListNode objects that represent grovery items
*/

#pragma once

#include "header.hpp"
#include "linkedlistnode.hpp"

class LinkedList {

public:

	LinkedList(); // Default constructor

	LinkedList(std::string (& itemArray)[25], int maxSize); // Constructor for random linked list containing items from inputted string array (random size and items)

	~LinkedList(); // Destructor (deletes all nodes)

	// Getters
	int getSize(); // Return number of nodes in the list
	LinkedListNode* getPHead();
	LinkedListNode* getPTail();

	// List operations
	bool insertAtEnd(std::string newItem); // Insert a node containing newItem at the end of the list

private:

	LinkedListNode* mPHead;
	LinkedListNode* mPTail;
	int mSize; // Number of nodes in the list

};

std::ostream& operator<<(std::ostream& os, LinkedList& list);