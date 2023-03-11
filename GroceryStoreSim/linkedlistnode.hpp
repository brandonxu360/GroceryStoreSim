/*
* Name: Brandon Xu
* Project: GroceryStoreSim
* File: linkedlistnode.hpp
* Date: 3/6/23
* Description: Header file for the LinkedListNode class, which will represent grovery items
*/

#pragma once

#include "header.hpp"

class LinkedListNode {

public:

	LinkedListNode(); // Default constructor

	LinkedListNode(std::string item); // Constructor for item input

	// Setters
	void setPNext(LinkedListNode* pNewNext);

	// Getters
	LinkedListNode* getPNext();
	std::string getItem(); // Return the name of the item stored in the node

private:

	std::string mItem; // Each node represents a grocery item, so it contains the name of the item
	LinkedListNode* mPNext;
};