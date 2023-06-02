
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

    uint toRemove = 8888;
    uint toFind = 5555;
    uint first = 1000;
    uint last = 9999;

    try{

        lasd::List<int> lst;
        for(uint i = 0; i < 100; i++){ lst.InsertAtFront(Ldist(Lgenerator)); }
        lst.Insert(toRemove);
        for(uint i = 0; i < 100; i++){ lst.InsertAtFront(Ldist(Lgenerator)); }
        lst.Insert(toFind);
        for(uint i = 0; i < 100; i++){ lst.InsertAtFront(Ldist(Lgenerator)); }
        lst.Remove(toRemove);
        for(uint i = 0; i < 100; i++){ lst.InsertAtBack(Ldist(Lgenerator)); }
        lst.InsertAtBack(last);
        for(uint i = 0; i < 100; i++){ lst.InsertAtFront(Ldist(Lgenerator)); }
        lst.InsertAtFront(first);

        if(lst.Exists(toFind) && !(lst.Exists(toRemove))){
            
            if(lst.Front() == first && lst.Back() == last){ Lresult = Lcorrect; }
            else{ Lresult = Lerror; }
        }
        else{ Lresult = Lerror; }
    }
    catch(...){ Lresult = Lerror; }

    cout << endl << "• Test 2: " << Lresult << RESET << endl;
}


// List test 3:
// testing the costructors, assignments and Clear function
void ListTest3(){

    uint key = 9999;
    uint badKey = 8888;

    try{

        lasd::List<int> lst;
        for(uint i = 0; i < 100; i++){ lst.InsertAtBack(Ldist(Lgenerator)); }
        lst.Insert(key);
        lst.Insert(badKey);
        for(uint i = 0; i < 100; i++){ lst.InsertAtBack(Ldist(Lgenerator)); }
        lasd::List<int> lst2(std::move(lst));
        lst2.Remove(badKey);
        lst = lst2;

        lst2.Clear();
        
        if(lst.Size() == 201 && lst2.Size() == 0){

            if(lst.Exists(key) && !(lst.Exists(badKey))){ Lresult = Lcorrect; }
            else{ Lresult = Lerror; }
        }
        else{ Lresult = Lerror; }
    }
    catch(...){ Lresult = Lerror; }

    cout << endl << "• Test 3: " << Lresult << RESET << endl;  
}


// List test 4:
// testing the usage of more than one map together on a list with many elements and move assignment
void ListTest4(){

    Lresult = Lcorrect;

    try{

        lasd::List<int> lst;
        for(uint i = 0; i < 200; i++){ lst.Insert(i); }
        lst.PreOrderMap(IncrementOnList<int>);
        lst.PreOrderMap(DoubleOnList<int>);
        lst.PreOrderMap(DoubleOnList<int>);
        lst.PreOrderMap(IncrementOnList<int>);
        lst.PreOrderMap(IncrementOnList<int>);  

        lst.Remove(402); //should be at index 99

        lasd::List<int> otherlst;
        otherlst = std::move(lst);

        lasd::List<int> finalList;
        finalList.Insert(100);

        if(lst.Size() != 0 || otherlst.Size() != 199){ Lresult = Lerror; }
        if(otherlst[0] != 6 || otherlst[198] != 802){ Lresult = Lerror; }
        if(otherlst.Exists(402)){ Lresult = Lerror; }
        if(finalList.Remove(5555)){ Lresult = Lerror; }
    }
    catch(...){ Lresult = Lerror; }

    cout << endl << "• Test 4: " << Lresult << RESET << endl; 
}



//  Auxiliary
template <typename Data>
void IncrementOnList(Data& e) {
  e++;
}


// Auxiliary
template <typename Data>
void DoubleOnList(Data& e) {
  e *= 2;
}
