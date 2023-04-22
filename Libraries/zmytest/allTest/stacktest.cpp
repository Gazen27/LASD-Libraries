
#include <iostream>
#include <stdlib.h>
#include <random>

#include "../test.hpp"
#include "../../stack/vec/stackvec.hpp"
#include "../../stack/lst/stacklst.hpp"

#define RESET   "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"

using namespace std;

typedef unsigned int uint;
typedef unsigned long ulong;

string Scorrect = BOLDGREEN "Passed!";
string Serror = BOLDRED "Failed!";
string Sresult;

default_random_engine Sgenerator(random_device{}());
uniform_int_distribution<uint> Sdist(1, 999);

// STARTING TO DEFINE LIST TEST FUNCTIONS

// Stack test 1:
// (vec) testing all the main function on a stack full of many elements
void StackTest1(){

    uint find = 0;
    uint maxSize = Sdist(Sgenerator);

    try{

        lasd::StackVec<int> stk;
        for(uint i = 0; i < maxSize; i++){

            find = Sdist(Sgenerator);
            stk.Push(find);
        }

        lasd::StackVec<int> stk2(std::move(stk));

    }
    catch(...){ Sresult = Serror; }
}