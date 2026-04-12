#include <iostream>

int main() {
	int* dangerous = nullptr;

	if (dangerous != nullptr) {
		std::cout << *dangerous << '\n';
	} else {
		std::cout << "Pointer is null, cannot dereference\n";
	}

	void* leak = new int[100];

	delete[] static_cast<int*>(leak);

	int* dangling;
	{
		int temp {5};
		dangling = &temp;
	}

	return 0;
}
