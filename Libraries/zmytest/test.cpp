#include <iostream>
#include <stdlib.h>
#include <random>

#include "test.hpp"
#include "../zlasdtest/test.hpp"

#define RESET   "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDCYAN    "\033[1m\033[36m"

using namespace std;

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

  /* ************************************************************************ */

void mytest(){

    cout << endl;
    cout << "<><><><><><><> Student Libraries Test <><><><><><><>" << endl;

    // STARTING VECTOR TEST
    cout << endl;
    cout << BOLDCYAN << "+++ Vector test +++" << RESET << endl;
    VectorTest1();
    VectorTest2();
    VectorTest3();
    VectorTest4();

    // STARTING LIST TEST
    cout << endl;
    cout << BOLDCYAN << "+++ List test +++" << RESET << endl;
    ListTest1();
    ListTest2();
    ListTest3();
    ListTest4();

    // STARTING STACK TEST
    cout << endl;
    cout << BOLDCYAN << "+++ Stack test +++" << RESET << endl;
    StackTest1();
    StackTest2();
    StackTest3();
    StackTest4();

    // STARTING QUEUE TEST
    cout << endl;
    cout << BOLDCYAN << "+++ Queue test +++" << RESET << endl;
    QueueTest1();
    QueueTest2();
    QueueTest3();
    QueueTest4();

  /* ************************************************************************ */

    // INFO
    cout << endl << endl << BOLDCYAN << "+++ INFO +++" << RESET << endl;
    cout << endl;
    cout << "In every single test, a lot of different functions are tested," << endl;
    cout << "in order to combine each other and try to stress the structures." << endl;
    cout << endl;
    cout << "Every test and the library itself, are provided by Giovanni Adamo." << endl;
    cout << endl << "Goodbye!" << endl;

  /* ************************************************************************ */

}
