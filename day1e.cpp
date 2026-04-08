#include <iostream>

int main() {
	int hours_coded_today;

	std::cout << "So how many hours did you code today? ";
	std::cin >> hours_coded_today;

	if (hours_coded_today >= 3) {
		std::cout << "Valid. China tier grind detected.\n";
	} else if (hours_coded_today >= 1) {
		std::cout << "WEAK!\n...But acceptable for Day 1.\n";
	} else {
		std::cout << "Unacceptable--UTTERLY UNACCEPTABLE!\nLog off and touch grass\n";
	}

	return 0;
}
