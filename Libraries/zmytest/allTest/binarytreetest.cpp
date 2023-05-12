
#include <iostream>
#include <stdlib.h>
#include <random>

#include "../test.hpp"
#include "../../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"

#define RESET   "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"

using namespace std;

typedef unsigned int uint;
typedef unsigned long ulong;

string BTcorrect = BOLDGREEN "Passed!";
string BTerror = BOLDRED "Failed!";
string BTresult;

default_random_engine BTgenerator(random_device{}());
uniform_int_distribution<uint> BTdist(1, 999);

// STARTING TO DEFINE BINARYTREE TEST FUNCTIONS

//BinaryTree test 1:
// (lnk) Testing main functionalities and constructors, then mix them together
void BinaryTreeTest1(){

    BTresult = BTcorrect;

    try{

        uint isRoot = 9999;

        lasd::List<int> lst;

        for(uint i = 0; i < 50; i++){ lst.InsertAtBack(BTdist(BTgenerator)); }
        lst.InsertAtFront(isRoot);

        lasd::BinaryTreeLnk<int> btlnk(lst);
        lasd::BinaryTreeLnk<int> btcopy(btlnk);
        lasd::BinaryTreeLnk<int> btmove(std::move(btcopy));

        if(btlnk.Root().Element() != isRoot){ BTresult = BTerror; }
        if(btlnk.Size() != 51){BTresult = BTerror; }

        if(btcopy == btlnk){ BTresult = BTerror; }
        if(btcopy.Size() != 0){ BTresult = BTerror; }
        
        try{
            
            int check = btcopy.Root().Element();
            if(check == btlnk.Root().Element()){ BTresult = BTerror; }
            BTresult = BTerror;
        }
        catch(...){ }

        if(btmove != btlnk){ BTresult = BTerror; }
        if(btmove.Root().Element() != isRoot){ BTresult = BTerror; }
        if(btmove.Root().Element() != btlnk.Root().Element()){ BTresult = BTerror; }
        if(btmove.Size() != btlnk.Size()){ BTresult = BTerror; }
    }
    catch(...){ BTresult = BTerror; }

    cout << endl << "• Test 1: " << BTresult << RESET << endl;  
}


//BinaryTree test 2:
// (lnk)
void BinaryTreeTest2(){

    BTresult = BTcorrect;

    try{ }
    catch(...){ BTresult = BTerror; }

    cout << endl << "• Test 2: " << BTresult << RESET << endl;  
}