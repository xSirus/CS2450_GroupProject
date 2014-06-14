#ifndef MY_REGEX_H
#define MY_REGEX_H
//--------------------------------------------------------------------------------------------------
// Author: Clint Worwood
//--------------------------------------------------------------------------------------------------
#include <regex>
#include <string>
class Regex {
private:
	Regex(){}
public:
	static bool hasMatch(const std::string text, const std::string pattern) {
		std::regex regex_pattern(pattern, std::regex_constants::extended);
		std::smatch matches;
		return std::regex_search(text, matches, regex_pattern);
	}

	static std::string getFirstMatch(const std::string text, const std::string pattern) {
		std::string result;
		std::smatch matches;
		std::regex regex_pattern(pattern, std::regex_constants::extended);
		std::regex_search(text, matches, regex_pattern);
		if(matches.size() > 0) {
			result = matches[0];
		}
		return result;
	}

	static std::string popFirstMatch(const std::string text, const std::string pattern) {
		std::regex regex_pattern(pattern, std::regex_constants::extended);
		return std::regex_replace(text, regex_pattern, std::string(""), std::regex_constants::format_first_only);
	}

	static std::smatch getMatches(const std::string text, const std::string pattern) {
		std::smatch matches;
		std::regex regex_pattern(pattern, std::regex_constants::extended);
		std::regex_search(text, matches, regex_pattern);
		return matches;
	}

	static std::string getMatchGroup(std::smatch& matches, std::size_t group) {
		return matches[group];
	}

	static std::string getMatchGroup(std::smatch&& matches, std::size_t group) {
		return matches[group];
	}
};
#endif