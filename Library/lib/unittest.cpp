//--------------------------------------------------------------------------------------------------
// Description: Automated Test System
// Author: Clint Worwood
// Version: 2.0.0
//--------------------------------------------------------------------------------------------------
#include <iostream>
#include "unittest.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::function;

namespace unittest {
	namespace {
//--------------------------------------------------------------------------------------------------
// Constants
//--------------------------------------------------------------------------------------------------
		const string DIVIDER_THICK("==================================================");
		const string DIVIDER("--------------------------------------------------");
		const string PASSES("Number of Passes");
		const string FAILS("Number of Failures");
//--------------------------------------------------------------------------------------------------
// Data Members
//--------------------------------------------------------------------------------------------------
		size_t nPass = 0;
		size_t nFail = 0;
		size_t totalPass = 0;
		size_t totalFail = 0;
		string test_group_name("");
//--------------------------------------------------------------------------------------------------
// Helper Functions
//--------------------------------------------------------------------------------------------------
		void failure(const string text, const string fileName, long lineNumber) {
			cout << "FAILURE: " << text << " in file " << fileName
						<< " on line " << lineNumber << endl;
			++nFail;
			++totalFail;
		}
		
		void success() {
			++nPass;
			++totalPass;
		}
	}
//--------------------------------------------------------------------------------------------------
// Implementations
//--------------------------------------------------------------------------------------------------
	void do_test(const string condText, bool cond, const string fileName, long lineNumber) {
		if (!cond) {
			failure(condText, fileName, lineNumber);
		}
		else {
			success();
		}
	}
	
	void do_fail(const string text, const string fileName, long lineNumber) {
		failure(text, fileName, lineNumber);
	}
	
	void do_succeed() {
		success();
	}
	
	void do_assert_equal(const string expectedText, bool expected, const string actualText, bool actual, const string fileName, long lineNumber) {
		if(!(expected == actual)) {
			failure(expectedText + " != " + actualText, fileName, lineNumber);
		}
		else {
			success();
		}
	}
	
	void do_assert_false(const string condText, bool condition, const string fileName, long lineNumber) {
		if(!(condition == false)) {
			failure(condText, fileName, lineNumber);
		}
		else {
			success();
		}
	}
	
	void do_assert_true(const string condText, bool condition, const string fileName, long lineNumber) {
		if(!(condition == true)) {
			failure(condText, fileName, lineNumber);
		}
		else {
			success();
		}
	}
	
	void do_assert_not_null(void* object, const string fileName, long lineNumber) {
		if(!(object != NULL)) {
			failure("object == NULL", fileName, lineNumber);
		}
		else {
			success();
		}
	}
	
	void do_assert_null(void* object, const string fileName, long lineNumber) {
		if(object != NULL) {
			failure("object != NULL", fileName, lineNumber);
		}
		else {
			success();
		}
	}
	
	void start_test_group(const string group_name) {
		test_group_name = group_name;
		cout << "\nRunning "
					<< (!test_group_name.empty() ? test_group_name : "")
					<< (!test_group_name.empty() ?  " " : "")
					<< "tests\n" << DIVIDER
					<< endl;
		nPass = 0;
		nFail = 0;
	}
	
	void run_group_report() {
		const string test_report_title = !test_group_name.empty() ? " Test Report:" : "Test Report:";
		cout << "\n" << DIVIDER_THICK << "\n"
					<< test_group_name << test_report_title
					<< "\n" << DIVIDER_THICK << "\n\n"
					<< "\t" << PASSES << " = " << nPass << "\n"
					<< "\t" << FAILS << " = " << nFail << "\n"
					<< "\n" << DIVIDER << endl;
	}
	
	void run_total_report() {
		cout << "\n" << DIVIDER_THICK << "\n"
					<< "Test Results Summary:"
					<< "\n" << DIVIDER_THICK << "\n\n"
					<< "\t" << PASSES << " = " << totalPass << "\n"
					<< "\t" << FAILS << " = " << totalFail << endl;
	}
	
	bool all_tests_successful() {
		bool result = false;
		if(totalFail == 0) {
			result = true;
		}
		return result;
	}
	
	TestGroup::TestGroup(string group_name) {
		startGroup(group_name);
	}
	
	void TestGroup::operator()() {
		for(auto test: tests) {
			test();
		}
		runGroupReport();
	}
	
	void TestGroup::addTest(function<void()> test) {
		tests.push_back(test);
	}
}