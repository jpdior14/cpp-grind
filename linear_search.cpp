#include <iostream>

int linearSearch(int scores[], int size, int target) {
	for (int i {0}; i < size; i++) {
		if (scores[i] == target) {
			return i;
		}
	}
	return -1;
}

int main() {
	int scores[7] {85, 92, 78, 90, 88, 73, 95};

	int target {90};
	int result {linearSearch(scores, 7, target)};

	if (result != -1) {
		std::cout << "Found " << target << " at index " << result << '\n';
	} else {
		std::cout << target << " not found." << '\n';
	}

	return 0;
}
