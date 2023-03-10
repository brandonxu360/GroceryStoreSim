/*
* Name: Brandon Xu
* Project: GroceryStoreSim
* File: grocerysimwrapper.hpp
* Date: 3/6/23
* Description: Header file for the wrapper class of the simulation - this class will provide only the nessessary and intuitive functionality for 
*			   the grocery store simulator
*/

#include "linkedlist.hpp"
#include "queue.hpp"

class GrocerySimWrapper {
public:

	GrocerySimWrapper(const std::string itemList[]); // Default constructor - takes an item list

	void displayStore(); // Display the store state (queues and change of state messages) visually to the user

	void displayTime(int minutes); // Convert minutes into clock time (hr:mn) and print to display

	void runSimulation(int time); // Run simulation for duration of time given

private:

	Queue mExpress, mNormal; // The two queues representing the checkout lanes
	std::string mItemList[25]; // List of availible items in store

};