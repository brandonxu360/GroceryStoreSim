/*
* Name: Brandon Xu
* Project: GroceryStoreSim
* File: main.cpp
* Date: 3/6/23
* Description: Main file for general program flow and execution
*/

#include "header.hpp"
#include "data.hpp"
#include "linkedlist.hpp"
#include "queue.hpp"

int main(void) {

	Queue myQueue; // Initialize the queue object

	srand(time(NULL)); // Initialize random seed

	// Get minutes to run simulation for
	int time;
	std::cout << "Enter a number of minutes for the simulation (at least 10): ";
	std::cin >> time;
	system("cls");

	myQueue.runSim(time); // Run the simulation with the inputted time

	return 0;
}