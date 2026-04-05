#include <iostream>

struct Node {
	int data;
	Node* next_node;
};

int main() {
	std::cout << "Day 6: The Sunday Link. Two cars, one train.\n";

	Node* head = new Node;
	head->data = 777;

	Node* second_car = new Node;
	second_car->data = 888;
	second_car->next_node = nullptr;

	head->next_node = second_car;

	std::cout << "Car 1's data is: " << head->data << '\n';
	std::cout << "Reading for Car 2 from Car 1's pointer... It is: " << head->next_node->data << '\n';

	delete head;
	delete second_car;

	std::cout << "Both cars destroyed. The heap is at peace. Amen!\n";

	return 0;
}
