#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class Dequeue {
    Node *front;
    Node *rear;
public:
    Dequeue() {
        front = NULL;
        rear = NULL;
    }

    // Push front
    void push_Front(int x) {
        if (front == NULL) {
            front = rear = new Node(x);
            cout << "Pushed " << x << " in front of dequeue\n" << endl;
            return;
        } else {
            Node *temp = new Node(x);
            temp->next = front;
            front->prev = temp;
            front = temp;
            cout << "Pushed " << x << " in front of dequeue\n" << endl;
            return;
        }
    }

    void push_back(int data) {
        if (front == NULL) {
            front = rear = new Node(data);
            cout << "Pushed " << data << " in back of dequeue\n" << endl;
            return;
        } else {
            Node *temp = new Node(data);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            cout << "Pushed " << data << " in back of dequeue\n" << endl;
            return;
        }
    }

    void pop_front() {
        if (front == NULL) {
            cout << "Dequeue is empty" << endl;
        } else {
            Node *temp = front;
             cout << "Popped " << temp->data << " from front of dequeue\n" << endl;
            front = front->next;
            delete temp;
            // greater than one node
            if (front) {
                front->prev = NULL;
            }
            // one node
            else {
                rear = NULL;
            }
        }
    }

    void pop_back() {
        if (front == NULL) {
            cout << "Dequeue is empty" << endl;
        } else {
            Node *temp = rear;
            cout << "Popped " << temp->data << " from back of dequeue\n" << endl;
            rear = rear->prev;
            delete temp;
            // greater than one node
            if (rear) {
                rear->next = NULL;
            }
            // one node
            else {
                rear = NULL;
            }
          
        }
    }

    int start() {
        if (front == NULL)
            return -1;
        else {
            return front->data;
        }
    }

    int end() {
        if (rear == NULL)
            return -1;
        else {
            return rear->data;
        }
    }
};

int main() {

    Dequeue d;
    d.push_Front(1);
    d.push_Front(2);
    d.push_Front(3);
    d.pop_back();
    d.push_back(4);
    d.pop_front();
    cout << d.start() << endl;
}
