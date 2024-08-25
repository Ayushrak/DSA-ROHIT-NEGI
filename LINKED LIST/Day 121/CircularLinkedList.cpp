#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Function to insert a new node at the end of the circular linked list
    void insert(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Function to display the circular linked list
    void display() {
        if (!head) {
            std::cout << "Circular Linked List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        std::cout << std::endl;
    }
};

int main() {
    CircularLinkedList cll;

    // Inserting elements into the circular linked list
    cll.insert(1);
    cll.insert(2);
    cll.insert(3);
    cll.insert(4);

    // Displaying the circular linked list
    std::cout << "Circular Linked List: ";
    cll.display();
    cll.insert(6);
    cll.display();
    return 0;
}
