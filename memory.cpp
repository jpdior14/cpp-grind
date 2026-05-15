#include <iostream>

int main() {
	int scores[5] {66, 33, 88, 55, 77};

	std::cout << "=== THE MATRIX ===\n";

	for (int i {0}; i < 5; i++) {
		std::cout << "scores[" << i << "] = " << scores[i]
			  << "	|	Address: " << &scores[i] << '\n';
	}

	std::cout << '\n'

		  << "scores itself: " << scores << '\n'
		  << "&scores[0]:	" << &scores[0] << '\n'
		  << "Are they equal? " << (scores == &scores[0] ? "YES" : "NO") << '\n'

		  << '\n'

		  << "scores + 0 points to: " << scores + 0 << " | Value: " << *(scores + 0) << '\n'
		  << "scores + 1 points to: " << scores + 1 << " | Value: " << *(scores + 1) << '\n'
		  << "scores + 2 points to: " << scores + 2 << " | Value: " << *(scores + 2) << '\n'

		  << '\n'

		  << "scores[2]	" << scores[2] << '\n'
		  << "*(scores + 2)	" << scores[2] << '\n'
		  << "2[scores]	" << 2[scores] << '\n';

	return 0;
}
