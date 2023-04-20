
#include <iostream>

using namespace std;

void VectorInt(){

    cout << endl << ">>>>>>>>>>   INTEGER VECTOR   <<<<<<<<<<" << endl << endl;

    lasd::Vector<int> vec(3);
    cout << "> Size of the Vector (expected 3): " << vec.Size() << endl;
}


void VectorDouble(){

    cout << endl << "DOUBLE VECTOR" << endl << endl;
    
    lasd::Vector<double> vec(7);
    cout << "> Size of the Vector (expected 7): " << vec.Size() << endl;
}


void VectorString(){

    cout << endl << "STRING VECTOR" << endl << endl;

    lasd::Vector<string> vec(5);
    cout << "> Size of the Vector (expected 5): " << vec.Size() << endl;
}


void VectorTestStart(){

    cout << endl;
    cout << "######################################################" << endl;
    cout << endl << "++++++++++++++++++++ VECTOR TEST ++++++++++++++++++++" << endl << endl;
    cout << "######################################################" << endl;
   
    VectorInt();
    VectorDouble();
    VectorString();

    cout << endl;
    cout << "######################################################" << endl;
    cout << endl;
}