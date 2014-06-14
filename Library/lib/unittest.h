#ifndef UNITTEST_H
#define UNITTEST_H

//--------------------------------------------------------------------------------------------------
// Description: Automated Test System
// Author: Clint Worwood
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
// Unittest API v2.0.0 - Reference
//--------------------------------------------------------------------------------------------------
// testCondition(:bool condition):void
// fail(:string text):void
// succeed():void
// assertEqual(:bool expected, :bool actual):void
// assertFalse(:bool condition):void
// assertTrue(:bool condition):void
// assertNotNull(:void* object):void
// assertNull(:void* object):void
// startGroup(:string group_name):void
// runGroupReport():void
// runTotalReport():void
// status():bool
//--------------------------------------------------------------------------------------------------

#include <string>
#include <vector>
#include <functional>

namespace unittest {
//--------------------------------------------------------------------------------------------------
// Forward Declarations
//--------------------------------------------------------------------------------------------------
	void do_test(const std::string condText, bool cond, const std::string fileName, long lineNumber);
	void do_fail(const std::string text, const std::string fileName, long lineNumber);
	void do_succeed();
	void do_assert_equal(const std::string expectedText, bool expected, const std::string actualText, bool actual, const std::string fileName, long lineNumber);
	void do_assert_false(const std::string condText, bool condition, const std::string fileName, long lineNumber);
	void do_assert_true(const std::string condText, bool condition, const std::string fileName, long lineNumber);
	void do_assert_not_null(void* object, const std::string fileName, long lineNumber);
	void do_assert_null(void* object, const std::string fileName, long lineNumber);
	void start_test_group(const std::string group_name = std::string(""));
	void run_group_report();
	void run_total_report();
	bool all_tests_successful();
//--------------------------------------------------------------------------------------------------
// Define API Macros
//--------------------------------------------------------------------------------------------------
	#define testCondition(cond) do_test(#cond, cond, __FILE__, __LINE__)
	#define fail(text) do_fail(text, __FILE__, __LINE__)
	#define succeed() do_succeed()
	#define assertEqual(expected, actual) do_assert_equal(#expected, expected, #actual, actual, __FILE__, __LINE__)
	#define assertFalse(cond) do_assert_false(#cond, cond, __FILE__, __LINE__)
	#define assertTrue(cond) do_assert_true(#cond, cond, __FILE__, __LINE__)
	#define assertNotNull(object) do_assert_not_null(object, __FILE__, __LINE__)
	#define assertNull(object) do_assert_not_null(object, __FILE__, __LINE__)
	#define startGroup(group_name) start_test_group(group_name)
	#define runGroupReport() run_group_report()
	#define runTotalReport() run_total_report()
	#define status() all_tests_successful()
//--------------------------------------------------------------------------------------------------
// Declare Unit Test Classes
//--------------------------------------------------------------------------------------------------
	class TestGroup {
	private:
		std::vector<std::function<void()>> tests;
	public:
		TestGroup(std::string group_name = std::string(""));
		void operator()();
		void addTest(std::function<void()> test);
	};
}

#endif