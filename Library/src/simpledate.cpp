#include "../include/simpledate.h"

#include <iostream>
#include <ctime>

#include "../lib/exceptions.h"

using namespace std;

// TODO: yearsPriors
// TODO: monthsPrior
// TODO: yearsAhead
// TODO: monthsAhead

namespace {
	enum MONTHS {
		JANUARY = 1,
		FEBRUARY,
		MARCH,
		APRIL,
		MAY,
		JUNE,
		JULY,
		AUGUST,
		SEPTEMBER,
		OCTOBER,
		NOVEMBER,
		DECEMBER
	};
	constexpr unsigned int WEEK = 7;
}


bool SimpleDate::isLeapYear(unsigned int year) {
	// In order for a year to be a leap year it must:
	// Be evenly divisible by 4
	// Not be evenly divisible by 100, unless it is also evenly divisible by 400
	return (year % 4 != 0 ? false :
			year % 100 != 0 ? true :
			year % 400 == 0 ? true :
			false);
}

void SimpleDate::validateDate(unsigned int day, unsigned int month, unsigned int year) {
	if(!(day > 0)) {
		// DateException
		throw DateException("Invalid Day");
	}
	switch(month) {
		// 31 days
		case JANUARY:
		case MARCH:
		case MAY:
		case JULY:
		case AUGUST:
		case OCTOBER:
		case DECEMBER:
			if(!(day <= 31)) {
				// DateException Invalid Day
				throw DateException("Invalid Day");
			}
		break;
		// 30 days
		case APRIL:
		case JUNE:
		case SEPTEMBER:
		case NOVEMBER:
			if(!(day <= 30)) {
				// DateException Invalid Day
				throw DateException("Invalid Day");
			}
		break;
		// 28 - 29 days
		case FEBRUARY:
			if(isLeapYear(year)) {
				if(!(day <= 29)) {
					// DateException Invalid Day
					throw DateException("Invalid Day");
				}
			}
			else {
				if(!(day <= 28)) {
					// DateException Invalid Day
					throw DateException("Invalid Day");
				}
			}
		break;
		// Error
		default:
			//DateException Invalid Month
			throw DateException("Invalid Month");
		break;
	}
}

void SimpleDate::init(unsigned int day, unsigned int month, unsigned int year) {
	// Validate
	validateDate(day, month, year); // throws DateException
	m_day = day;
	m_month = month;
	m_year = year;
}

int SimpleDate::compare(const SimpleDate& date) {
	// Return -1 if Current Object less than, 0 if equal, 1 if Current Object greater than
	return (m_year < date.m_year ? -1 :
			m_year > date.m_year ? 1 :
			m_month < date.m_month ? -1 :
			m_month > date.m_month ? 1 :
			m_day < date.m_day ? -1 :
			m_day > date.m_day ? 1 :
			0);
}

int SimpleDate::compare(const SimpleDate&& date) {
	return compare(date);
}

// TODO: yearsPrior
void SimpleDate::yearsPrior(unsigned int years) {
	// keep track of leap years
	// adjust days according to leap years
	// adjust months according to leap years
	// adjust years
	throw UnimplementedException("yearsPrior() Not Implemented");
}

// TODO: monthsPrior
void SimpleDate::monthsPrior(unsigned int months) {
	// keep track of leap years
	// adjust days according to leap years
	// adjust months according to leap years
	// adjust years
	throw UnimplementedException("monthsPrior() Not Implemented");
}

void SimpleDate::weeksPrior(unsigned int weeks) {
	unsigned int days_back = weeks * WEEK;
	for(int i = 0; i < days_back; ++i) {
		regressDate();
	}
}

void SimpleDate::daysPrior(unsigned int days) {
	for(int i = 0; i < days; ++i) {
		regressDate();
	}
}

// TODO: yearsAhead
void SimpleDate::yearsAhead(unsigned int years) {
	// keep track of leap years
	// adjust days according to leap years
	// adjust months according to leap years
	// adjust years
	throw UnimplementedException("yearsAhead() Not Implemented");
}

// TODO: monthsAhead
void SimpleDate::monthsAhead(unsigned int months) {
	// keep track of leap years
	// adjust days according to leap years
	// adjust months according to leap years
	// adjust years
	throw UnimplementedException("monthsAhead() Not Implemented");
}

void SimpleDate::weeksAhead(unsigned int weeks) {
	unsigned int days_ahead = weeks * WEEK;
	for(int i = 0; i < days_ahead; ++i) {
		advanceDate();
	}
}

void SimpleDate::daysAhead(unsigned int days) {
	for(int i = 0; i < days; ++i) {
		advanceDate();
	}
}

SimpleDate::SimpleDate(unsigned int day, unsigned int month, unsigned int year) {
	init(day, month, year);
}

SimpleDate::SimpleDate() {
	// Use Current Date
	time_t now = time(0);
	tm *local_time = localtime(&now);
	init(local_time->tm_mday, (1 + local_time->tm_mon), (1900 + local_time->tm_year));
}

SimpleDate::SimpleDate(const SimpleDate& simple_date) {
	init(simple_date.m_day, simple_date.m_month, simple_date.m_year);
}

SimpleDate::SimpleDate(const SimpleDate&& simple_date) {
	init(simple_date.m_day, simple_date.m_month, simple_date.m_year);
}

SimpleDate::~SimpleDate() {}

void SimpleDate::display(ostream& os) {
	os << m_day << '/' << m_month << '/' << m_year;
}

void SimpleDate::displayAmerican(ostream& os) {
	os << m_month << '/' << m_day << '/' << m_year;
}

