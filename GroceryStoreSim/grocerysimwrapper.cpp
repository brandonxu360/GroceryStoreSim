/*
* Name: Brandon Xu
* Project: GroceryStoreSim
* File: grocerysimwrapper.cpp
* Date: 3/6/23
* Description: Source file for the wrapper class of the simulation - this class will provide only the nessessary and intuitive functionality for
*			   the grocery store simulator
*/

#include "grocerysimwrapper.hpp"

// Constructor that takes in an itemList array
GrocerySimWrapper::GrocerySimWrapper(const std::string itemList[]) {

    // Initialize the member item list using the given item list
    std::size_t numItems = std::min(std::size_t{ 25 }, std::size_t{ sizeof(mItemList) / sizeof(mItemList[0]) });
    for (std::size_t i = 0; i < numItems; i++) {
        mItemList[i] = itemList[i];
    }

}

// Display the express and normal queues horizontally using the printQueueNice functions of the Queue class
void GrocerySimWrapper::displayStore() {

	// Display express line
	std::cout << "Express Line: " << std::endl << std::endl;
	mExpress.printQueueNice();
	std::cout << std::endl << std::endl;

	// Display normal line
	std::cout << "Normal Line:  " << std::endl << std::endl;
	mNormal.printQueueNice();
	std::cout << std::endl << std::endl;
	
}

// Convert time from minutes to hr:mn format and displays to console
void GrocerySimWrapper::displayTime(int minutes) {
	std::cout << "CURRENT TIME: " << std::setfill('0') << std::setw(2) << minutes / 60 << ":" << std::setw(2) << minutes % 60 << std::setfill(' ') << std::endl;
}

// Get service time based on number of items in cart
int GrocerySimWrapper::getServiceTime(int numItems) {
	return numItems + 2;
}

// Main executable logic - simulate two grocery lines (queues)
void GrocerySimWrapper::runSimulation(int time) {

	int elapsedTime = 0; // Elased time to keep track of time during simulation

	// Customer numbers
	int customerNumber = 1;

	// Get initial random arrival times for express and normal lanes
	int expressArrival = rand() % 5 + 1;
	int normalArrival = rand() % 8 + 3;

	// Time loop
	while (elapsedTime <= time) {

		//	DISPLAY CURRENT MINUTE
		displayTime(elapsedTime);
		std::cout << "---------------------------------------------" << std::endl << std::endl;

		//	STATE CHANGES
		std::cout << "STATE CHANGES" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;

		//	ENQUEUE CHECKS
		if (elapsedTime == expressArrival) { // Time that a customer will arrive in express lane has been reached

			// Print to state changes that a customer has arrived in the express lane
			std::cout << "* Customer " << customerNumber << " has joined the express line" << std::endl;

			LinkedList* expressCart = new LinkedList(mItemList, 6); // Create a random cart for the new customer
			mExpress.enqueue(customerNumber,getServiceTime(expressCart->getSize()), expressCart);

			expressArrival += rand() % 5 + 1; // Set next arrival time for express lane by incrementing by express lane random time
			customerNumber++;
		}
		if (elapsedTime == normalArrival) { // Time that a customer will arrive in normal lane has been reached

			// Print to state changes that a customer has arrived in the normal lane
			std::cout << "* Customer " << customerNumber << " has joined the normal line" << std::endl;

			LinkedList* normalCart = new LinkedList(mItemList, 6); // Create a random cart for the new customer
			mNormal.enqueue(customerNumber, getServiceTime(normalCart->getSize()), normalCart);

			normalArrival += rand() % 8 + 3; // Set next arrival time for normal lane by incrementing by normal lane random time
			customerNumber++;
		}

		//	DEQUEUE CHECKS
		mExpress.checkQueue();
		mNormal.checkQueue();

		std::cout << std::endl;

		displayStore(); // Display current state of store

		// Display entire queues every 10 minutes
		if (elapsedTime != 0 && elapsedTime % 10 == 0) {
			std::cout << "FULL QUEUE INFORMATION" << std::endl;
			std::cout << "---------------------------------------------" << std::endl;
			std::cout << "Express Lane: " << std::endl;
			mExpress.printQueue();
			std::cout << std::endl << "Normal Lane: " << std::endl;
			mNormal.printQueue();
		}

		// COMMENT OUT 3 SECOND WAIT BLOCK BELOW AND UNCOMMENT THE PAUSE IF YOU WANT TO MOVE THROUGH SIMULATION MANUALLY
		// system("pause");

		// Wait for 3 seconds so the user can observe changes
		std::cout << std::endl << "Next minute in..." << std::endl;
		for (int i = 3; i > 0; i--) {
			std::cout << i << "... ";
			std::cout.flush(); // flush output to ensure it is immediately visible
			std::this_thread::sleep_for(std::chrono::seconds(1)); // wait for 1 second
		}
		std::cout << std::endl;

		system("cls");

		elapsedTime++;
	}
}

