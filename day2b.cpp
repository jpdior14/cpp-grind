#include <iostream>
#include <string>

int addYears(int current_age, int years_to_add);
void printStatus(std::string name, int age, bool is_broke);
bool canEnterChinaMarket(int years_experience);

int main() {
	int my_age {17};
	std::string my_name = {"Christian"};

	int future_age {addYears(my_age, 8)};
	printStatus(my_name, my_age, true);

	std::cout << "At age " << future_age << ", China eligibility: ";
	if (canEnterChinaMarket(future_age - my_age)) {
		std::cout << "YES!\n";
	} else {
		std::cout << "Oh HELL Noo-ooh-awww!!!\n";
	}

	return 0;
}

int addYears(int current_age, int years_to_add) {
	return current_age + years_to_add;
}

void printStatus(std::string name, int age, bool is_broke) {
	std::cout << "=== STATUS REPORT ===\n"
		  << "Name: " << name << '\n'
		  << "Current Age: " << age << '\n'
		  << "Broke Status: " << (is_broke ? "Yes" : "No") << '\n'
		  << "=====================\n";
}

bool canEnterChinaMarket(int years_experience) {
	return years_experience >= 3;
}
