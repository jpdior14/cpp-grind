#include <iostream>

void swap(int &a, int &b) {
	int temp {a};
	a = b;
	b = temp;
}

void bubbleSort(int scores[], int size) {
	for (int pass {0}; pass < size - 1; pass++) {
		bool swapped {false};

		for (int i {0}; i < size - 1 - pass; i++) {
			if (scores[i] > scores[i + 1]) {
				swap(scores[i], scores[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false) {
			break;
		}
	}
}

void printArray(int scores[], int size) {
	for (int i {0}; i < size; i++) {
		std::cout << scores[i] << " ";
	}
	std::cout << '\n';
}

int main() {
	int scores[7] {85, 92, 78, 90, 88, 73, 95};

	std::cout << "Before: ";
	printArray(scores, 7);

	bubbleSort(scores, 7);

	std::cout << "After: ";
	printArray(scores, 7);

	return 0;
}
