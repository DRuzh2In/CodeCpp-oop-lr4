#include <iostream>
#include "List.h"
#include "Complex.h"

using namespace std;
int main()
{
    List<Complex> obj;

    Complex complex1 (1,2);
    Complex complex2 (3,4);
    Complex complex3 = Complex().mult(complex1, complex2);
    Complex complex4 = Complex().sum(complex1, complex2);
    Complex complex5 = Complex().sub(complex1, complex2);
    Complex complex6 = Complex().div(complex1, complex2);

    obj.createNode(complex1);
    obj.createNode(complex2);

    cout<<"\n--------------------------------------------------\n";
    cout<<"---------------Displaying All nodes---------------";
    cout<<"\n--------------------------------------------------\n";
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"-----------------Inserting At End-----------------";
    cout<<"\n--------Multiplication of complex numbers---------";
    cout<<"\n--------------------------------------------------\n";
    obj.createNode(complex3);
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"----------------Inserting At Start----------------";
    cout<<"\n--------------Sum of complex numbers--------------";
    cout<<"\n--------------------------------------------------\n";
    obj.insert_start(complex4);
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"-------------Inserting At Position--------------";
    cout<<"\n----------Subtraction of complex numbers----------";
    cout<<"\n--------------------------------------------------\n";
    obj.insert_position(2,complex5);
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"----------------Deleting At Start-----------------";
    cout<<"\n-----------Division of complex numbers------------";
    cout<<"\n--------------------------------------------------\n";
    obj.delete_first();
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"-----------------Deleing At End-------------------";
    cout<<"\n--------------------------------------------------\n";
    obj.delete_last();
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"---------------Deleting At Position---------------";
    cout<<"\n--------------------------------------------------\n";
    obj.delete_position(2);
    obj.display();
    cout<<"\n--------------------------------------------------\n";
    cout<<"--------------Search In List By ID----------------";
    cout<<"\n--------------------------------------------------\n";
    Complex com = obj.search_position(2);
    cout << com;

    return 0;
}
