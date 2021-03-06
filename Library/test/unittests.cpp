//--------------------------------------------------------------------------------------------------
// C++ Group 3 Members:
//                                                         Clint Worwood
//                                      Jake Parratt
//                  Joel Harrison
// Nino Munoz
//--------------------------------------------------------------------------------------------------
#include <iostream>
#include <exception>
#include "../lib/unittest.h"
#include "../lib/exceptions.h"
//--------------------------------------------------------------------------------------------------
// Includes for Modules to Test
#include "../include/simpledate.h"
// Includes for Modules to Test
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
// Unit Test Groups
//--------------------------------------------------------------------------------------------------
unittest::TestGroup simple_date_test_group("Simple Date");

void setup() {
//==================================================================================================
// Simple Date Unit Tests
//==================================================================================================
//--------------------------------------------------------------------------------------------------
// Test Default Constructor
//--------------------------------------------------------------------------------------------------
	simple_date_test_group.addTest([]()->void {
		try {
			SimpleDate simple_date;
			unittest::succeed();
		}
		catch(DateException& le) {
			unittest::fail("");
			std::cerr << le.what() << std::endl;
		}
		catch(UnimplementedException& ue) {
			unittest::fail("Invoked Unimplemented Feature");
		}
		catch(Exception& e) {
			unittest::fail("");
			std::cerr << e.what() << std::endl;
		}
	});
}

int main(int argc, char *argv[]) {
	setup();
//--------------------------------------------------------------------------------------------------
// Run Unit Tests
//--------------------------------------------------------------------------------------------------
	simple_date_test_group();
	
//--------------------------------------------------------------------------------------------------
// Display Cumulative Test Results
//--------------------------------------------------------------------------------------------------
	unittest::runTotalReport();
	return unittest::status();
}