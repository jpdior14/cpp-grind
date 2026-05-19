#include <iostream>

void checkIn(int rooms[], int &notepad) {
	rooms[0] = 100;
	rooms[1] = 90;
	notepad = 2;
}

int main() {
	int hotel[10];
	int notepad {0};

	checkIn(hotel, notepad);

	for (int i {0}; i < notepad; i++) {
		std::cout << hotel[i] << '\n';
	}

	return 0;
}
