#include <iostream>
#include "List.h"
#include "Complex.h"

using namespace std;



int main()

{

    List<Complex> list0; // Создаем список елементов типа char



    cout<<"list0.emty: "<<list0.emty()<<endl; // Если список пуст emty вернет 1, иначе 0

    cout<<"list0.size: "<<list0.size()<<endl<<endl;  // Размер списка



    // Вставляем четыре елемента в конец списка

    Complex complex1(1,2);
    list0.pushBack(complex1);

    Complex complex2(3,4);
    list0.pushBack(complex2);

    Complex complex3(5,6);
    list0.pushBack(complex3);

    Complex complex4(7,8);
    list0.pushBack(complex4);

    // Вставляем три елемента в начало списка

    Complex complexNew1(99,98);
    list0.pushFront(complexNew1);

    Complex complexNew2(97,96);
    list0.pushFront(complexNew2);

    Complex complexNew3(95,94);
    list0.pushFront(complexNew3);



    cout<<"list0.emty: "<<list0.emty()<<endl; // Если список пуст emty вернет 1, иначе 0

    cout<<"list0.size: "<<list0.size()<<endl<<endl;  // Размер списка



    // Обход списка с помощью итератора

    Iterator<Complex> itr; // Создаем итератор
    itr = list0.begin(); // устанавливаем его в начало

    for(int i = 0; i < list0.size(); i++)
    {
        Complex ch;
        ch = itr.value();
        cout<<ch<<' ';
        ++itr;
    }
    cout<<endl<<endl;
    cout<<"list0.popBack"<<endl;

    list0.popBack(); // Удаляем последний елемент списка

    // Посмотрим результат удаления

    itr = list0.begin(); //устанавливаем итератор в начало

    for(int i = 0; i < list0.size(); i++)
    {
        Complex ch;
        ch = itr.value();
        cout<<ch<<' ';
        ++itr;
    }

    cout<<endl<<endl;
    cout<<"list0.popFront"<<endl;
    list0.popFront(); // Удаляем первый елемент списка
    itr = list0.begin(); //устанавливаем итератор в начало

    for(int i = 0; i < list0.size(); i++)
    {
        Complex ch;
        ch = itr.value();
        cout<<ch<<' ';
        ++itr;
    }

    cout<<endl<<endl;

    // Перегруженный оператор + и функция value, класса Iterator

    itr = list0.begin(); //устанавливаем итератор в начало

//    cout<<"(itr + 3).value: "<<(itr + 3).value()<<endl<<endl;



//    // Функция isert(T val, Iterator<T> itr)
//
//    cout<<"list0.isert(T val, Iterator<T> itr)"<<endl;
//
//    list0.isert('I', itr + 3);

    itr = list0.begin(); //устанавливаем итератор в начало

    for(int i = 0; i < list0.size(); i++)

    {

        Complex ch;



        ch = itr.value();

        cout<<ch<<' ';



        ++itr;

    }

    cout<<endl<<endl;



    // Функция erase

    cout<<"list0.erase: "<<endl;

    itr = list0.begin(); //устанавливаем итератор в начало

    list0.erase(itr + 4);

    for(int i = 0; i < list0.size(); i++)

    {

        Complex ch;



        ch = itr.value();

        cout<<ch<<' ';



        ++itr;

    }

    cout<<endl<<endl;



    // Удаление всех элементов, функция clear

    cout<<"list0.clear"<<endl;

    list0.clear();

    cout<<"list0.emty: "<<list0.emty()<<endl; // Если список пуст emty вернет 1, иначе 0

    cout<<"list0.size: "<<list0.size()<<endl<<endl;  // Размер списка



    return 0;

}