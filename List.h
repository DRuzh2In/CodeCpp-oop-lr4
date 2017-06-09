#pragma once

#include "Note.h"
#include "Iterator.h"


template<class T>
class List {

private:
    Node<T> *frontNode; // Указатель на первый узел списка
    Node<T> *backNode;  // Указатель на последний узел списка

public:

    List() {
        frontNode = NULL;
        backNode = NULL;
    }

    ~List() {
        while (1) {
            Node<T> *temp;
            if (frontNode == NULL)
                return;
            if (frontNode == backNode) {
                delete frontNode;
                return;
            }
            temp = backNode->previos;
            delete backNode;
            backNode = temp;
        }
    }

    // Добавляет элемент в конец списка
    void pushBack(T val) {

        if (frontNode == NULL) { // Если список пуст
            frontNode = new Node<T>(val);
            backNode = frontNode;
            backNode->previos = frontNode;
            frontNode->next = backNode;
            backNode->next = NULL;
        } else {
            Node<T> *temp = backNode; // Запоминаем адресс последнего узла
            backNode = new Node<T>(val);
            temp->next = backNode;
            backNode->previos = temp;
            backNode->next = NULL;
        }
    }

    // Добавляет элемент в начало списка
    void pushFront(T val) {

        if (frontNode == NULL){ // Если список пуст
            frontNode = new Node<T>(val);
            backNode = frontNode;
            backNode->previos = frontNode;
            frontNode->next = backNode;
            backNode->next = NULL;
        } else {
            Node<T> *temp = frontNode; // Запоминаем адреосс первого узла
            frontNode = new Node<T>(val);
            temp->previos = frontNode;
            frontNode->next = temp;
            frontNode->previos = NULL;
        }
    }

    void popBack() {
        if (frontNode == NULL) // Если список пуст
            return; // выходим из функции
        if (backNode == NULL){ // Если в списке один элемент
            delete frontNode; // Удаляем первый элемент
            frontNode = NULL;
            return;
        }
        Node<T> *temp = backNode; // Запоминаем адресс последнего узла
        backNode = temp->previos;
        delete temp;
        backNode->next = NULL;
    }


    void popFront() {
        if (frontNode == NULL) // Если список пуст
            return; // выходим из функции
        if (backNode == NULL){ // Если в списке один элемент
            delete frontNode; // Удаляем первый элемент
            frontNode = NULL;
            return;
        }
        Node<T> *temp;
        temp = frontNode; // Запоминаем адресс первого элемента
        frontNode = frontNode->next;
        delete temp;
        frontNode->previos = NULL;
    }


    // Вставляет элемент со значением val, в позицию
    // сразу следующую за позицией, на которую указывает итератор itr
    void isert(T val, Iterator<T> itr) {

        Node<T> *temp;
        if (itr.getNode()->next == NULL){ // Если элемент последний
            temp = backNode;
            backNode = new Node<T>(val);
            temp->next = backNode;
            backNode->previos = temp;
            return;
        }
        temp = itr.getNode()->next;
        Node<T> *insertNode = new Node<T>(val);
        itr.getNode()->next = insertNode;
        insertNode->previos = itr.getNode();
        insertNode->next = temp;
        temp->previos = insertNode;
    }

    // Возвращает итератор на первый элемент списка
    Iterator<T> begin() {
        Iterator<T> it(frontNode);
        return it;
    }

    // Возвращает итератор на последний элемент списка
    Iterator<T> end() {
        Iterator<T> it(backNode);
        return it;
    }

    // Возвращает размер списка
    int size() {
        int count = 0;
        Node<T> *temp = frontNode;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Возвращает true если список пуст, иначе возвращает false
    bool emty() {
        return frontNode == NULL;
    }

    // Удаляет элемент на который ссылается itr
    void erase(Iterator<T> itr) {
        Node<T> *delNode;
        delNode = itr.getNode();
        if (delNode->next == NULL){ // Если элемент последний
            popBack();
            return;
        }
        if (delNode->previos == NULL){ // Если элемент первый
            popFront();
            return;
        }
        Node<T> *n_Node, *p_Node;
        n_Node = delNode->next;
        p_Node = delNode->previos;
        p_Node->next = n_Node;
        n_Node->previos = p_Node;
        delete delNode;
    }

    // Удаляет все элементы списка
    void clear() {
        while (1) {
            Node<T> *temp;
            if (backNode == frontNode) {
                delete frontNode;
                backNode = NULL;
                frontNode = NULL;
                return;
            }
            temp = backNode->previos;
            delete backNode;
            backNode = temp;
        }
    }
};




////
//// Created by vdruzhinin on 6/9/2017.
////
//
//#ifndef CODECPP_OOP_LR4_LIST_H
//#define CODECPP_OOP_LR4_LIST_H
//#include <iostream>
//#include <stdlib.h>
//#include<clocale>
//#include "Complex.h"
//
//using namespace std;
//
//class List {
//
//private:
//    struct list
//    {
//        Complex data;
//        list *next;
//
//    };
//
//public:
//    //функция добавления элемента в заданную позицию pos односвязного списка
//    void add(list *&top,int pos, Complex x)
//    {
//    int j=1;
//    int i; list *pnew, *p=top;
//    pnew=new list; pnew->data=x;
//    if (pos<=1||top==NULL)
//    {
//        pnew->next=top; top=pnew;
//    }
//    else
//    {
//        for(i=1;i<pos-1;i++)
//            if (p->next!=NULL)
//            {
//                p=p->next;
//                j++;
//            }
//        if (pos<=j+1)
//        {
//            pnew->next=p->next; p->next=pnew;
//        }
//    }
//}
//// вспомогательная функция для вывода списка
//void print(list *top)
//{
//    list *p=top;
//    while (p!=NULL)
//    {
//        cout <<p-> data<<' ';
//        p=p->next;
//    }
//    cout<<endl;
//}
////удалить все элементы
//void clrscr(list *&top)
//{
//    if(top==NULL)
//    {
//        cout<<"спиок пуст!"<<endl;
//    }
//    while(top!=NULL)
//    {
//        list *p=top;
//        top=top->next;
//        delete p;
//    }
//}
////удаление элемента с заданной позиции
//void delet(list *&top, int pos2)
//{
//    list *a=top,*b;
//    int i=0;
//    while(a!=NULL)
//    {
//        a=a->next;
//        i++;
//    }
//    if(pos2>i||pos2<1)
//    {
//        cout<<"такой позиции в списке нет!"<<endl;
//    }//проверка на сущ-е позиции
//
//    else
//    {
//        if(pos2==1)
//        {
//            a=top->next;//если эл-т первый
//            top=a;
//        }
//        if (pos2>1)
//        {
//            i=1;//если эл-т не первый
//            a=top;
//            while (i!=pos2-1)
//            {
//                i++; a=a->next;
//            }
//            b=a->next;
//            a->next=b->next;//сдвигаем
//            delete b;
//        }
//    }
//}
//
//};
//
//
//#endif //CODECPP_OOP_LR4_LIST_H
