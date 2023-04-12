
typedef unsigned long ulong;

namespace lasd {

////////////////////////////////////////////////////////////////// Node structure

// Specific constructor #1: Given initial value
template <typename Data>
List<Data>::Node::Node(Data& value){

    /////////// TODO
}


// Copy constructor
template <typename Data>
List<Data>::Node::Node(const Node otherNode){

    ////////// TODO
}


// Move constructor
template <typename Date>
List<Data>::Node::Node(Node&& otherNote){

    ////////// TODO
}


// Destructor
template <typename Data>
List<Data>::Node::~Node(){

    ////////// TODO
}


// Operator ==
template <typename Data>
List<Data>::Node::operator == (const Node& otherNode) const noexcept{

    ////////// TODO
}


// Operator !=
template <typename Data>
List<Data>::Node::operator != (const Node& otherNode) const noexcept{

    ///////// TODO
}


////////////////////////////////////////////////////////////////// List

// Default constructor
// XXXXXXXXXXXXXXXXXXX

// Specific constructor #1: List obtained from a MappableContainer
template <typename Data>
List<Data>::List(const MappableContainer<Data>& container) noexcept{

    ///////// TODO
}


// Specific constructor #2: List obtained from a MutableMappableContainer
template <typename Data>
List<Data>::List(MutableMappableContainer<Data>&& container) noexcept{

    ///////// TODO
}


// Copy constructor
template <typename Data>
List<Data>::List(const List<Data>& otherList){

    //////// TODO
}


// Move constructor
template <typename Data>
List<Data>::List(List<Data>&& otherList) noexcept{

    //////// TODO
}
}
