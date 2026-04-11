#include <iostream>

void naiveSwap(int a, int b);
void realSwap(int& a, int& b);
void printVars(std::string label, int x, int y);

int main() {
	int x {10};
	int y {20};

	std::cout << "Original values:\n";
	printVars("Before", x, y);

	naiveSwap(x, y);
	std::cout << "After naiveSwap:\n";
	printVars("Naive", x, y);

	realSwap(x, y);
	std::cout << "After realSwap:\n";
	printVars("Real", x, y);

	return 0;
}

void naiveSwap(int a, int b) {
	int temp {a};
	a = b;
	b = temp;
}

void realSwap(int& a, int& b) {
	int temp {a};
	a = b;
	b = temp;
}

void printVars(std::string label, int x, int y) {
	std::cout << label << ": x=" << x << ", y=" << y << '\n';
}
