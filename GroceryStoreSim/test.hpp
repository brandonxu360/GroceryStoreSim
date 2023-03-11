/*
* Name: Brandon Xu
* Project: GroceryStoreSim
* File: test.hpp
* Date: 3/6/23
* Description: Header file for the test class, which holds functions to test 5 test cases
*/

#pragma once

#include "queue.hpp"
#include "grocerysimwrapper.hpp"

class Test {

public:

	// Test functions
	void testEnqueueOnEmptyQueue(void);
	void testEnqueueOnOneNodeQueue(void);
	void testDequeueOnOneNodeQueue(void);
	void testDequeueOnTwoNodeQueue(void);
	void testSimulationFor24Hours(void);

private:

};