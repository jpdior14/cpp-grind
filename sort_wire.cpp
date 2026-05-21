#include <iostream>

void checkIn(int rooms[], int &notepad) {
	int num;
	std::cout << "How many scores? (max 5): ";
	std::cin >> num;

	std::cout << "Enter " << num << " scores:\n";
	for (int i {0}; i < num; i++) {
		std::cin >> rooms[i];
	}

	notepad = num;
}

void displayScores(int rooms[], int notepad) {
	for (int i {0}; i < notepad; i++) {
		std::cout << rooms[i] << " ";
	}
	std::cout << '\n';
}

void bubbleSort(int rooms[], int notepad) {
	for (int pass {0}; pass < notepad - 1; pass++) {
		bool swapped = false;
		for (int i {0}; i < notepad - 1 - pass; i++) {
			if (rooms[i] > rooms[i+1]) {
				int temp = rooms[i];
				rooms[i] = rooms[i+1];
				rooms[i+1] = temp;
				swapped = true;
			}
		}
		if (swapped == false) break;
	}
}

int main() {
	int hotel[5];
	int notepad {0};

	checkIn(hotel, notepad);

	std::cout << "Before: ";
	displayScores(hotel, notepad);

	bubbleSort(hotel, notepad);

	std::cout << "After: ";
	displayScores(hotel, notepad);

	return 0;
}
