#include <iostream>

int linearSearch(int scores[], int size, int target) {
	for (int i {0}; i < size; i++) {
		if (scores[i] == target) {
			return i;
		}
	}
	return -1;
}

void swap(int &a, int &b) {
	int temp {a};
	a = b;
	b = temp;
}

void bubbleSort(int scores[], int size) {
	for (int pass; pass < size - 1; pass++) {
		bool swapped {false};

		for (int i {0}; i <= size - 1 - pass; i++) {
			if (scores[i] > scores[i+1]) {
				swap(scores[i], scores[i+1]);
			}
			swapped = true;
		}

		if (swapped == false) {
			break;
		}
	}
}

void printArray (int scores[], int size) {
	for (int i {0}; i < size; i++) {
		std::cout << scores[i] << " ";
	}
}

int main() {
	int scores[7] {66, 33, 88, 55, 88, 44, 77};
	int target;

	std::cout << "Before: ";
	printArray(scores, 7);
	std::cout << "\nEnter a target score: ";
	std::cin >> target;

	int result = {linearSearch(scores, 7, target)};
	if (result != -1) {
		std::cout << "Found " << target << " at index " << result << '\n';
	} else {
		std::cout << target << " not found.\n";
	}

	std::cout << "After: ";
	bubbleSort(scores, 7);
	printArray(scores, 7);

	std::cout << "\nAnd to prove linear search still works, let's run it again!\n";
	result = linearSearch(scores, 7, target);
	if (result != -1) {
		std::cout << "Found " << target << " at index " << result << '\n';
	} else {
		std::cout << target << " not found.\n";
	}

	return 0;
}
