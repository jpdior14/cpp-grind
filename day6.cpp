#include <iostream>

struct Node {
	int data;
	Node* next_node;
};

int main() {
	std::cout << "Day 7: The Engine is On. I am traversing the linked list.\n";

	Node* head = new Node;
	head->data = 10;

	Node* second = new Node;
	second->data = 20;
	head->next_node = second;

	Node* third = new Node;
	third->data = 30;
	second->next_node = third;

	third->next_node = nullptr;

	std::cout << "--- STARTING INSPECTION ---\n";

	Node* curr = head;

	while (curr != nullptr) {
		std::cout << "Inspector pointer found cargo: " << curr->data << '\n';

		curr = curr->next_node;
	}

	std::cout << "--- INSPECTION COMPLETE! ---\n";

	delete third;
	delete second;
	delete head;

	std::cout << "Train dismantled. RAM secured for the motherland.\n";
	return 0;
}
