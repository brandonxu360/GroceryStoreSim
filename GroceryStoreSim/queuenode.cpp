/*
* Name: Brandon Xu
* Project: GroceryStoreSim
* File: main.cpp
* Date: 3/6/23
* Description: Source file for the QueueNode class, which will be the individual nodes within the queue
*/

#include "queuenode.hpp"

// Default constructor
QueueNode::QueueNode() {
	mPData = new Data(); // Allocate space for a default data object (fields are 0)
	mPNext = nullptr;
	mPGroceryList = new LinkedList(); // Allocate space for LinkedList object
}

// Constructor for provided pointers to Data object and grocery list LinkedList
QueueNode::QueueNode(Data* data, LinkedList* gList) {
	mPData = data; // Set pointer to Data object to the given pointer
	mPNext = nullptr;
	mPGroceryList = gList; // Set pointer to the LinkedList given
}

// Getters
Data* QueueNode::getPData() {
	return mPData;
}
QueueNode* QueueNode::getPNext() {
	return mPNext;
}
LinkedList* QueueNode::getItemList() {
	return mPGroceryList;
}

// Setters
void QueueNode::setPNext(QueueNode* next) {
	mPNext = next;
}

