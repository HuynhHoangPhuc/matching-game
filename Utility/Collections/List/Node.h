//
// Created by Phuc Huynh Hoang on 11/04/2022.
//

#ifndef MATCHINGGAME_NODE_H
#define MATCHINGGAME_NODE_H


template<typename T>
struct Node {
    T data;
    Node<T> *next;

    explicit Node(T data);

    Node(T data, Node<T> *next);
};

template<typename T>
Node<T>::Node(T data) {
    this->data = data;
    this->next = nullptr;
}

template<typename T>
Node<T>::Node(T data, Node<T> *next) {
    this->data = data;
    this->next = next;
}


#endif //MATCHINGGAME_NODE_H
