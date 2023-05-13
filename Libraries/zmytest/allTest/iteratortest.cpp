
#include <iostream>
#include <stdlib.h>
#include <random>

#include "../test.hpp"
#include "../../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"
#include "../../iterator/iterator.hpp"


#define RESET   "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"

using namespace std;

typedef unsigned int uint;
typedef unsigned long ulong;

string ITcorrect = BOLDGREEN "Passed!";
string ITerror = BOLDRED "Failed!";
string ITresult;

default_random_engine ITgenerator(random_device{}());
uniform_int_distribution<uint> ITdist(1, 999);

// STARTING TO DEFINE BINARYTREE TEST FUNCTIONS

//Iterator test 1:
// Testing PreOrder and PostOrder Iterator
void IteratorTest1(){

    ITresult = ITcorrect;

    try{

        
    }
    catch(...){ ITresult = ITerror; }
    cout << endl << "• Test 1: " << ITresult << RESET << endl;
}