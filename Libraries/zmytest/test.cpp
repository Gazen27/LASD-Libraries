#include <iostream>

#include "../zlasdtest/test.hpp"
#include "test.hpp"

using namespace std;

void mytest(){

    cout << "WORK IN PROGRESS" << endl;
}

void callMenu(){

    cout << "###############################################################" << endl;
    cout << " ++++++++++++++ WELCOME TO LASD LIBRARIES TEST! ++++++++++++++ " << endl;
    cout << "###############################################################" << endl << endl;

    cout << "Choose a test to start:" << endl;
    cout << "[1] Teacher Test" << endl;
    cout << "[2] Student Test" << endl << endl;
    cout << "[0] Exit" << endl;

    int option;
    cout << endl << "Test selected: ";
    cin >> option;

    switch(option){

        case 1:
        lasdtest();
        break;

        case 2:
        mytest();
        break;

        case 0:
        break;
    }
}
