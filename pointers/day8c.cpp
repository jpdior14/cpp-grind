#include <iostream>

int main() {
	std::cout << "=== MEMORY LEAK SIMULATION ===\n"
		  << "Allocating huge memory blocks without freeing...\n";

	for (int i {0}; i < 10; i++) {
		int* block = new int[1000000];
		std::cout << "Allocated block " << i << " (4MB). NOT freeing.\n";
		// delete[] block;	// Intentionally OMITTED
	}
	std::cout << "If you check System Monitor, you'll see the RAM spike.\n"
		  << "In production, this would crash the server. Chinese DevOps would yell at you.\n";
	return 0;
}
