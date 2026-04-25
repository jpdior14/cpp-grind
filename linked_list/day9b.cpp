#include <iostream>

struct Node {
    int data;
    Node* next;
    Node (int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        std::cout << "LinkedList destroyed. All nodes freed.\n";
    }

    void push_front(int value) {
        Node* new_node = new Node(value);
        new_node->next = head;
        head = new_node;
        std::cout << "push_front(" << value << "): New head.\n";
    }

    void push_back(int value) {
        Node* new_node = new Node(value);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
        std::cout << "push_back(" << value << "): Added to tail.\n";
    }

    bool remove(int value) {
        if (head == nullptr) return false;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            std::cout << "Removed " << value << "(was head).\n";
            return true;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            std::cout << "Removed " << value << ".\n";
            return true;
        }
        std::cout << "Value " << value << " not found.\n";
        return false;
    }

    bool contains(int value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }

    void print() const {
        std::cout << "HEAD -> ";
        Node* current = head;
        while (current != nullptr) {
            std::cout << "[" << current->data << "] -> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }

    int size() const {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    std::cout << "=== CHINESE TECH COMPANY TASK QUEUE (Linked List) ===\n\n";
    LinkedList tasks;

    tasks.push_back(101);
    tasks.push_back(102);
    tasks.push_back(999);
    tasks.push_back(103);

    std::cout << "\nCurrent task queue.\n";
    tasks.print();
    std::cout << "Queue size: " << tasks.size() << "\n\n";

    std::cout << "Working on head: " << tasks.contains(999) << " (exists)\n";
    tasks.remove(999);

    std::cout << "\nAfter completing critical task:\n";
    tasks.print();

    tasks.remove(102);
    std::cout << "\nAfter removing #102:\n";
    tasks.print();

    tasks.remove(404);
    std::cout << "\nFinal queue:\n";
    tasks.print();
    std::cout << "Tasks remaining: " << tasks.size() << '\n'

              << "\n=== INTERVIEWER QUESTION ===\n"
              << "Q: What's the time complexity of front?\nA: O(1)\n"
              << "Q: What about push_back?\nA: O(n) for singly linked list.\n"
              << "Q: How can you make push_back O(1)?\nA:Keep a tail pointer.\n"
              << "      (This is exactly what ByteDance asks.)\n";

    return 0;
}
