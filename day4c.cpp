#include <iostream>
using namespace std;

int main() {
	cout << "Day 2: I am the Landlord of my RAM.\n";

	int array[4] = {2, 7, 11, 15};

	cout << "The value at index 0 is: " << array[0] << "\n";

	cout << "The physical RAM address of index 0 is: " << &array[0] << "\n";
	cout << "The physical RAM address of index 1 is: " << &array[1] << "\n";

	return 0;
}
