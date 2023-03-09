/*
* Name: Brandon Xu
* Project: GroceryStoreSim
* File: data.hpp
* Date: 3/6/23
* Description: Header file for the Data class that will contain the attributes to describe/represent a customer
*/

#pragma once

#include "header.hpp"

class Data {

public: // Member functions

	Data(); // Default constructor

	Data(int customerNum, int serviceTime, int totalTime); // Constructor for customer number, service time, and total time input

	~Data(); // Destructor

	//getters
	int getCustomerNum();
	int getServiceTime();
	int getTotalTime();

	//setters
	void setServiceTime(int newTime);

private:

	int mCustomerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
	int mServiceTime;   // Random time; varies between express and normal lanes; units in minutes
	int mTotalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes

}; // This memory needs to be allocated on the heap!

// Overloaded stream insertion operator for displaying a Data object
std::ostream& operator<<(std::ostream& os, Data& data);