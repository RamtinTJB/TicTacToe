#include "input.h"

namespace {
	bool is_num(const std::string& str) {
		return str.find_first_not_of("1234567890") == std::string::npos;
	}
}

std::string get_entry(const std::string& prompt) {
	std::string str;

	while (str.compare("") == 0) {
		std::cout << prompt << ": ";
		std::getline(std::cin, str);
	}

	return str;
}

int get_int(const std::string& prompt) {
	std::string str;
	int res;

	while (1) {
		str = get_entry(prompt);
		if (is_num(str)) {
			res = std::stoi(str);
			return res;
		}
	}
}
