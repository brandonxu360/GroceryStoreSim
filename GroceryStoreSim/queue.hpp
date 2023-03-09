/*
* Name: Brandon Xu
* Project: GroceryStoreSim
* File: queue.hpp
* Date: 3/6/23
* Description: Header file for the Queue class, which will organize the QueueNode objects to represent a grocery line
*/

#pragma once

#include "header.hpp"
#include "queuenode.hpp"

class Queue {
	
public: // Member functions
	
	Queue(); // Default constructor

	// Queue operations
	bool enqueue(int customerNum, int serviceTime, LinkedList* gList); // Insert node at end of queue
	void dequeue(); // Delete node from front of queue
	void printQueue(); // Print attributes of each customer represented by each QueueNode

	// Get arrival times (random) for express/normal lanes
	int getExpressArrival();
	int getNormalArrival();

	// Get service time based on number of items in cart
	int getServiceTime(int numItems);

	// Check if the time has reached when the head node should be dequeued
	void checkQueue(Queue* myQueue, int time);

	// Main executable logic
	void runSim(int time); // Simulate two grocery lines (queues) 

private:

	QueueNode* mPHead;
	QueueNode* mPTail;
};

