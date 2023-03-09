/*
* Name: Brandon Xu
* Project: GroceryStoreSim
* File: linkedlistnode.hpp
* Date: 3/6/23
* Description: Header file for the LinkedListNode class, which will represent grovery items
*/

#include "linkedlistnode.hpp"

// Default constructor
LinkedListNode::LinkedListNode() {
	mItem = "-----"; // Indicates empty field
	mPNext = nullptr;
}

// Constructor for item input
LinkedListNode::LinkedListNode(std::string item) {
	mItem = item;
	mPNext = nullptr;
}

// Setters
void LinkedListNode::setPNext(LinkedListNode* pNewNext) {
	mPNext = pNewNext;
}

// Getters
LinkedListNode* LinkedListNode::getPNext() {
	return mPNext;
}

std::string LinkedListNode::getItem() {
	return mItem;
}