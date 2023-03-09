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
		delete target->getPData();
		delete target;
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

// Returns a random number from 1-5 to represent the arrival time of a customer in the express lane
int Queue::getExpressArrival() {
	return rand() % 5 + 1;
}
// Returns a random number from 3-8 to represent the arrival time of a customer in the normal lane
int Queue::getNormalArrival() {
	return rand() % 8 + 3;
}

// Get service time based on number of items in cart
int Queue::getServiceTime(int numItems) {
	return numItems + 2;
}

void Queue::checkQueue(Queue* myQueue, int time) {
	if (myQueue->mPHead != nullptr) {
		QueueNode* pMem = myQueue->mPHead;
		int num = myQueue->mPHead->getPData()->getServiceTime();
		if (pMem->getPData()->getServiceTime() != 0) {
			myQueue->mPHead->getPData()->setServiceTime(num - 1);
		}
		else {
			myQueue->dequeue();
		}
	}
}

// Main executable logic - simulate two grocery lines (queues)
void Queue::runSim(int time) {
	Queue expressQ, normalQ;
	int elapsedTime = 0; // Elased time to keep track of time during simulation

	// Customer numbers
	int expressCustomerNum = 1;
	int normalCustomerNum = 1;

	// Get initial random arrival times for express and normal lanes
	int expressArrival = getExpressArrival();
	int normalArrival = getNormalArrival();

	// Array of items availible for purchase in store
	std::string itemArray[25] = { "Banana", "Frozen Meal", "Apple", "Steak", "Ground Beef", "Soap" };

	// Time loop
	while (elapsedTime <= time) {

		//ENQUEUE 
		if (elapsedTime == expressArrival) { // Time that a customer will arrive in express lane has been reached
			LinkedList* expressCart = new LinkedList(itemArray, 6);
			expressQ.enqueue(expressCustomerNum, getServiceTime(expressCart->getSize()), expressCart);

			expressArrival += getExpressArrival(); // Set next arrival time for express lane by incrementing by express lane random time
			expressCustomerNum++;
		}
		if (elapsedTime == normalArrival) { // Time that a customer will arrive in normal lane has been reached
			LinkedList* normalCart = new LinkedList(itemArray, 6);
			normalQ.enqueue(normalCustomerNum, getServiceTime(normalCart->getSize()), normalCart);

			normalArrival += getNormalArrival(); // Set next arrival time for normal lane by incrementing by normal lane random time
			normalCustomerNum++;
		}

		//DEQUEUE
		checkQueue(&expressQ, elapsedTime);
		checkQueue(&normalQ, elapsedTime);

		// Display entire queues every 10 minutes
		if (elapsedTime != 0 && elapsedTime % 10 == 0) {
			system("cls");
			std::cout << "Express Lane: " << std::endl;
			expressQ.printQueue();
			std::cout << std::endl << "Normal Lane: " << std::endl;
			normalQ.printQueue();
			std::cout << std::endl << "Click any key to continue: " << std::endl;
			std::cin.get();
		}

		elapsedTime++;
	}
	
}