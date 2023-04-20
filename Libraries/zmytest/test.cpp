#include <iostream>

#include "../zlasdtest/test.hpp"

using namespace std;

void callMenu(){

    cout << "###############################################################" << endl;
    cout << " ++++++++++++++ WELCOME TO LASD LIBRARIES TEST! ++++++++++++++ " << endl;
    cout << "###############################################################" << endl << endl;

    cout << "Choose a test to start:" << endl;
    cout << "[1] Teacher Test" << endl;
    cout << "[2] Student Test" << endl;

    int option;
    cout << endl << "Test selected: ";
    switch(option){

        case 1:
        lasdtest();
        break;

        case 2:
        //mytest();
        break;
    }
}

void mytest(){

    cout << "WORK IN PROGRESS" << endl;
}