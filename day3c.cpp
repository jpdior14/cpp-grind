#include <iostream>

int main() {
	int x {42};
	int* ptr = &x;

	std::cout << "Value of x: " << x << '\n'
		  << "Address of x: " << &x << '\n'
		  << "Value of pointer: " << ptr << '\n'
		  << "Value pointed to: " << *ptr << '\n';

	*ptr = 100;
	std::cout << "x is now: " << x << '\n';

	int arr[] {10, 20, 30};
	int* arr_ptr = arr;

	std::cout << "First: " << *arr_ptr << '\n'
		  << "Second: " << *(arr_ptr + 1) << '\n';

	return 0;
}
