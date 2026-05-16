#include <iostream>

const int MAX = 10;

void enterScores(int scores[], int &count) {
	int numScores;
	std::cout << "How many scores do you want to enter? (MAX 10)\n";
	for (int i {0}; i < numScores; i++) {
		std::cin >> scores[count+i];
	}
	count += numScores;
}

void displayScores(const int scores[], int count) {
	for (int i {0}; i < count; i++) {
		std::cout << scores[i];
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int scores[], int count) {
	for (int pass {0}; pass < count - 1; pass++) {
		bool swapped {false};

		for (int i {0}; i < count - 1 - pass; i++) {
			if (scores[i] > scores[i+1]) {
				swap(&scores[i], &scores[i+1]);
				swapped = true;
			}
		}

		if (swapped == false) {
			break;
		}
	}
}

int linearSearch(const int scores[], int count, int target) {
	for (int i {0}; i < count; i++) {
		if (scores[i] == target) {
			return i;
		}
	}
	return -1;
}

void showStats(const int scores[], int count) {
	int sum {0};
	for (int i {0}; i < count; i++) {
		sum += scores[i];
	}

	int avg {sum / count};

	int high {scores[0]};
	for (int i {1}; i < count; i++) {
		if (scores[i] > scores[i-1]) {
			high = scores[i];
		}
	}

	int low {scores[0]};
	for (int i {1}; i < count; i++) {
		if (scores[i] < scores[i-1]) {
			low = scores[i];
		}
	}

	int ct {0};
	for (int i {0}; i < count; i++) {
		if (scores[i] >= 80) {
			ct++;
		}
	}

	std::cout << "Sum: " << sum << "\nAverage: " << avg << "\nHighest: " << high << "\nLowest: " << low << "Count >= 80: " << ct << '\n';
}

void printMenu() {
	std::cout << "\n=== STUDENT GRADE SYSTEM===\n"
		  << "1. Enter scores\n"
		  << "2. Display scores\n"
		  << "3. Sort scores\n"
		  << "4. Search score\n"
		  << "5. Statistics:\n"
		  << "6. Exit\n"
		  << "Choice: ";
}

int main() {
	int scores[MAX];
	int count {0};
	int choice;
	do {
		printMenu();
		std::cin >> choice;

		switch (choice) {
			case 1:
				enterScores(scores, count);
				break;
			case 2:
				if (count == 0) {
					std::cout << "No scores entered yet!\n";
				} else {
					displayScores(scores, count);
				} break;
			case 3:
				if (count == 0) {
					std::cout << "No scores entered yet!\n";
				} else {
					bubbleSort(scores, count);
					std::cout << "Sorted.\n";
				} break;
			case 4:
				if (count == 0) {
					std::cout << "No scores to search!\n";
				} else {
					int target;
					std::cout << "Enter to find: ";
					std::cin >> target;
					int result {linearSearch(scores, count, target)};
					if (result != -1) {
						std::cout << "Found " << target << " at " << result << '\n';
					} else {
						std::cout << "Not found!\n";
					}
				} break;
			case 5:
				if (count == 0) {
					std::cout << "No scores yet!\n";
				} else {
					showStats(scores, count);
				} break;
			case 6:
				std::cout << "Goodbyeee!\n";
				break;
			default:
				std::cout << "Invalid! Try again...\n";
		}
	} while (choice != 6);

	return 0;
}
