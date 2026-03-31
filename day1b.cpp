#include <iostream>
using namespace std;

int main() {
	double x;

	int count = 0;
	int positive_count = 0;

	while (true) {

		cout << "\n=== New Calculation ===\n";
		cout << "Enter a number (Type 999 to quit): ";
		cin >> x;

		if (x == 999) {
			cout << "----------------------------\n";
			cout << "TOTAL NUMBERS ANALYZED: " << count << endl;
			cout << "POSITIVE NUMBERS FOUND: " << positive_count << endl;
			cout << "Shutting down ... Bye!\n";
			break;
		}

		count = count + 1;

		if (x > 0) {
			cout << "Result: Positive\n";
			positive_count += 1;
		} else if (x < 0) {
			cout << "Result: Negative\n";
		} else {
			cout << "Result: Zero\n";
		}
	}

	return 0;
}
