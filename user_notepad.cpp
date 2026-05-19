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

int main() {
	int hotel[5];
	int notepad {0};

	checkIn(hotel, notepad);

	std::cout << "You entered " << notepad << " scores:\n";
	for (int i {0}; i < notepad; i++) {
		std::cout << hotel[i] << '\n';
	}

	return 0;
}
