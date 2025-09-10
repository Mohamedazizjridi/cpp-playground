#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int value)
      : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList(): head(nullptr), tail(nullptr) {}

    void push_front(int value) {
        Node* newnode = new Node(value);
        if (!head) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void push_back(int value) {
        Node* newnode = new Node(value);
        if (!tail) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    void pop_front() {
        if (!head) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void pop_back() {
        if (!tail) return;
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void print_forward() const {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void print_backward() const {
        Node* curr = tail;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        Node* cur = head;
        while (cur) {
            Node* nextnode = cur->next;
            delete cur;
            cur = nextnode;
        }
    }
};

int main() {
    DoublyLinkedList dll;

    dll.push_back(10);
    dll.push_back(20);
    dll.push_front(5);
    dll.push_front(1);

    cout << "Forward: ";
    dll.print_forward();   

    cout << "Backward: ";
    dll.print_backward();  

    dll.pop_front();      // removes 1
    dll.pop_back();       // removes 20

    cout << "After pops (forward): ";
    dll.print_forward();  // should output: 5 10

    return 0;
}
