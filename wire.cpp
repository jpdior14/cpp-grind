#include <iostream>

void checkIn(int rooms[], int &notepad) {
	int num;
	std::cout << "How many scores (max 5): ";
	std::cin >> num;

	std::cout << "Enter " << num << " scores:\n";
	for (int i {0}; i < num; i++) {
		std::cin >> rooms[i];
	}

	notepad = num;
}

void searchScore(int rooms[], int notepad) {
	int target;
	std::cout << "Enter score to find: ";
	std::cin >> target;

	for (int i {0}; i < notepad; i++) {
		if (rooms[i] == target) {
			std::cout << "Found at index " << i << '\n';
			return;
		}
	}
	std::cout << "Not found.\n";
}

int main() {
	int hotel[5];
	int notepad {0};

	checkIn(hotel, notepad);
	searchScore(hotel, notepad);

	return 0;
}
