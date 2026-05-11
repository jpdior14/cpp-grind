#include <iostream>

int main() {
	int scores[5] {85, 92, 78, 90, 88};

	for (int i {0}; i < 5; i++) {
		std::cout << "Score " << i << " is: " << scores[i] << '\n';
	}

	int sum {0};
	for (int i {0}; i < 5; i++) {
		sum += scores[i];
	};
	std::cout << "Total sum: " << sum << '\n'
		  << "Average: " << sum / 5 << '\n';

	return 0;
}
