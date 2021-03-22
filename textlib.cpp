#include "textlib.h"
#include <vector>
#include <string>

void CreatePiArray(std::vector <int>& pi, std::string str) {

	int j = 0, i = 1;

	while (i < str.length()) {

		if (str[i] == str[j]) {

			pi[i] = j + 1;
			i++;
			j++;
		}
		else if (j == 0) {

			pi[i] = 0;
			i++;
		}
		else {

			j = pi[j - 1];
		}
	}
}

bool KnuthMorrisPrattTextSearching(std::string str, std::string part) {

	std::vector <int> pi(str.length());
	CreatePiArray(pi, str);

	int strIndex = 0, partIndex = 0;

	while (strIndex < str.length()) {

		if (str[strIndex] == part[partIndex]) {

			strIndex++;
			partIndex++;

			if (partIndex == part.length()) {

				return true;
			}
		}
		else if (partIndex == 0) {

			strIndex++;

			if (strIndex == str.length()) {

				return false;
			}
		}
		else {

			partIndex = pi[partIndex - 1];
		}

	}
}