#include <iostream>
using namespace std;

int main() {
	cout << "Day 3: I am unlocking the true power of Pointers.\n";

	int my_score = 100;
	int* pointer_to_score = &my_score;

        cout << "My actual score is: " << my_score << "\n";
        cout << "The memory address of my score is: " << pointer_to_score << "\n";

        cout << "Breaking into the address to find the value... It is " << *pointer_to_score << "\n";

        *pointer_to_score = 999;

        cout << "I hacked my own RAM. My new score is: " << my_score << "\n";

	return 0;
}
