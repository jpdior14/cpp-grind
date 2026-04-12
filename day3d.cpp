#include <iostream>

int main() {
	stackExample();
	heapExample();

	int* big_array = new int[1000];
	big_array[0] = 1;
	big_array[999] = 999;

	delete[] big_array;
	big_array = nullptr;

	std::cout << "Memory managed correctly! (no leaks)\n";
	return 0;
}
