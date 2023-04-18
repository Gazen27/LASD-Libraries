
#ifndef MYTEST_HPP
#define MYTEST_HPP


#include "../container/linear.hpp"
#include "../container/dictionary.hpp"

#include "../vector/vector.hpp"
#include "../list/list.hpp"

/* ************************************************************************** */

// Start the full Vector test
void VectorTestStart();

// Start the full List test
void ListTestStart();

// Start the full Stack test
void StackTestStart();

// Start the full Queue test
void QueueTestStart();

/* ************************************************************************** */

// Vector #1: Creation and usage of a Vector<int>
void VectorInt();

// Vector #2: Creation and usage of a Vector<double>
void VectorDouble();

// Vector #3: Creation and usage of a Vector<string>
void VectorString();

/* ************************************************************************** */

// List #1: Creation and usage of a List<int>
void ListInt();

// List #2: Creation and usage of a List<double>
void ListDouble();

// List #3: Creation and usage of a List<string>
void ListString();

/* ************************************************************************** */

// Stack #1: Creation and usage of a StackLst<int> and StackVec<int>
void StackLstInt();
void StackVecInt();

// Stack #2: Creation and usage of a StackLst<double> and StackVec<double>
void StackLstDouble();
void StackVecDouble();

// Stack #3: Creation and usage of a StackLst<string> and StackVec<string>
void StackLstString();
void StackVecString();

/* ************************************************************************** */


#endif
