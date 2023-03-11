/*
* Name: Brandon Xu
* Project: GroceryStoreSim
* File: queue.cpp
* Date: 3/6/23
* Description: Source file for the Queue class, which will organize the QueueNode objects to represent a grocery line
*/

#include "queue.hpp"

// Default constructor
Queue::Queue() {
	// Initialize list to nullptr (empty)
	mPHead = nullptr;
	mPTail = nullptr;
	mSize = 0;
}

// Destructor
Queue::~Queue() {
	// Iterate through the queue, deleting each QueueNode and its corresponding Data object
	QueueNode* curr = mPHead;

	while (curr != nullptr) {
		QueueNode* next = curr->getPNext();
		delete curr;
		curr = next;
	}
}

// Returns true if empty, false otherwise (based on size attribute)
bool Queue::isEmpty() {
	return mSize == 0;
}


// Enqueue operation (insert node containing inputted Data object at the end of the queue)
bool Queue::enqueue(int customerNum, int serviceTime, LinkedList* gList) {
	bool success = false;
	int newTotalTime;

	if (mPHead != nullptr) { // Not empty list, so previous total time exists
		newTotalTime = serviceTime + mPTail->getPData()->getTotalTime(); // Get new total time
	}

	else newTotalTime = serviceTime; // Total time is same as service time if no prior total time exists
	
	Data* newData = new Data(customerNum, serviceTime, newTotalTime); // Create new Data object with given attributes

	if (newData != nullptr) { // Check if memory was allocated for the new Data object

		// Allocate space for and create new QueueNode with newData object and gList 
		QueueNode* newNode = new QueueNode(newData, gList);

		if (newNode != nullptr) { // Check if memory was allocated for the new QueueNode object

			success = true; // Memory was successfully allocated for the new QueueNode and Data objects
			mSize++;

			if (mPHead == nullptr) { // Empty queue
				mPHead = mPTail = newNode;
			}

			else { // Not empty queue
				mPTail->setPNext(newNode);
				mPTail = newNode;
			}
		}
	}

	return success;
}

// Delete node from front of queue
void Queue::dequeue() {

	if (mPHead != nullptr) { // Not an empty list

		QueueNode* target = mPHead; // Store address to current head (to be deleted later)

		mPHead = target->getPNext(); // Set the head to the next node in the list

		// Delete both the Data object pointed to by the target node and the node itself
		delete target;

		mSize--;
	}

	// If the list is empty (mPHead == nullptr), then nothing needs to be done
}

// Print attributes of each customer represented by each QueueNode
void Queue::printQueue() {
	QueueNode* curr = mPHead; // Create an iterator pointer and set it to head

	while (curr != nullptr) { // Iterate until reaching the end of the queue
		std::cout << *(curr->getPData()); // Display data attributes using overloaded stream operator
		std::cout << *(curr->getItemList());

		curr = curr->getPNext();
	}
}

// Print queue horizontally in a visually appealing manner
void Queue::printQueueNice() {

	QueueNode* iterator = mPHead; // Set iterator node to head

	for (int i = 0; i < mSize; i++) { // Print tops of boxes
		std::cout << "+------------------+ ";
	}

	std::cout << std::endl;

	for (int i = 0; i < mSize; i++) { // Print customer numbers
		std::cout << "| Customer #" << std::setw(2) << std::right << iterator->getPData()->getCustomerNum() << "     | ";
		iterator = iterator->getPNext();
	}

	std::cout << std::endl;
	iterator = mPHead; // Reset iterator

	for (int i = 0; i < mSize; i++) { // Print service times
		std::cout << "| Service Time: " << std::setw(2) << std::left << iterator->getPData()->getServiceTime() << "m| ";
		iterator = iterator->getPNext();
	}

	std::cout << std::endl;
	iterator = mPHead; // Reset iterator again

	for (int i = 0; i < mSize; i++) { // Print number of items in each cart
		std::cout << "| # of Items: " << std::setw(3) << std::right << iterator->getItemList()->getSize() << "  | ";
		iterator = iterator->getPNext();
	}
	
	std::cout << std::endl;

	for (int i = 0; i < mSize; i++) { // Print bottoms of boxes
		std::cout << "+------------------+ ";
	}
	
}

// Getters
QueueNode* Queue::getPHead() {
	return mPHead;
}
int Queue::getSize() {
	return mSize;
}

// Checks if the head of the queue needs to be dequeued (service time has reached 0 - the customer is done checking out)
void Queue::checkQueue() {

	if (this->mPHead != nullptr) { // Check that the list is not empty

		QueueNode* pMem = this->mPHead;
		int num = this->mPHead->getPData()->getServiceTime(); // Get the service time of the head node and store in num variable

		if (pMem->getPData()->getServiceTime() != 0) { // If the service time is not 0, then the customer is not done checking out - only decrease service time by 1 and exit function
			this->mPHead->getPData()->setServiceTime(num - 1);
		}
		else { // Customer is done checking out, so notify the user and dequeue the customer from the queue

			// Print out indicating customer is done checking out
			std::cout << "* Customer " << mPHead->getPData()->getCustomerNum() << " has finished checking out" << std::endl;
			this->dequeue(); // Dequeue the customer 
		}
	}
}

