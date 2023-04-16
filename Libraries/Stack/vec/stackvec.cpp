
namespace lasd {

/* ************************************************************************** */

// Default constructor
// XXXXXXXXXXXXXXXXXX

// Specific constructor #1: StackVec obtained from a MappableContainer
template <typename Data>
StackVec<Data>::StackVec(const MappableContainer<Data>&) noexcept{

    ///////// TODO
}


// Specific constructor #2: StackVec obtained from a MutableMappableContainer
template <typename Data>
StackVec<Data>::StackVec(MutableMappableContainer<Data>&&) noexcept{

    ///////// TODO
}


// Copy constructor
template <typename Data>
StackVec<Data>::StackVec(const StackVec<Data>&){

    //////// TODO
}


// Move constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec<Data>&&) noexcept{

    //////// TODO
}


// Destructor
template <typename Data>
StackVec<Data>::~StackVec(){

    //////// TODO
}


// Copy assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator = (const StackVec<Data>&) noexcept{

    ///////// TODO
}


// Move assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator = (StackVec<Data>&&) noexcept{

    ///////// TODO
}


// Operator ==
template <typename Data>
bool StackVec<Data>::operator == (const StackVec<Data>&) const noexcept{

    ///////// TODO
}


// Operator !=
template <typename Data>
bool StackVec<Data>::operator != (const StackVec<Data>&) const noexcept{

    ///////// TODO
}


// Override function Top (Non-Mutable)
template <typename Data>
const Data& StackLst<Data>::Top(){

    ///////// TODO
} 


// Override function Top (Mutable)
template <typename Data>
Data& StackVec<Data>::Top(){

    ///////// TODO
}

// Override function Pop
template <typename Data>
void StackVec<Data>::Pop(){

    ///////// TODO
}


// Override function TopNPop
template <typename Data>
Data& StackVec<Data>::TopNPop(){

    ///////// TODO
}


// Override function Push (Copy)
template <typename Data>
void StackVec<Data>::Push(const Data& element) noexcept{

    ///////// TODO
}


// Override function Push (Move)
template <typename Data>
void StackVec<Data>::Push(Data&& element) noexcept{

    ///////// TODO
}


// Override function Empty
template <typename Data>
bool StackVec<Data>::Empty() const noexcept{

    ///////// TODO
}


// Override function Size
template <typename Data>
ulong StackVec<Data>::Size() const noexcept{

    ///////// TODO
}


// Override function Clear
template <typename Data>
void StackVec<Data>::Clear() noexcept{

    ///////// TODO
}


// Defining function Expand
template <typename Data>
void StackVec<Data>::Expand(){

    ///////// TODO
}


// Defining function Reduce
template <typename Data>
void StackVec<Data>::Reduce(){

    ///////// TODO
}

/* ************************************************************************** */

}
