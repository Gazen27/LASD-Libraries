
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../container/linear.hpp"
#include "../container/dictionary.hpp"

#include "../vector/vector.hpp"
#include "../list/list.hpp"

/* ************************************************************************** */

void callMenu();

void mytest();

/* ************************************************************************** */

// Vector 
void VectorTest1();
void VectorTest2();
void VectorTest3();
void VectorTest4();

// List
void ListTest1();
void ListTest2();
void ListTest3();
void ListTest4();

// Stack
void StackTest1();
void StackTest2();
void StackTest3();
void StackTest4();

// Queue
void QueueTest1();
void QueueTest2();
void QueueTest3();
void QueueTest4();

/* ************************************************************************** */

// Auxiliary functions

template <typename Data>
void DoubleOnList(Data&);

template <typename Data>
void IncrementOnList(Data&);

void printlist(lasd::List<int>);

template <typename Data>
void FoldSum(Data&, void*);

#endif
