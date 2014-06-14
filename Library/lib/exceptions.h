#ifndef MY_EXCEPTIONS_H
#define MY_EXCEPTIONS_H
//--------------------------------------------------------------------------------------------------
// Author: Clint Worwood
//--------------------------------------------------------------------------------------------------
#include <string>

namespace {
	const std::string UNIMPLEMENTED_ERROR_PREFIX("UNIMPLEMENTED ERROR: ");
	const std::string FILE_ERROR_PREFIX("FILE ERROR: ");
	const std::string DATA_ERROR_PREFIX("DATA ERROR: ");
	const std::string LOGIC_ERROR_PREFIX("LOGIC ERROR: ");
	const std::string DATE_ERROR_PREFIX("DATE ERROR: ");
}

class Exception {
protected:
	std::string error_text;
public:
	Exception(std::string msg) : error_text(msg) {}
	virtual ~Exception() {};
	virtual std::string what() = 0;
};

class UnimplementedException : public Exception {
public:
	UnimplementedException(std::string msg) : Exception(msg) {}
	~UnimplementedException() {}
	std::string what() {
		return UNIMPLEMENTED_ERROR_PREFIX + error_text;
	}
};

class FileException : public Exception {
public:
	FileException(std::string msg) : Exception(msg) {}
	~FileException() {}
	std::string what() {
		return FILE_ERROR_PREFIX + error_text;
	}
};

class DataException : public Exception {
public:
	DataException(std::string msg) : Exception(msg) {}
	~DataException() {}
	std::string what() {
		return DATA_ERROR_PREFIX + error_text;
	}
};

class LogicException : public Exception {
public:
	LogicException(std::string msg) : Exception(msg) {}
	~LogicException() {}
	std::string what() {
		return LOGIC_ERROR_PREFIX + error_text;
	}
};

class DateException : public Exception {
public:
	DateException(std::string msg) : Exception(msg) {}
	~DateException() {}
	std::string what() {
		return DATE_ERROR_PREFIX + error_text;
	}
};

#endif