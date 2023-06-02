
#include <iostream>
#include <stdlib.h>
#include <random>

#include "../test.hpp"
#include "../../hashtable/hashtable.hpp"
#include "../../hashtable/clsadr/htclsadr.hpp"
#include "../../hashtable/opnadr/htopnadr.hpp"

#define RESET   "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"

using namespace std;

typedef unsigned int uint;
typedef unsigned long ulong;

string Hcorrect = BOLDGREEN "Passed!";
string Herror = BOLDRED "Failed!";
string Hresult;

default_random_engine Hgenerator(random_device{}());
uniform_int_distribution<uint> Hdist(1, 999);

// STARTING TO DEFINE HASHTABLE TEST FUNCTIONS

//Hashtable test 1:
// testing CLOSED on INT type
void HashTableTest1(){

    Hresult = Hcorrect;

    try{

        lasd::HashTableClsAdr<int> table1;
        lasd::HashTableClsAdr<int> table2(std::move(table1));
        if(table1.Size() != 0){ Hresult = Herror; }

    }
    catch(...){ Hresult = Herror; }
    cout << endl << "• Test 1: " << Hresult << RESET << endl;
}


//Hashtable test 2:
// ...
void HashtableTest2(){}


//Hashtable test 3:
// ...
void HashtableTest3(){}


//Hashtable test 4:
// ...
void HashtableTest4(){}


//Hashtable test 5:
// ...
void HashtableTest5(){}


//Hashtable test 6:
// ...
void HashtableTest6(){}