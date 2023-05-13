
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
// Testing PreOrder Iterator
void IteratorTest1(){

    ITresult = ITcorrect;

    try{

        uint isRoot = 9999;
        lasd::List<int> lst;
        for(uint i = 0; i < 50; i++){ lst.InsertAtBack(ITdist(ITgenerator)); }
        lst.InsertAtFront(isRoot);
        lasd::BinaryTreeLnk<int> bt(lst);

        lasd::BTPreOrderIterator<int> it1(bt);
        lasd::BTPreOrderIterator<int> it2(bt);

        ++it1;
        if(*it1 == *it2){ ITresult = ITerror; }

        it1.Reset();
        if(*it1 != isRoot || *it1 != *it2){ ITresult = ITerror; }

        lasd::List<int> elst;
        for(uint i = 0; i < 50; i++){ elst.InsertAtBack(ITdist(ITgenerator)); }
        lasd::BinaryTreeLnk<int> emptytree(elst);

        emptytree.Clear();
        try{
            lasd::BTPreOrderIterator<int> it3(emptytree);
            if(!it3.Terminated()){ ITresult = ITerror; }
        }
        catch(...){ ITresult = ITerror; }

        try{
            for(uint i = 0; i < 100; i++){ ++it2; }
            ITresult = ITerror;    
        }
        catch(...){ }
        if(!it2.Terminated()){ ITresult = ITerror; }

        ///////////////////////////////// TEST ON EMPTY BST
    }
    catch(...){ ITresult = ITerror; }
    cout << endl << "• Test 1: " << ITresult << RESET << endl;
}


// Iterator test 2:
// Testing PostOrderIterator
void IteratorTest2(){

    ITresult = ITerror;

    try{
        // TODO
    }
    catch(...){ ITresult = ITerror; }
    cout << endl << "• Test 2: " << ITresult << RESET << endl;
}


// Iterator test 3:
// Testing InOrderIterator
void IteratorTest3(){

    ITresult = ITerror;

    try{
        // TODO
    }
    catch(...){ ITresult = ITerror; }
    cout << endl << "• Test 2: " << ITresult << RESET << endl;
}


// Iterator test 3:
// Testing BreadthIterator
void IteratorTest4(){

    ITresult = ITerror;

    try{
        // TODO
    }
    catch(...){ ITresult = ITerror; }
    cout << endl << "• Test 2: " << ITresult << RESET << endl;
}