#include <iostream>
#include <string>

int main() {
	int age {17};
	double height {1.78};
	char grade = 'A';
	std::string name = "Christian";
	bool is_broke = true;

	std::cout << "Name: " << name << '\n'
		  << "Age: " << age << " years old" << '\n'
		  << "Height: " << height << "m" << '\n'
		  << "Grade goal: " << grade << '\n'
		  << "Broke status: " << is_broke << '\n';

	return 0;
}
