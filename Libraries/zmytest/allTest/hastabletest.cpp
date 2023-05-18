
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
// ...
void HashtableTest1(){}


//Hashtable test 2:
// ...
void HashtableTest2(){}


//Hashtable test 3:
// ...
void HashtableTest3(){}


//Hashtable test 4:
// ...
void HashtableTest4(){}
