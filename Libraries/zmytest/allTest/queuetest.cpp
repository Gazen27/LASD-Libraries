
#include <iostream>
#include <stdlib.h>
#include <random>

#include "../test.hpp"
#include "../../queue/vec/queuevec.hpp"
#include "../../queue/lst/queuelst.hpp"

#define RESET   "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"

using namespace std;

typedef unsigned int uint;
typedef unsigned long ulong;

string Qcorrect = BOLDGREEN "Passed!";
string Qerror = BOLDRED "Failed!";
string Qresult;

default_random_engine Qgenerator(random_device{}());
uniform_int_distribution<uint> Qdist(1, 999);

// STARTING TO DEFINE QUEUE TEST FUNCTIONS

// Queue test 1:
// ...
void QueueTest1(){}


// Queue test 2:
// ...
void QueueTest2(){}


// Queue test 3:
// ...
void QueueTest3(){}


// Queue test 4:
// ...
void QueueTest4(){}