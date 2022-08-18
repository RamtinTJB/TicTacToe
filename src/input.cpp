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

int get_int_range(const std::string& prompt, int begin, int end) {
	while (1) {
		int input = get_int(prompt);
		if (input >= begin && input <= end) {
			return input;
		}
	}
}

bool get_bool(const std::string& prompt) {
	std::string str;
	while (1) {
		str = get_entry(prompt + " (y/n)");
		if (str == "y" || str == "Y") return true;
		if (str == "n" || str == "N") return false;	
	}
}
