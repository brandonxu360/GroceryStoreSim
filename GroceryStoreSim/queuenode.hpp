/*
* Name: Brandon Xu
* Project: GroceryStoreSim
* File: queuenode.hpp
* Date: 3/6/23
* Description: Header file for the QueueNode class, which will be the individual nodes within the queue
*/

#pragma once

#include "header.hpp"
#include "data.hpp"
#include "linkedlist.hpp"

class QueueNode {

public: // Member functions

	QueueNode(); // Default constructor

	QueueNode(Data* data, LinkedList* gList); // Constructor for provided pointer to Data object
	
	~QueueNode(); // Destructor to free dynamic memory allocated for the Data object and grocery list LinkedList object

	// Getters
	Data* getPData();
	QueueNode* getPNext();
	LinkedList* getItemList();

	// Setters
	void setPNext(QueueNode* next);

	void displayNode(); // Function to display a single customer in an ascii box (NOT CURRENTLY USED)


private:

	Data* mPData;    // The memory for Data will need to be allocated on the heap as well!
	QueueNode* mPNext;
	LinkedList* mPGroceryList;
};