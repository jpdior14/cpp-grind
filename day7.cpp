#include <iostream>

struct Node {
	int data;
	Node* next_node;
};

Node* insert_at_front(Node* head, int new_data) {
	Node* new_car = new Node;
	new_car->data = new_data;

	new_car->next_node = head;

	return new_car;
}

void print_train(Node* head) {
	Node* curr = head;
	std::cout << "Current Train: ";

	while (curr != nullptr) {
		std::cout << curr->data << " -> ";
		curr = curr->next_node;
	}
	std::cout << "NULL\n";
}

void nuke_train(Node* head) {
	Node* curr = head;

	while (curr != nullptr) {
		Node* next_target = curr->next_node;

		delete curr;

		curr = next_target;
	}
	std::cout << "Train completely nuked! 0 memory leaks.\n";
}

int main() {
	std::cout << "Day 8: Full Automation. Let's build a massive train.\n";

	Node* head = nullptr;

	head = insert_at_front(head, 100);
	head = insert_at_front(head, 200);
	head = insert_at_front(head, 300);
	head = insert_at_front(head, 999);

	print_train(head);

	nuke_train(head);

	return 0;
}
