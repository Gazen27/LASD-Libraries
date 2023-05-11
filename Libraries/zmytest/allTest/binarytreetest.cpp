
#include <iostream>
#include <stdlib.h>
#include <random>

#include "../test.hpp"
#include "../../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"

#define RESET   "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"

using namespace std;

typedef unsigned int uint;
typedef unsigned long ulong;

string BTcorrect = BOLDGREEN "Passed!";
string BTerror = BOLDRED "Failed!";
string BTresult;

default_random_engine BTgenerator(random_device{}());
uniform_int_distribution<uint> BTdist(1, 999);

// STARTING TO DEFINE BINARYTREE TEST FUNCTIONS

//BinaryTree test 1:
// (lnk)
void BinaryTreeTest1(){

    BTresult = BTcorrect;

    try{ }
    catch(...){ BTresult = BTerror; }

    cout << endl << "• Test 1: " << BTresult << RESET << endl;  
}


//BinaryTree test 2:
// (lnk)
void BinaryTreeTest2(){

    BTresult = BTcorrect;

    try{ }
    catch(...){ BTresult = BTerror; }

    cout << endl << "• Test 2: " << BTresult << RESET << endl;  
}