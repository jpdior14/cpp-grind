#include<iostream>

int main(){
	int a, b;

	std::cout << "Enter a number of your choice: ";
	std::cin >> a;
	std::cout << "And another number: ";
	std::cin >> b;

	int sum = a + b;

	std::cout << "Here's the sum of them: " << sum << '\n';
	return 0;
}

