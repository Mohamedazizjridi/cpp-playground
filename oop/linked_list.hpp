#pragma once

#include <iostream>

// Node structure for doubly linked list
template <typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(const T& value)
        : data(value), prev(nullptr), next(nullptr) {}
};

// Doubly linked list class
template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();

    void print_forward() const;
    void print_backward() const;

    bool empty() const;
    size_t size() const;

private:
    Node<T>* head;
    Node<T>* tail;
    size_t length;
};

// Include implementation
#include "linkedlist.cpp"