void SimpleDate::advanceDate() {
	validateDate(m_day, m_month, m_year);
	switch(m_month) {
		// 31 days
		case JANUARY:
			if(m_day < 31) {
				++m_day;
			}
			else {
				m_day = 1;
				++m_month;
			}
		break;
		// 28 - 29 days
		case FEBRUARY:
			if(isLeapYear(m_year)) {
				if(m_day < 29) {
					++m_day;
				}
				else {
					m_day = 1;
					++m_month;
				}
			}
			else {
				if(m_day < 28) {
					++m_day;
				}
				else {
					m_day = 1;
					++m_month;
				}
			}
		break;
		// 31
		case MARCH:
			if(m_day < 31) {
				++m_day;
			}
			else {
				m_day = 1;
				++m_month;
			}
		break;
		// 30
		case APRIL:
			if(m_day < 30) {
				++m_day;
			}
			else {
				m_day = 1;
				++m_month;
			}
		break;
		// 31
		case MAY:
			if(m_day < 31) {
				++m_day;
			}
			else {
				m_day = 1;
				++m_month;
			}
		break;
		// 30
		case JUNE:
			if(m_day < 30) {
				++m_day;
			}
			else {
				m_day = 1;
				++m_month;
			}
		break;
		// 31
		case JULY:
			if(m_day < 31) {
				++m_day;
			}
			else {
				m_day = 1;
				++m_month;
			}
		break;
		// 31
		case AUGUST:
			if(m_day < 31) {
				++m_day;
			}
			else {
				m_day = 1;
				++m_month;
			}
		break;
		// 30
		case SEPTEMBER:
			if(m_day < 30) {
				++m_day;
			}
			else {
				m_day = 1;
				++m_month;
			}
		break;
		// 31
		case OCTOBER:
			if(m_day < 31) {
				++m_day;
			}
			else {
				m_day = 1;
				++m_month;
			}
		break;
		// 30
		case NOVEMBER:
			if(m_day < 30) {
				++m_day;
			}
			else {
				m_day = 1;
				++m_month;
			}
		break;
		// 31
		case DECEMBER:
			if(m_day < 31) {
				++m_day;
			}
			else {
				m_day = 1;
				m_month = JANUARY;
				++m_year;
			}
		break;
	}
}

void SimpleDate::regressDate() {
	validateDate(m_day, m_month, m_year);
	switch(m_month) {
		// 31 days
		case JANUARY:
			if(m_day > 1) {
				--m_day;
			}
			else {
				m_day = 31;
				m_month = DECEMBER;
				--m_year;
			}
		break;
		// 28 - 29 days
		case FEBRUARY:
			if(m_day > 1) {
				--m_day;
			}
			else {
				m_day = 31;
				--m_month;
			}
		break;
		// 31
		case MARCH:
			if(m_day > 1) {
				--m_day;
			}
			else {
				if(isLeapYear(m_year)) {
					m_day = 29;
				}
				else {
					m_day = 28;
				}
				--m_month;
			}
		break;
		// 30
		case APRIL:
			if(m_day > 1) {
				--m_day;
			}
			else {
				m_day = 31;
				--m_month;
			}
		break;
		// 31
		case MAY:
			if(m_day > 1) {
				--m_day;
			}
			else {
				m_day = 30;
				--m_month;
			}
		break;
		// 30
		case JUNE:
			if(m_day > 1) {
				--m_day;
			}
			else {
				m_day = 31;
				--m_month;
			}
		break;
		// 31
		case JULY:
			if(m_day > 1) {
				--m_day;
			}
			else {
				m_day = 30;
				--m_month;
			}
		break;
		// 31
		case AUGUST:
			if(m_day > 1) {
				--m_day;
			}
			else {
				m_day = 31;
				--m_month;
			}
		break;
		// 30
		case SEPTEMBER:
			if(m_day > 1) {
				--m_day;
			}
			else {
				m_day = 31;
				--m_month;
			}
		break;
		// 31
		case OCTOBER:
			if(m_day > 1) {
				--m_day;
			}
			else {
				m_day = 30;
				--m_month;
			}
		break;
		// 30
		case NOVEMBER:
			if(m_day > 1) {
				--m_day;
			}
			else {
				m_day = 31;
				--m_month;
			}
		break;
		// 31
		case DECEMBER:
			if(m_day > 1) {
				--m_day;
			}
			else {
				m_day = 30;
				--m_month;
			}
		break;
	}
}
//--------------------------------------------------------------------------------------------------
// Assignment Operator
void SimpleDate::operator=(const SimpleDate& date) { init(date.m_day, date.m_month, date.m_year); }
void SimpleDate::operator=(const SimpleDate&& date) { init(date.m_day, date.m_month, date.m_year); }

//--------------------------------------------------------------------------------------------------
// Relational Operators
bool SimpleDate::operator==(const SimpleDate& date) { return compare(date) == 0; }
bool SimpleDate::operator==(const SimpleDate&& date) { return compare(date) == 0; }

bool SimpleDate::operator<(const SimpleDate& date) { return compare(date) < 0; }
bool SimpleDate::operator<(const SimpleDate&& date) { return compare(date) < 0; }

bool SimpleDate::operator>(const SimpleDate& date) { return compare(date) > 0; }
bool SimpleDate::operator>(const SimpleDate&& date) { return compare(date) > 0; }

bool SimpleDate::operator!=(const SimpleDate& date) { return compare(date) != 0; }
bool SimpleDate::operator!=(const SimpleDate&& date) { return compare(date) != 0; }

bool SimpleDate::operator<=(const SimpleDate& date) { return compare(date) <= 0; }
bool SimpleDate::operator<=(const SimpleDate&& date) { return compare(date) <= 0; }

bool SimpleDate::operator>=(const SimpleDate& date) { return compare(date) >= 0; }
bool SimpleDate::operator>=(const SimpleDate&& date) { return compare(date) >= 0; }