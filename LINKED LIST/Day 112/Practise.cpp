#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    void insertAtBeginning(int data) {
        Node* curr = new Node(data);
        curr->next = head;
        head = curr;
    }

    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "Underflow" << endl;
            return;
        }
        Node* curr = head;
        head = head->next;
        delete curr;
    }

    void insertAtEnd(int data) {
        Node* curr = new Node(data);
        if (head == NULL) {
            head = curr;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = curr;
        curr->next = NULL;
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "Underflow" << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* curr = head;
        Node* prev = NULL;
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        delete curr;
    }

    void insertAtMiddle(int data, int position) {
        Node* newNode = new Node(data);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp; ++i) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Position out of bounds." << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtMiddle(int position) {
        if (head == NULL) {
            cout << "Underflow" << endl;
            return;
        }
        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        Node* prev = NULL;
        for (int i = 0; i < position && temp; ++i) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp) {
            cout << "Position out of bounds." << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    int choice, data, position;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Delete at Beginning\n";
        cout << "3. Insert at End\n";
        cout << "4. Delete at End\n";
        cout << "5. Insert at Middle\n";
        cout << "6. Delete at Middle\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data to insert at beginning: ";
            cin >> data;
            list.insertAtBeginning(data);
            break;
        case 2:
            list.deleteAtBeginning();
            break;
        case 3:
            cout << "Enter data to insert at end: ";
            cin >> data;
            list.insertAtEnd(data);
            break;
        case 4:
            list.deleteAtEnd();
            break;
        case 5:
            cout << "Enter data to insert at middle: ";
            cin >> data;
            cout << "Enter position to insert: ";
            cin >> position;
            list.insertAtMiddle(data, position);
            break;
        case 6:
            cout << "Enter position to delete: ";
            cin >> position;
            list.deleteAtMiddle(position);
            break;
        case 7:
            list.display();
            break;
        case 8:
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
