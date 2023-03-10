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

QueueNode::~QueueNode() {
	delete mPData; // Free memory for Data object
	delete mPGroceryList; // Free memory for grocery list LinkedList object
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

// Function to display a single customer in an ascii box (NOT CURRENTLY USED)
void QueueNode::displayNode() {
	std::cout << "+------------------+" << std::endl;
	std::cout << "| Customer #" << std::setw(2) << mPData->getCustomerNum() << "     |" << std::endl;
	std::cout << "| Service Time: " << std::setw(2) << mPData->getServiceTime() << "m |" << std::endl;
	std::cout << "| # of Items:   " << std::setw(2) << mPGroceryList->getSize() << "  |" << std::endl;
	std::cout << "+------------------+" << std::endl;
}