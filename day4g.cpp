#include <iostream>

class Node {
public:
	int data;
	Node* next;

	Node(int val) : data (val),
next(nullptr) {
		std::cout << "Node created with value " << data << '\n';
	}

	~Node() {
		std::cout << "Node with value " << data << " destroyed\n";
	}
};

int main() {
	Node* first = new Node(10);
	Node* second = new Node(20);
	Node* third = new Node(30);

	first->next = second;
	second->next = third;
	third->next = nullptr;

	std::cout << "\nTraversing list:\n";
	Node* current = first;
	while(current != nullptr) {
		std::cout << current->data << " -> ";

		current = current->next;
	}
	std::cout << "nullptr\n";

	delete third;
	delete second;
	delete first;

	return 0;
}
