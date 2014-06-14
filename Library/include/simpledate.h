#ifndef SIMPLEDATE_H
#define SIMPLEDATE_H

#include <iosfwd>

// TODO: yearsPrior
// TODO: monthsPrior
// TODO: yearsAhead
// TODO: monthsAhead

class SimpleDate {
private:
	unsigned int m_day;
	unsigned int m_month;
	unsigned int m_year;
	
	// Name: isLeapYear
	// Description: Check if year is a Leap Year
	// Arguments: unsigned int year
	// Returns: bool
	// Pre-conditions: Must have a valid year
	// Post-conditions: none
	// Throws: none
	bool isLeapYear(unsigned int year);
	
	// Name: validateDate
	// Description: Check if date is valid
	// Arguments: unsigned int day, unsigned int month, unsigned int year
	// Returns: void
	// Pre-conditions: Must have a valid day, month, and year
	// Post-conditions: none
	// Throws: DateException
	void validateDate(unsigned int day, unsigned int month, unsigned int year);
	
	// Name: init
	// Description: Initializes Simple Date Object
	// Arguments: unsigned int day, unsigned int month, unsigned int year
	// Returns: void
	// Pre-Conditions: Must have a valid day, month, and year
	// Post-Conditions: Simple Date Object is Initialized
	// Throws: DateException
	void init(unsigned int day, unsigned int month, unsigned int year);
	
	// Name: compare
	// Description: Compare SimpleDate Object to current SimpleDate Object
	// Arguments: const SimpleDate& date
	// Returns: int
	// Pre-conditions: Current Object and Object being compared against must not be Null
	// Post-conditions: none
	int compare(const SimpleDate& date);
	
	int compare(const SimpleDate&& date);
	
	friend class SimpleDateFactory;
	
	// TODO: yearsPrior
	void yearsPrior(unsigned int years);
	
	// TODO: monthsPrior
	void monthsPrior(unsigned int months);
	
	void weeksPrior(unsigned int weeks);
	
	void daysPrior(unsigned int days);
	
	// TODO: yearsAhead
	void yearsAhead(unsigned int years);
	
	// TODO: monthsAhead
	void monthsAhead(unsigned int months);
	
	void weeksAhead(unsigned int weeks);

	void daysAhead(unsigned int days);
	
public:
	
	// Name: SimpleDate
	// Description: Simple Date Constructor
	// Arguments: unsigned int day, unsigned int month, unsigned int year
	// Returns: this pointer for SimpleDate Object
	// Pre-conditions: Must have a valid day, month, and year as well as enough available memory
	// Post-conditions: SimpleDate Object is allocated and initialized
	// Throws: DateException
	SimpleDate(unsigned int day, unsigned int month, unsigned int year);
	
	// Name: SimpleDate
	// Description: Default Simple Date Constructor
	// Arguments: none
	// Returns: this pointer for SimpleDate Object
	// Pre-conditions: Must have a valid day, month, and year as well as enough available memory
	// Post-conditions: SimpleDate Object is allocated and initialized
	// Throws: DateException
	SimpleDate();
	
	// Name: SimpleDate
	// Description: Simple Date Copy Constructor
	// Arguments: const SimpleDate& simple_date
	// Returns: this pointer for SimpleDate Object
	// Pre-conditions: simple_date must not be null and must have a valid day, month,
	//					and year as well as enough available memory
	// Post-conditions: SimpleDate Object is allocated and initialized
	// Throws: DateException
	SimpleDate(const SimpleDate& simple_date);
	
	// Name: SimpleDate
	// Description: Simple Date R-Value Reference Copy Constructor
	// Arguments: const SimpleDate&& simple_date
	// Returns: this pointer for SimpleDate Object
	// Pre-conditions: simple_date must not be null and must have a valid day, month,
	//					and year as well as enough available memory
	// Post-conditions: SimpleDate Object is allocated and initialized
	// Throws: DateException
	SimpleDate(const SimpleDate&& simple_date);
	
	~SimpleDate();
	
	void display(std::ostream& os);
	
	void displayAmerican(std::ostream& os);
	
