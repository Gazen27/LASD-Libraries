
#include <iostream>
#include <stdlib.h>
#include <random>

#include "../test.hpp"
#include "../../list/list.hpp"

#define RESET   "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"

using namespace std;

typedef unsigned int uint;
typedef unsigned long ulong;

string Lcorrect = BOLDGREEN "Passed!";
string Lerror = BOLDRED "Failed!";
string Lresult;

default_random_engine Lgenerator(random_device{}());
uniform_int_distribution<uint> Ldist(1, 999);

// STARTING TO DEFINE LIST TEST FUNCTIONS

// List test 1:
// testing Exists, InsertAtBack, InsertAtFront, RemoveFromFront with many elements
void ListTest1(){

    uint find = 1000;
    uint index = Ldist(Lgenerator) - 1;

    try{

        lasd::List<int> lst;
        for(uint i = 0; i < 500; i++){ lst.InsertAtFront(Ldist(Lgenerator)); }
        for(uint i = 0; i < 500; i++){ lst.InsertAtBack(Ldist(Lgenerator)); }
        for(uint i = 0; i < 100; i++){ lst.RemoveFromFront(); }
        for(uint i = 0; i < 50; i++){ lst.InsertAtFront(Ldist(Lgenerator)); }
        for(uint i = 0; i < 50; i++){ lst.InsertAtBack(Ldist(Lgenerator)); }
        lst[index] = find;
    
        if(lst.Size() == 1000 && lst.Exists(find)){ Lresult = Lcorrect; }
        else{Lresult = Lerror; }
    }
    catch(...){  Lresult = Lerror;}

    cout << endl << "• Test 1: " << Lresult << RESET << endl;
}


// List test 2:
// testing Front, Back, Insert and Remove
void ListTest2(){

    
}


// List test 3:
// 
void ListTest3(){}


// List test 4:
// 
void ListTest4(){}