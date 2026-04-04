#include <iostream>
using namespace std;

int main() {
	cout << "Day 4: I'm leaving the Stack. I'm conquering the HEAP.\n";
	int* heap_pointer = new int;

	*heap_pointer = 88888888;

	cout << "I requested Heap memory. It lives at address: " << heap_pointer << "\n";
	cout << "The lucky data inside is: " << *heap_pointer << "\n";

	delete heap_pointer;

	heap_pointer = nullptr;

	cout << "Memory freed! Pointer neutralized. No memory leaks here, bruh\n";

	return 0;
}
