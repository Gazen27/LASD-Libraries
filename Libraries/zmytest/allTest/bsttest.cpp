
#include <iostream>
#include <stdlib.h>
#include <random>

#include "../test.hpp"
#include "../../bst/bst.hpp"

#define RESET   "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"

using namespace std;

typedef unsigned int uint;
typedef unsigned long ulong;

string BSTcorrect = BOLDGREEN "Passed!";
string BSTerror = BOLDRED "Failed!";
string BSTresult;

default_random_engine BSTgenerator(random_device{}());
uniform_int_distribution<uint> BSTdist(1, 999);

// STARTING TO DEFINE BINARYSEARCHTREE TEST FUNCTIONS

//BinarySearchTree test 1:
//...
void BinarySearchTreeTest1(){

    BSTresult = BSTcorrect;

    try{ }
    catch(...){ BSTresult = BSTerror; }

    cout << endl << "• Test 1: " << BSTresult << RESET << endl;  
}


//BinarySearchTree test 2:
//...
void BinarySearchTreeTest2(){

    BSTresult = BSTcorrect;

    try{ }
    catch(...){ BSTresult = BSTerror; }

    cout << endl << "• Test 2: " << BSTresult << RESET << endl;  
}


//BinarySearchTree test 3:
//...
void BinarySearchTreeTest3(){

    BSTresult = BSTcorrect;

    try{ }
    catch(...){ BSTresult = BSTerror; }

    cout << endl << "• Test 3: " << BSTresult << RESET << endl;  
}


//BinarySearchTree test 4:
//...
void BinarySearchTreeTest4(){

    BSTresult = BSTcorrect;

    try{ }
    catch(...){ BSTresult = BSTerror; }

    cout << endl << "• Test 4: " << BSTresult << RESET << endl;  
}