#pragma once

#include <iostream>

// Node for the doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    explicit Node(int value)
        : data(value), prev(nullptr), next(nullptr) {}
};

// Doubly linked list class declaration
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void push_front(int value);
    void push_back(int value);

    void pop_front();
    void pop_back();

    void print_forward() const;
    void print_backward() const;

private:
    Node* head;
    Node* tail;
};
