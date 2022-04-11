//
// Created by Phuc Huynh Hoang on 11/04/2022.
//

#ifndef MATCHINGGAME_LIST_H
#define MATCHINGGAME_LIST_H

#include <stdexcept>

#include "Node.h"


template<typename T>
struct List {
private:
    Node<T> *_head{};
    Node<T> *_tail{};
    int _size{};

public:
    int size();

    bool isEmpty();

    T front();

    T back();

    int index_of(const T &element);

    void push_back(const T &element);

    void push_front(const T &element);

    void pop_back();

    void pop_front();
};

template<typename T>
int List<T>::size() {
    return _size;
}

template<typename T>
bool List<T>::isEmpty() {
    return _size == 0;
}

template<typename T>
T List<T>::front() {
    if (isEmpty()) {
        throw std::runtime_error("Empty list");
    }
    return _head->data;
}

template<typename T>
T List<T>::back() {
    if (isEmpty()) {
        throw std::runtime_error("Empty list");
    }
    return _tail->data;
}

template<typename T>
inline int List<T>::index_of(const T &element) {
    if (isEmpty()) {
        throw std::runtime_error("Empty list");
    }

    int index{};
    auto current = _head;

    while (current != nullptr && current->next != nullptr && current->data != element) {
        current = current->next;
        index += 1;
    }

    return current->data == element ? index : -1;
}

template<typename T>
void List<T>::push_back(const T &element) {
    if (isEmpty()) {
        _head = _tail = new Node<T>(element);
    } else {
        _tail->next = new Node<T>(element);
        _tail = _tail->next;
    }

    _size += 1;
}

template<typename T>
void List<T>::push_front(const T &element) {
    if (isEmpty()) {
        _head = _tail = new Node<T>(element);
    } else {
        _head = new Node<T>(element, _head);
    }

    _size += 1;
}

template<typename T>
void List<T>::pop_back() {
    if (isEmpty()) {
        throw std::runtime_error("Empty list");
    }

    auto current = _head;
    while (current != nullptr &&
           current->next != nullptr &&
           current->next->data != _tail->data) {
        current = current->next;
    }

    _tail = current;
    _size -= 1;
    if (isEmpty()) _head = nullptr;
}

template<typename T>
void List<T>::pop_front() {
    if (isEmpty()) {
        throw std::runtime_error("Empty list");
    }

    _head = _head->next;
    _size -= 1;
    if (isEmpty()) _tail = nullptr;
}


#endif //MATCHINGGAME_LIST_H
