
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
    bool check = false;

    try{

        // LIMIT CASE: Remove of 150
        lasd::BST<int> tree;
        tree.Insert(100);
        tree.Insert(99);
        tree.Insert(150);
        tree.Insert(160);
        tree.Insert(120);
        tree.Insert(125);
        tree.Insert(130);
        tree.Insert(127);
        
        tree.Remove(150);

        if(tree.Size() == 8){ BSTresult = BSTerror; }
        if(!validBST(tree.Root())){ BSTresult = BSTerror; }


        // Other tests:

        lasd::BST<int> oak;
        oak.Insert(100);
        oak.Insert(99);
        oak.Insert(150);
        oak.Insert(160);
        oak.Insert(120);
        oak.Insert(125);

        oak.Remove(125);
        if(oak.Size() == 6){ BSTresult = BSTerror; }
        if(!validBST(oak.Root())){ BSTresult = BSTerror; }

        lasd::BST<int> birch;
        birch.Insert(100);
        birch.Insert(99);
        birch.Insert(150);
        birch.Insert(160);
        birch.Insert(120);
        birch.Insert(125);
        birch.Insert(130);
        birch.Insert(127);

        birch.Remove(100);
        if(birch.Size() == 8){ BSTresult = BSTerror; }
        if(!validBST(birch.Root())){ BSTresult = BSTerror; }
    }
    catch(...){ BSTresult = BSTerror; }

    cout << endl << "• Test 4: " << BSTresult << RESET << endl;  
}


// AUXILIARY
bool validBST(lasd::BinaryTree<int>::Node const& node){

    if(node.HasRightChild() && !validBST(node.RightChild())){ return false; }
    if(node.HasLeftChild() && !validBST(node.LeftChild())){ return false; }
    if(node.HasRightChild() && node.RightChild().Element() < node.Element()){ return false; }
    if(node.HasLeftChild() && node.LeftChild().Element() > node.Element()){ return false; }

    return true;
};