#pragma once
#include <cstdio>

template <class T> class Node {

public:

    T v;
    Node<T> *next;
    Node<T> *previos;

    Node() {
        previos = next = NULL;
    }

    Node(T val) {
        previos = next = NULL;
        v = val;
    }

    Node(const Node *nod) {
        v = nod->v;
        next = nod->next;
        previos = nod->previos;
    }
};