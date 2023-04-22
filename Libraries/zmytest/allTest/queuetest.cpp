
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
// (vec) testing the main functionalities on a QueueVec full of many elements
void QueueTest1(){

    Qresult = Qcorrect;

    try{

        lasd::QueueVec<int> que;
        for(uint i = 0; i < 250; i++){ que.Enqueue(Qdist(Qgenerator)); }
        que.Enqueue(9999);
        for(uint i = 0; i < 250; i++){ que.Enqueue(Qdist(Qgenerator)); }
        for(uint i = 0; i < 250; i++){ que.Dequeue(); }

        lasd::QueueVec<int> otherqueue(std::move(que));
        for(uint i = 0; i < 250; i++){ otherqueue.Enqueue(Qdist(Qgenerator)); }

        if(que.Size() != 0 || !(que.Empty())){ Qresult = Qerror; }
        if(otherqueue.Size() != 501){ Qresult = Qerror; }
        if(otherqueue.Head() != 9999){ Qresult = Qerror; }
    }
    catch(...){ Qresult = Qerror; }

    cout << endl << "• Test 1: " << Qresult << RESET << endl;     

}


// Queue test 2:
// (vec) testing Clear function, some operators and other functionalities
void QueueTest2(){

    Qresult = Qcorrect;

    try{

        lasd::QueueVec<int> que1;
        for(uint i = 0; i < 500; i++){ que1.Enqueue(Qdist(Qgenerator)); }
        que1.Enqueue(5555);

        lasd::QueueVec<int> que2;
        que2 = std::move(que1);
        for(uint i = 0; i < 500; i++){ que2.Enqueue(Qdist(Qgenerator)); }

        lasd::QueueVec<int> que3;
        que3 = que2;
        for(uint i = 0; i < 500; i++){ que3.Dequeue(); }

        que2.Clear();

        if(que1.Size() != 0 || !(que1.Empty())){ Qresult = Qerror; }
        if(que2.Size() != 0 || !(que2.Empty())){ Qresult = Qerror; }
        if(que3.Size() != 501 || que3.Head() != 5555){ Qresult = Qerror; }
    }
    catch(...){ Qresult = Qerror; }

    cout << endl << "• Test 2: " << Qresult << RESET << endl;     
}


// Queue test 3:
// (lst) testing main functionalities, constructors and other functions
void QueueTest3(){

    Qresult = Qcorrect;

    try{

        lasd::QueueLst<int> que;
        for(uint i = 0; i < 50; i++){ que.Enqueue(Qdist(Qgenerator)); }
        que.Enqueue(9999);
        for(uint i = 0; i < 500; i++){ que.Enqueue(Qdist(Qgenerator)); }

        while(que.Head() != 9999){ que.Dequeue(); } //expected size 501 after this

        lasd::QueueLst<int> que2(std::move(que));
        for(uint i = 0; i < 100; i++){ que2.Enqueue(Qdist(Qgenerator)); }

        if(que.Size() != 0 || !(que.Empty())){ Qresult = Qerror; }
        if(que2.Head() != 9999 || que2.Size() != 601){ Qresult = Qerror; }
    }
    catch(...){ Qresult = Qerror; }

    cout << endl << "• Test 3: " << Qresult << RESET << endl; 
}


// Queue test 4:
// (lst) testing assignments, Clear functions and other main functionalities
void QueueTest4(){

    Qresult = Qcorrect;

    try{

        lasd::QueueLst<int> simple;
        for(uint i = 0; i < 100; i++){ simple.Enqueue(Qdist(Qgenerator)); }
        simple.Clear();

        lasd::QueueLst<int> que1;
        for(uint i = 0; i < 100; i++){ que1.Enqueue(Qdist(Qgenerator)); }
        que1.Enqueue(8888);
        for(uint i = 0; i < 100; i++){ que1.Enqueue(Qdist(Qgenerator)); }
        for(uint i = 0; i < 100; i++){ que1.Dequeue(); }

        lasd::QueueLst<int> que2;
        que2 = que1;

        try{

            simple.Dequeue();
            Qresult = Qerror;
        }
        catch(length_error){}

        if(simple.Size() != 0 || !(simple.Empty())){ Qresult = Qerror; }
        if(que1 != que2){ Qresult = Qerror; }
        if(que2.Size() != 101 || que2.Head() != 8888){ Qresult = Qerror; }
    }
    catch(...){ Qresult = Qerror; }

    cout << endl << "• Test 4: " << Qresult << RESET << endl; 
}