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
	std::string getItem();

private:

	std::string mItem;
	LinkedListNode* mPNext;
};