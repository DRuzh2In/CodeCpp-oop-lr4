#pragma once

template<class Type>
struct Node {
    Type data;
    Node *next;
};

using namespace std;
template<class T>
class List {

private:
    Node<T> *head;
    Node<T> *tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    void createNode(T value) {
        Node<T> *temp = new Node<T>;
        temp->data = value;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
            temp = NULL;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void display() {
        Node<T> *temp = new Node<T>;
        temp = head;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    void insert_start(T value) {
        Node<T> *temp = new Node<T>;
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    void insert_position(int pos, T value) {
        Node<T> *pre = new Node<T>;
        Node<T> *cur = new Node<T>;
        Node<T> *temp = new Node<T>;
        cur = head;
        for (int i = 1; i < pos; i++) {
            pre = cur;
            cur = cur->next;
        }
        temp->data = value;
        pre->next = temp;
        temp->next = cur;
    }

    void delete_first() {
        Node<T> *temp = new Node<T>;
        temp = head;
        head = head->next;
        delete temp;
    }

    void delete_last() {
        Node<T> *current = new Node<T>;
        Node<T> *previous = new Node<T>;
        current = head;
        while (current->next != NULL) {
            previous = current;
            current = current->next;
        }
        tail = previous;
        previous->next = NULL;
        delete current;
    }

    void delete_position(int pos) {
        Node<T> *current = new Node<T>;
        Node<T> *previous = new Node<T>;
        current = head;
        for (int i = 1; i < pos; i++) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
    }

    T search_position(int pos) {
        Node<T> *current = new Node<T>;
        Node<T> *previous = new Node<T>;
        current = head;
        for (int i = 1; i < pos; i++) {
            if(current == NULL ){
                throw exception();
            }
            previous = current;
            current = current->next;
        }
        return current->data;
    }
};
