#include <iostream>
#include <string>
#include "textlib.h"

int main() {

	std::string str = "aaa bbb ccc ddd eee fff ggg hhh iii jjj kkk";
	std::string part = "kkk";

	std::cout << "String: " << str << std::endl;
	std::cout << "Part: \"" << part << "\"" << std::endl;

	bool searchingStatus = RabinTextSearching(str, part);

	if (searchingStatus) {

		std::cout << "The part FOUND in the string";
	}
	else {

		std::cout << "Part NOT found in the string";
	}
	std::cout << std::endl;

	return 0;
}