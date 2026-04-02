#include <iostream>
using namespace std;

int main() {
	int age;
	cout << "Hey, how old are u?\n";
	cin >> age;
	if (age < 18) {
		cout << "Bro is a literal prodigy.\n";
	} else if (age == 18) {
		cout << "Welcome to adulthood, lock in!\n";
	} else {
		cout << "Unc status. Too late for you lolll\n";
	}

	for (int i = 0; i < age; i++) {
		cout << "I'm gonna be the BEST in the tech industry!\n";
	}

	return 0;
}
