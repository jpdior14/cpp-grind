#include <iostream>

void stackExample() {
	int local {5};
	std::cout << "Stack var: " << local << '\n';
}

void heapExample() {
	int* heap_var = new int;
	*heap_var = 42;

	std::cout << "Heap var: " << *heap_var << '\n';

	delete heap_var;
	heap_var = nullptr;
}

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
