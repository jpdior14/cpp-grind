#include <iostream>
#include <string>

int main() {
	int age {17};
	int commute_hours {4};

	double first_semester_gpa_goal {4.0};

	bool will_i_quit {false};

	char grade {'A'};
	std::string dream_company {"Tencent"};

	std::cout << "--- ICTU Yaounde to " << dream_company << " Profile ---\n"
		  << "Age: " << age << " | Target Grade: " << grade << '\n'
		  << "Hours wasted complaining: 0 | Hours Commuting: " << commute_hours << '\n';

	if (will_i_quit == false) {
		std::cout << "Mental Status: UNBREAKABLE.\n";
	} else {
		std::cout << "System Error: WE DO NOT QUIT!!!\n";
	}

	return 0;
}
