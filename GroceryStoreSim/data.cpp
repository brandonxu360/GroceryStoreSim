/*
* Name: Brandon Xu
* Project: GroceryStoreSim
* File: data.cpp
* Date: 3/6/23
* Description: Source file for Data class that will contain the attributes to describe/represent a customer
*/

#include "header.hpp"
#include "data.hpp"

// Default constructor
Data::Data() {
	mCustomerNumber = 0;
	mServiceTime = 0;
	mTotalTime = 0;
}

// Constructor for provided customer number, service time, and total time input
Data::Data(int customerNum, int serviceTime, int totalTime) {
	mCustomerNumber = customerNum;
	mServiceTime = serviceTime;
	mTotalTime = totalTime;
}

// Destructor
Data::~Data() {}

// Getters
int Data::getCustomerNum() {
	return mCustomerNumber;
}

int Data::getServiceTime() {
	return mServiceTime;
}

int Data::getTotalTime() {
	return mTotalTime;
}

// Setters
void Data::setServiceTime(int newTime) {
	mServiceTime = newTime;
}

// Overloaded stream insertion operator for displaying a Data object
std::ostream& operator<<(std::ostream& os, Data& data) {
	os << "Customer number:      " << data.getCustomerNum() << std::endl;
	os << "Service time:         " << data.getServiceTime() << std::endl;
	os << "Total service time:   " << data.getTotalTime() << std::endl;
	return os;
}