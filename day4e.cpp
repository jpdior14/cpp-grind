#include <iostream>
#include <string>

struct Student {
	std::string name;
	int age;
	double gpa;
	bool is_international;
};

void printStudent(const Student& s) {
	std::cout << "Name: " << s.name << '\n'
		  << "Age: " << s.age << '\n'
		  << "GPA: " << s.gpa << '\n'
		  << "International: " << (s.is_international ? "Yes" : "No") << '\n';
}

Student createChristian() {
	Student christian;
	christian.name = "Christian";
	christian.age = 17;
	christian.gpa = 4.0;
	christian.is_international = true;
	return christian;
}

int main() {
	Student cameroon_dev;
	cameroon_dev.name = "Christian";
	cameroon_dev.age = 17;
	cameroon_dev.gpa = 3.9;
	cameroon_dev.is_international = true;

	Student china_candidate {
		"Future Tencent Engineer",
		25,
		3.8,
		true
	};

	printStudent(cameroon_dev);
	std::cout << "---\n";
	printStudent(china_candidate);

	Student cohort[3] = {
		{"Alice", 20, 3.5, false},
		{"Bob", 21, 3.2, false},
		{"Christian", 17, 4.0, true}
	};

	std::cout << "\nCohort average age: ";
	int total_age = 0;
	for (const auto& student : cohort) {
		total_age += student.age;
	}
	std::cout << total_age / 3.0 << '\n';

	return 0;
}
