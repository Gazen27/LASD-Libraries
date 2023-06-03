
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
uniform_int_distribution<uint> Hdist(101, 999);

default_random_engine doubleGenerator(random_device{}());
uniform_real_distribution<double> doubleDist(0.1, 0.9);

// STARTING TO DEFINE HASHTABLE TEST FUNCTIONS

//Hashtable test 1:
// testing CLOSED on INT type
void HashTableTest1(){

    Hresult = Hcorrect;

    try{

        ulong random = Hdist(Hgenerator);

        lasd::HashTableClsAdr<int> table1;
        lasd::HashTableClsAdr<int> table2(std::move(table1));

        if(table1.Size() != 0){ Hresult = Herror; }
        table1.Insert(55);
        table1.Insert(80);
        if(!table1.Exists(55)){ Hresult = Herror; }
        if(table1.Size() != 2){ Hresult = Herror; }

        for(ulong i = 0; i < 50; i++){ table2.Insert(i + 1); }
        table2.Insert(random);
        for(ulong i = 50; i < 100; i++){ table2.Insert(i + 1); }
        if(table2.Size() != 101){ Hresult = Herror; }
        if(!table2.Exists(random)){ Hresult = Herror; }

        lasd::HashTableClsAdr<int> table3(71);
        table3 = table2;
        if(table3.Size() != 101){ Hresult = Herror; }
        if(!table3.Exists(random)){ Hresult = Herror; }

        table1 = std::move(table3);
        if(table3.Size() != 2 || table3.Exists(random)){ Hresult = Herror; }
        if(table1.Size() != 101 || !table1.Exists(random)){ Hresult = Herror; }

        table2 = table1;
        table2.Resize(10);
        if(table2.Size() != 101){ Hresult = Herror; }
        if(!table2.Exists(random)){ Hresult = Herror; }

        table1.Clear();
        if(table1.Size() != 0){ Hresult = Herror; }
        if(table1.Exists(random)){ Hresult = Herror; }
    }
    catch(...){ Hresult = Herror; }
    cout << endl << "• Test 1: " << Hresult << RESET << endl;
}


//Hashtable test 2:
// testing CLOSED on DOUBLE type
void HashTableTest2(){

    Hresult = Hcorrect;

    try{

        double random = Hdist(Hgenerator) + doubleDist(doubleGenerator);

        lasd::HashTableClsAdr<double> table1;
        lasd::HashTableClsAdr<double> table2(std::move(table1));

        if(table1.Size() != 0){ Hresult = Herror; }
        table1.Insert(55.7);
        table1.Insert(80.3);
        if(!table1.Exists(55.7)){ Hresult = Herror; }
        if(table1.Size() != 2){ Hresult = Herror; }

        for(ulong i = 0; i < 50; i++){ table2.Insert(i + 1 + doubleDist(doubleGenerator)); }
        table2.Insert(random);
        for(ulong i = 50; i < 100; i++){ table2.Insert(i + 1 + doubleDist(doubleGenerator)); }
        if(table2.Size() != 101){ Hresult = Herror; }
        if(!table2.Exists(random)){ Hresult = Herror; }

        lasd::HashTableClsAdr<double> table3(71.6);
        table3 = table2;
        if(table3.Size() != 101){ Hresult = Herror; }
        if(!table3.Exists(random)){ Hresult = Herror; }

        table1 = std::move(table3);
        if(table3.Size() != 2 || table3.Exists(random)){ Hresult = Herror; }
        if(table1.Size() != 101 || !table1.Exists(random)){ Hresult = Herror; }

        table2 = table1;
        table2.Resize(10);
        if(table2.Size() != 101){ Hresult = Herror; }
        if(!table2.Exists(random)){ Hresult = Herror; }

        table1.Clear();
        if(table1.Size() != 0){ Hresult = Herror; }
        if(table1.Exists(random)){ Hresult = Herror; }

        for(int i = 0; i < 10; i++){

            table1 = std::move(table2);
            table2 = std::move(table1);
        }
        if(table2.Size() != 101){ Hresult = Herror; }
        if(!table2.Exists(random)){ Hresult = Herror; }
        if(table1.Size() != 0){ Hresult = Herror; }
        if(table1.Exists(random)){ Hresult = Herror; }

    }
    catch(...){ Hresult = Herror; }
    cout << endl << "• Test 2: " << Hresult << RESET << endl;
}


//Hashtable test 3:
// ...
void HashTableTest3(){}


//Hashtable test 4:
// ...
void HashTableTest4(){}


//Hashtable test 5:
// ...
void HashTableTest5(){}


//Hashtable test 6:
// ...
void HashTableTest6(){}