	// Name: advanceDate
	// Description: Advance current date by one day
	// Arguments: none
	// Returns: void
	// Pre-conditions: Must have a valid day, month, and year
	// Post-conditions: Date is advanced by one day
	// Throws: none
	void advanceDate();
	
	// Name: regressDate
	// Description: Regress current date by one day
	// Arguments: none
	// Returns: void
	// Pre-conditions: Must have a valid day, month, and year
	// Post-conditions: Date is regressed by one day
	// Throws: none
	void regressDate();
//--------------------------------------------------------------------------------------------------
// Assignment Operator
	void operator=(const SimpleDate& date);
	void operator=(const SimpleDate&& date);
	
//--------------------------------------------------------------------------------------------------
// Relational Operators
	bool operator==(const SimpleDate& date);
	bool operator==(const SimpleDate&& date);
	
	bool operator<(const SimpleDate& date);
	bool operator<(const SimpleDate&& date);
	
	bool operator>(const SimpleDate& date);
	bool operator>(const SimpleDate&& date);
	
	bool operator!=(const SimpleDate& date);
	bool operator!=(const SimpleDate&& date);
	
	bool operator<=(const SimpleDate& date);
	bool operator<=(const SimpleDate&& date);
	
	bool operator>=(const SimpleDate& date);
	bool operator>=(const SimpleDate&& date);
};

class SimpleDateFactory {
private:
	SimpleDateFactory() = delete;
public:
	~SimpleDateFactory() {}
	
	static SimpleDate AmericanDate(unsigned int month, unsigned int day, unsigned int year) {
		SimpleDate date(day, month, year);
		return date;
	}
	
	static SimpleDate date(unsigned int day, unsigned int month, unsigned int year) {
		SimpleDate date(day, month, year);
		return date;
	}
	
	static SimpleDate today() {
		SimpleDate today;
		return today;
	}
	
	static SimpleDate daysAhead(unsigned int days) {
		SimpleDate today;
		return daysAhead(today, days);
	}
	
	static SimpleDate daysAhead(SimpleDate simple_date, unsigned int days) {
		simple_date.daysAhead(days);
		return simple_date;
	}
	
	static SimpleDate weeksAhead(unsigned int weeks) {
		SimpleDate today;
		return weeksAhead(today, weeks);
	}
	
	static SimpleDate weeksAhead(SimpleDate simple_date, unsigned int weeks) {
		simple_date.weeksAhead(weeks);
		return simple_date;
	}
	
	static SimpleDate monthsAhead(unsigned int months) {
		SimpleDate today;
		return monthsAhead(today, months);
	}
	
	static SimpleDate monthsAhead(SimpleDate simple_date, unsigned int months) {
		simple_date.monthsAhead(months);
		return simple_date;
	}
	
	static SimpleDate yearsAhead(unsigned int years) {
		SimpleDate today;
		return yearsAhead(today, years);
	}
	
	static SimpleDate yearsAhead(SimpleDate simple_date, unsigned int years) {
		simple_date.yearsAhead(years);
		return simple_date;
	}
	
	static SimpleDate yearsPrior(unsigned int years) {
		SimpleDate today;
		return yearsPrior(today, years);
	}
	
	static SimpleDate yearsPrior(SimpleDate simple_date, unsigned int years) {
		simple_date.yearsPrior(years);
		return simple_date;
	}
	
	static SimpleDate monthsPrior(unsigned int months) {
		SimpleDate today;
		return monthsPrior(today, months);
	}
	
	static SimpleDate monthsPrior(SimpleDate simple_date, unsigned int months) {
		simple_date.monthsPrior(months);
		return simple_date;
	}
	
	static SimpleDate weeksPrior(unsigned int weeks) {
		SimpleDate today;
		return weeksPrior(today, weeks);
	}
	
	static SimpleDate weeksPrior(SimpleDate simple_date, unsigned int weeks) {
		simple_date.weeksPrior(weeks);
		return simple_date;
	}
	
	static SimpleDate daysPrior(unsigned int days) {
		SimpleDate today;
		return daysPrior(today, days);
	}
	
	static SimpleDate daysPrior(SimpleDate simple_date, unsigned int days) {
		simple_date.daysPrior(days);
		return simple_date;
	}
};

#endif