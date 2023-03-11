/*
* Name: Brandon Xu
* Project: GroceryStoreSim
* File: test.cpp
* Date: 3/6/23
* Description: Source file for the test class, which holds functions to test 5 test cases
*/

#include "test.hpp"

void Test::testEnqueueOnEmptyQueue(void) {

	std::cout << "TESTING ENQUEUE ON EMPTY QUEUE: " << std::endl;

	Queue q; // Initialize empty q Queue

	q.enqueue(1, 1, nullptr); // Enqueue a node into the empty q Queue
	
	if (q.getSize() == 1) {
		std::cout << "* SUCESS: A node has been successfully added to queue" << std::endl;

		if (q.getPHead()->getPData()->getCustomerNum() == 1 && q.getPHead()->getPData()->getServiceTime() == 1
			&& q.getPHead()->getItemList() == nullptr) {
			std::cout << "* SUCCESS: The node that was added to queue contains the correct information" << std::endl;
		}

		else {
			std::cout << "* ERROR: The node at the front of the queue contains incorrect information or is not the new node" << std::endl;
		}
	}

	else {
		std::cout << "* ERROR: A node was not added to queue" << std::endl;
	}
}

void Test::testEnqueueOnOneNodeQueue() {

	std::cout << "TESTING ENQUEUE ON ONE NODE QUEUE: " << std::endl;

	Queue q;
	q.enqueue(1, 1, nullptr); // Initialize q Queue with one node 

	q.enqueue(2, 2, nullptr); // Enqueue target node

	if (q.getSize() == 2) {
		std::cout << "* SUCESS: A node has been successfully added to queue" << std::endl;

		if (q.getPHead()->getPNext()->getPData()->getCustomerNum() == 2 && q.getPHead()->getPNext()->getPData()->getServiceTime() == 2
			&& q.getPHead()->getPNext()->getItemList() == nullptr) {
			std::cout << "* SUCCESS: The node that was added to queue contains the correct information" << std::endl;
		}

		else {
			std::cout << "* ERROR: The node that was added to the queue contains incorrect information or is not the new node" << std::endl;
		}
	}

	else {
		std::cout << "* ERROR: A node was not added to queue" << std::endl;
	}
}

void Test::testDequeueOnOneNodeQueue() {
	std::cout << "TESTING DEQUEUE ON ONE NODE QUEUE: " << std::endl;

	Queue q;
	q.enqueue(1, 1, nullptr); // Initialize q Queue with one node

	q.dequeue(); // Call dequeue

	if (q.getSize() == 0) {
		std::cout << "* SUCESS: The size of the queue has been corretly adjusted to 0" << std::endl;

		if (q.getPHead() == nullptr) {
			std::cout << "* SUCCESS: The node that was dequeued is now nullptr" << std::endl;
		}

		else {
			std::cout << "* ERROR: The queue head still points to a nonnull node" << std::endl;
		}
	}

	else {
		std::cout << "* ERROR: The size of the queue is not the expected value of 0" << std::endl;
	}
	
}

void Test::testDequeueOnTwoNodeQueue() {

	std::cout << "TESTING ENQUEUE ON TWO NODE QUEUE: " << std::endl;

	// Initialize q Queue with two nodes
	Queue q;
	q.enqueue(1, 1, nullptr); 
	q.enqueue(2, 2, nullptr); 

	q.dequeue(); // Call dequeue on q Queue

	if (q.getSize() == 1) {
		std::cout << "* SUCESS: The size of the queue has been corretly adjusted to 1" << std::endl;

		if (q.getPHead()->getPNext() == nullptr) {
			std::cout << "* SUCCESS: The node that was dequeued is now nullptr" << std::endl;

			if (q.getPHead()->getPData()->getCustomerNum() == 2 && q.getPHead()->getPData()->getServiceTime() == 2) {
				std::cout << "* SUCCESS: The first-in node was correctly dequeued and the remaining node is the second-in node" << std::endl;
			}

			else {
				std::cout << "* ERROR: The node left in the queue is not the correct node or contains unexpected attributes" << std::endl;
			}
		}

		else {
			std::cout << "* ERROR: The queue head node's pointer to the next node still points to a nonnull node" << std::endl;
		}
	}

	else {
		std::cout << "* ERROR: The size of the queue is not the expected value of 0" << std::endl;
	}
	
}

void Test::testSimulationFor24Hours() {
	
	std::string itemArray[25] = { "Banana", "Frozen Meal", "Apple", "Steak", "Ground Beef", "Soap" };

	GrocerySimWrapper myStore(itemArray); // Initialize a GrocerySimWrapper object with the itemArray array of availible grocery items

	myStore.runSimulation(24 * 60); // Run the simulation for 24 hours - the success of the test will be determined visually by the user

}