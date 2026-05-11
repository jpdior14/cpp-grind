#include <iostream>

int main() {
	int scores[5] {85, 92, 78, 90, 88};

	std::cout << "First score: " << scores[0] << '\n'
		  << "Second score: " << scores[1] << '\n';

	scores[2] = 95;
	std::cout << "Updated 3rd score: " << scores[2] << '\n';

	return 0;
}
