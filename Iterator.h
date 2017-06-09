#pragma once
#include "Note.h"

template <class T> class Iterator {

private:
    Node<T> *node;

public:
    Iterator(){node = NULL;}
    Iterator(Node<T> *nod) {
        node = nod;
    }

    Iterator<T> operator++ () {
        node = node->next;
        return *this;
    }

    Iterator<T> operator-- () {
        node = node->previos;
        return *this;
    }

    Iterator<T> operator= (const Iterator<T> &it) {
        node = it.node;
        return *this;
    }

    Iterator<T> operator+ (int di) {
        Iterator<T> temp;
        temp.node = node;
        for(int i = 1; i < di; i++) {
            ++temp;
        }
        return temp;
    }

    Iterator<T> operator- (int di)
    {
        Iterator<T> temp;
        temp.node = node;
        for(int i = 1; i < di; i++) {
            --temp;
        }
        return temp;
    }


    void setNode(Node<T> *nod) {
        node = nod;
    }


    Node<T>* getNode() {
        return node;
    }

    T value() {
        return node->v;
    }

};