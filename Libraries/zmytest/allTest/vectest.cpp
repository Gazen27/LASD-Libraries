
#include <iostream>
#include <stdlib.h>
#include <random>

#include "../test.hpp"
#include "../../vector/vector.hpp"

#define RESET   "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"

using namespace std;

typedef unsigned int uint;
typedef unsigned long ulong;

string Vcorrect = BOLDGREEN "Passed!";
string Verror = BOLDRED "Failed!";
string Vresult;

default_random_engine Vgenerator(random_device{}());
uniform_int_distribution<uint> Vdist(1, 999);

// STARTING TO DEFINE VECTOR TEST FUNCTIONS

// Vector test 1:
// testing the resize, front and back functions
void VectorTest1(){

    uint first = Vdist(Vgenerator);
    uint last = Vdist(Vgenerator);

    try{

        lasd::Vector<int> vec(3);
        vec.Resize(100);

        vec[0] = first;
        for(uint i = 1; i <= 98; i++){ vec[i] = Vdist(Vgenerator); }
        vec[99] = last;

        if(vec.Size() == 100){

            if(vec.Front() == first && vec.Back() == last){ Vresult = Vcorrect; }
            else{ Vresult = Verror;}
        }

        else{ Vresult = Verror; }
    }
    catch(...){ Vresult = Verror; }

    cout << endl << "• Test 1: " << Vresult << RESET << endl;
}


// Vector test 2:
// testing the load of many elements, the move constructor and the exist after moving
void VectorTest2(){

    uint find = 2705;
    uint index = Vdist(Vgenerator) - 1;

    try{

        lasd::Vector<int> vec1(999);

        for(uint i = 1; i < 999; i++){ vec1[i] = Vdist(Vgenerator); }
        vec1[index] = find;

        lasd::Vector<int> vec2(std::move(vec1));

        if(vec2.Size() == 999 && vec1.Size() == 0){

            if(vec2.Exists(find)){ Vresult = Vcorrect; }
            else{ Vresult = Verror; }
        }

        else{ Vresult = Verror; }
    }
    catch(...){ Vresult = Verror; }

    cout << endl << "• Test 2: " << Vresult << RESET << endl;
}


// Vector test 3:
// testing the sort function on a vector full of many elements
void VectorTest3(){

    try{

        Vresult = Vcorrect;

        lasd::Vector<int> vec(999);
        for(uint i = 0; i < 999; i++){ vec[i] = Vdist(Vgenerator); }

        vec.Sort();

        uint j = 1;
        for(uint i = 0; i < 998; i++){

            if(vec[i] > vec[j]){ Vresult = Verror; }
            j++;
        }
    }
    catch(...){ Vresult = Verror; }

    cout << endl << "• Test 3: " << Vresult << RESET << endl;
}


// Vector test 4:
// testing the Clear function and the assignments on a vector full of elements
void VectorTest4(){

    try{

        uint find = 1000;
        uint index = Vdist(Vgenerator) - 1;

        lasd::Vector<int> vec(999);
        for(uint i = 0; i < 999; i++){ vec[i] = Vdist(Vgenerator); }
        vec[index] = find;

        lasd::Vector<int> otherVec(vec);
        vec.Clear();

        vec = std::move(otherVec);

        if(otherVec.Size() == 0 && vec.Exists(find)){ Vresult = Vcorrect; }
        else{ Vresult = Verror; }
    }
    catch(...){ Vresult = Verror; }

    cout << endl << "• Test 4: " << Vresult << RESET << endl;
}