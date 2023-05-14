
#include <iostream>
#include <stdlib.h>
#include <random>

#include "../test.hpp"
#include "../../bst/bst.hpp"

#define RESET   "\033[0m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"

using namespace std;

typedef unsigned int uint;
typedef unsigned long ulong;

string BSTcorrect = BOLDGREEN "Passed!";
string BSTerror = BOLDRED "Failed!";
string BSTresult;

default_random_engine BSTgenerator(random_device{}());
uniform_int_distribution<uint> BSTdist(1, 999);
uint over = 9999;

// STARTING TO DEFINE BINARYSEARCHTREE TEST FUNCTIONS

//BinarySearchTree test 1:
// Testing a lot of main functionalities combined by each other
void BinarySearchTreeTest1(){

    BSTresult = BSTcorrect;

    try{

        lasd::BST<int> tree1;
        for(uint i = 0; i < 100; i++){ tree1.Insert(BSTdist(BSTgenerator)); }
        for(uint i = 0; i < 100; i++){ tree1.Insert(BSTdist(BSTgenerator)); }
        tree1.Insert(over);
        
        if(!tree1.Exists(9999)){ BSTresult = BSTerror; }

        uint oldSize = tree1.Size();
        tree1.Remove(over);
        uint newSize = tree1.Size();
        if(oldSize != newSize + 1){ BSTresult = BSTerror; }

        tree1.Remove(275);
        if(tree1.Exists(275)){ BSTresult = BSTerror; }
    }
    catch(...){ BSTresult = BSTerror; }

    cout << endl << "• Test 1: " << BSTresult << RESET << endl;  
}


//BinarySearchTree test 2:
// Testing Min and Max with other functionalities
void BinarySearchTreeTest2(){

    BSTresult = BSTcorrect;

    try{
        lasd::BST<int> tree;
        tree.Insert(0);
        for(uint i = 0; i < 100; i++){ tree.Insert(BSTdist(BSTgenerator)); }
        tree.Insert(over);

        int oldSize = tree.Size();

        int minimum = tree.MinNRemove();

        if(tree.Exists(minimum)){ BSTresult = BSTerror; }
        if(tree.Size() != oldSize - 1){ BSTresult = BSTerror; }
        if(minimum != 0){ BSTresult = BSTerror; }
    }
    catch(...){ BSTresult = BSTerror; }

    cout << endl << "• Test 2: " << BSTresult << RESET << endl;  
}


//BinarySearchTree test 3:
// Testing some constructors mixed with some functionalities
void BinarySearchTreeTest3(){

    BSTresult = BSTcorrect;

    try{
        lasd::BST<int> tree;
        for(uint i = 0; i < 100; i++){ tree.Insert(BSTdist(BSTgenerator)); }
        tree.Insert(over);

        lasd::BST<int> coptree(tree);
        lasd::BST<int> movtree(std::move(tree));

        movtree.Remove(9999);
        if(tree.Size() != 0){ BSTresult = BSTerror; }
        if(movtree.Size() != coptree.Size() - 1){ BSTresult = BSTerror; }

        if(!coptree.Exists(9999) || movtree.Exists(9999)){ BSTresult = BSTerror; }
    }
    catch(...){ BSTresult = BSTerror; }

    cout << endl << "• Test 3: " << BSTresult << RESET << endl;  
}


//BinarySearchTree test 4:
// Testing the tree in a limit case of remove
void BinarySearchTreeTest4(){

    BSTresult = BSTcorrect;

    try{

        lasd::BST<int> tree;
        tree.Insert(100);
        tree.Insert(99);
        tree.Insert(150);
        tree.Insert(160);
        tree.Insert(120);
        tree.Insert(125);
        tree.Insert(130);
        tree.Insert(127);


        lasd::BTPreOrderIterator<int> it1(tree);
        cout << *it1 << endl;
        ++it1;
        cout << *it1 << endl;
        ++it1;
        cout << *it1 << endl;
        ++it1;
        cout << *it1 << endl;
        ++it1;
        cout << *it1 << endl;
        ++it1;
        cout << *it1 << endl;
        ++it1;
        cout << *it1 << endl;
        ++it1;
        cout << *it1 << endl;
        
        tree.Remove(150);

        lasd::BTPreOrderIterator<int> it2(tree);
        cout << *it2 << endl;
        ++it2;
        cout << *it2 << endl;
        ++it2;
        cout << *it2 << endl;
        ++it2;
        cout << *it2 << endl;
        ++it2;
        cout << *it2 << endl;
        ++it2;
        cout << *it2 << endl;
        ++it2;
        cout << *it2 << endl;
        ++it2;
        cout << *it2 << endl;

    }
    catch(...){ BSTresult = BSTerror; }

    cout << endl << "• Test 4: " << BSTresult << RESET << endl;  
}