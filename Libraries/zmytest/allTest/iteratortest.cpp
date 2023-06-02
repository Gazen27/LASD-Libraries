
#include <iostream>
#include <stdlib.h>
#include <random>

#include "../test.hpp"
#include "../../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"
#include "../../iterator/iterator.hpp"
#include "../../bst/bst.hpp"


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
uint isRoot = 9999;

// STARTING TO DEFINE BINARYTREE TEST FUNCTIONS

//Iterator test 1:
// Testing PreOrder Iterator
void IteratorTest1(){

    ITresult = ITcorrect;

    try{

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

        lasd::BTPreOrderIterator<int> it4(bt);
        if(*it4 != isRoot){ ITresult = ITerror; }
        
        lasd::BST<int> abr;
        try{
            lasd::BTPreOrderIterator<int> itbst(abr);
            if(!itbst.Terminated()){ ITresult = ITerror; }
        }
        catch(...){ ITresult = ITerror;}
    }
    catch(...){ ITresult = ITerror; }
    cout << endl << "• Test 1: " << ITresult << RESET << endl;
}


// Iterator test 2:
// Testing PostOrderIterator
void IteratorTest2(){

    ITresult = ITcorrect;

    try{
        
        lasd::List<int> lst;
        for(uint i = 0; i < 63; i++){ lst.InsertAtBack(i); }
        lasd::BinaryTreeLnk<int> bt(lst);
        
        lasd::BTPostOrderIterator<int> it1(bt);
        if(*it1 != 31){ ITresult = ITerror; }

        lasd::List<int> lst2;
        for(uint i = 0; i < 99; i++){ lst2.InsertAtBack(ITdist(ITgenerator)); }
        lst2.InsertAtFront(isRoot);
        lasd::BinaryTreeLnk<int> bt2(lst2);
        lasd::BTPostOrderMutableIterator<int> mit(bt2);

        try{ for(uint i = 0; i < 99; i++){++mit;} }
        catch(...){ ITresult = ITerror; }

        if(*mit != isRoot){ ITresult = ITerror; }

        lasd::List<int> elst;
        for(uint i = 0; i < 50; i++){ elst.InsertAtBack(ITdist(ITgenerator)); }
        lasd::BinaryTreeVec<int> emptytree(elst);

        emptytree.Clear();
        try{
            lasd::BTPostOrderIterator<int> it3(emptytree);
            if(!it3.Terminated()){ ITresult = ITerror; }
        }
        catch(...){ ITresult = ITerror; }

        lasd::BST<int> abr;
        try{
            lasd::BTPostOrderMutableIterator<int> itbst(abr);
            if(!itbst.Terminated()){ ITresult = ITerror; }
        }
        catch(...){ ITresult = ITerror;}
    }
    catch(...){ ITresult = ITerror; }
    cout << endl << "• Test 2: " << ITresult << RESET << endl;
}


// Iterator test 3:
// Testing InOrderIterator
void IteratorTest3(){

    ITresult = ITcorrect;

    try{
        lasd::List<int> lst;
        for(uint i = 0; i < 63; i++){ lst.InsertAtBack(i); }
        lasd::BinaryTreeLnk<int> bt(lst);
        
        lasd::BTInOrderIterator<int> it1(bt);
        if(*it1 != 31){ ITresult = ITerror; }

        lasd::List<int> elst;
        for(uint i = 0; i < 50; i++){ elst.InsertAtBack(ITdist(ITgenerator)); }
        lasd::BinaryTreeVec<int> emptytree(elst);

        emptytree.Clear();
        try{
            lasd::BTInOrderIterator<int> it3(emptytree);
            if(!it3.Terminated()){ ITresult = ITerror; }
        }
        catch(...){ ITresult = ITerror; }

        lasd::BST<int> abr;
        try{
            lasd::BTInOrderMutableIterator<int> itbst(abr);
            if(!itbst.Terminated()){ ITresult = ITerror; }
        }
        catch(...){ ITresult = ITerror;}

        lasd::List<int> tlst;
        for(uint i = 0; i < 100; i++){ tlst.InsertAtBack(i); }
        lasd::BST<int> tree(tlst);
        lasd::BTInOrderIterator<int> cursor(tree);

        if(*cursor != 0){ ITresult = ITerror; }
        for(uint i = 0; i < tree.Size()-1; i++){++cursor;}
        if(*cursor != 99){ ITresult = ITerror; }
    }
    catch(...){ ITresult = ITerror; }
    cout << endl << "• Test 3: " << ITresult << RESET << endl;
}


// Iterator test 4:
// Testing BreadthIterator
void IteratorTest4(){

    ITresult = ITcorrect;

    try{
        
        lasd::List<int> lst1;
        for(uint i = 0; i < 99; i++){ lst1.InsertAtFront(ITdist(ITgenerator)); }
        lst1.InsertAtFront(isRoot);
        lasd::BinaryTreeLnk<int> tree1(lst1);
        lasd::BTBreadthMutableIterator<int> it1(tree1);
        if(*it1 != isRoot){ ITresult = ITerror; }

        lasd::BinaryTreeVec<int> tree2(lst1);
        tree2.Clear();
        try{
            lasd::BTBreadthIterator<int> it2(tree2);
            if(!it2.Terminated()){ITresult = ITerror; }
        }
        catch(...){ ITresult = ITerror; }

        lasd::List<int> last;
        for(uint i = 0; i < 100; i++){ last.InsertAtBack(i);}
        lasd::BST<int> tree(last);
        lasd::BTBreadthIterator<int> cursor(tree);
        for(uint i = 0; i < tree.Size() - 1; i++){ ++cursor; }
        if(*cursor != 99){ ITresult = ITerror; }
    }
    catch(...){ ITresult = ITerror; }
    cout << endl << "• Test 4: " << ITresult << RESET << endl;
}