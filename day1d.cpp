#include <iostream>
#include <string>

int main() {
	std::string your_name;
	int your_age;

	std::cout << "Enter your name: ";
	std::cin >> your_name;
	std::cout << "And your age? ";
	std::cin >> your_age;

	std::cout << "Yo, " << your_name << "! You are " << your_age << "years old." << '\n'
		  << "In 8 years (China goal), you will be " << your_age + 8 << '\n';

	return 0;
}
