#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next_node;
};

int main() {
	cout << "Day 5: The Weekend Grind. I am building my first Node.\n";

	Node* head = new Node;

	head->data = 777;
	head->next_node = nullptr;

	cout << "My Node's memory address is: " << head << "\n";
	cout << "The data inside my Node is: " << head->data << "\n";

	if (head->next_node == nullptr) {
		cout << "The pointer is empty. I fear this is the end of the train.\n";
	}

	delete head;
	head = nullptr;

	cout << "Node destroyed! Memory's secure now\n";
	return 0;
}
