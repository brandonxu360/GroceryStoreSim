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
#include "grocerysimwrapper.hpp"
#include "test.hpp"

int main(void) {

	// Testing
	Test test;

	std::cout << "TEST CASES" << std::endl << std::endl;
	test.testEnqueueOnEmptyQueue();
	std::cout << std::endl;
	test.testEnqueueOnOneNodeQueue();
	std::cout << std::endl;
	test.testDequeueOnOneNodeQueue();
	std::cout << std::endl;
	test.testDequeueOnTwoNodeQueue();
	/*std::cout << std::endl;
	test.testSimulationFor24Hours();*/

	std::cout << std::endl;
	system("pause");
	std::cout << std::endl;

	srand(time(NULL)); // Initialize random seed

	std::string itemArray[25] = { "Banana", "Frozen Meal", "Apple", "Steak", "Ground Beef", "Soap" };

	GrocerySimWrapper myStore(itemArray);

	// Get minutes to run simulation for
	int time;
	std::cout << "Enter a number of minutes for the simulation (at least 10): ";
	std::cin >> time;
	system("cls");

	myStore.runSimulation(time); // Run the simulation with the inputted time

	return 0;
}