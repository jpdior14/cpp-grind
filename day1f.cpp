#include <iostream>

int main() {
	int count = 0;

	while (count < 5) {
		std::cout << "Repetition " << count << ": I will NOT skip DSA class\n";
		count++;
	}

	std::cout << "Loop finished. Count is now " << count << '\n';
	return 0;
}
