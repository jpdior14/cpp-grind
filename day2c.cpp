#include <iostream>

int main() {
	const int ARRAY_SIZE {5};
	int grades[ARRAY_SIZE] {90, 85, 78, 92, 88};

	std::cout << "First grade: " << grades[0] << '\n'
		  << "Third grade: " << grades[2] << '\n'
		  << "Last grade: " << grades[4] << '\n';

	int sum {0};
	for (int grade : grades) {
		sum += grade;
	}

	double average {static_cast<double>(sum) / ARRAY_SIZE};
	std::cout << "Average: " << average << '\n';

	return 0;
}
