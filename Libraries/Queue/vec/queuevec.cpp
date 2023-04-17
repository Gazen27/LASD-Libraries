
namespace lasd {

/* ************************************************************************** */

// Default constructor
// XXXXXXXXXXXXXXXXX


// Specific constructor #1: QueueVec obtained from a MappableContainer
template <typename Data>
QueueVec<Data>::QueueVec(const MappableContainer<Data>& container) noexcept{

    ////////// TODO
}


// // Specific constructor #2: QueueVec obtained from a MutableMappableContainer
template <typename Data>
QueueVec<Data>::QueueVec(MutableMappableContainer<Data>&& container) noexcept{

    ///////// TODO
}


// Copy constructor
template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& otherQueue){

    ///////// TODO
}


// Move constructor
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& otherQueue) noexcept{

    ///////// TODO
}


// Destructor
template <typename Data>
QueueVec<Data>::~QueueVec(){

    ///////// TODO
}


// Copy assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator = (const QueueVec<Data>& otherQueue) noexcept{

    ///////// TODO
}


// Move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator = (QueueVec<Data>&& otherQueue) noexcept{

    ///////// TODO
} 


// Operator ==
template <typename Data>
bool QueueVec<Data>::operator == (const QueueVec<Data>& otherQueue) const noexcept{

    ///////// TODO
}


// Operator != 
template <typename Data>
bool QueueVec<Data>::operator != (const QueueVec<Data>& otherQueue) const noexcept{

    ///////// TODO
}


// Override function Head (Non-Mutable)
template <typename Data>
const Data& QueueVec<Dat>::Head() const{

    ///////// TODO
}


// Override function Head (Mutable)
template <typename Data>
Data& QueueVec<Data>::Head(){

    ///////// TODO
}


// Override function Dequeue
template <typename Data>
void QueueVec<Data>::Dequeue(){

    ///////// TODO
}


// Override function HeadNDequeue
template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){

    ///////// TODO
}


// Override function Enqueue (Copy)
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& e) noexcept{

    ///////// TODO
}


// Override function Enqueue (Move)
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& e) noexcept{

    ///////// TODO
}


// Override function Empty
template <typename Data>
bool QueueVec<Data>::Empty() const noexcept{

    ///////// TODO
}


// Override function Size
template <typename Data>
ulong QueueVec<Data>::Size() const noexcept{

    ///////// TODO
}


// Override function Clear
template <typename Data>
void QueueVec<Data>::Clear() noexcept{

    ///////// TODO
}


// Defining function Expand
template <typename Data>
void QueueVec<Data>::Expand(){

    ///////// TODO
}


// Defining function Reduce
template <typename Data>
void QueueVec<Data>::Reduce(){

    ///////// TODO
}


// Defining function SwapVectors
template <typename Data>
void QueueVec<Data>::SwapVectors(QueueVec<Data>&& otherQueue) noexcept{

    ///////// TODO
}

/* ************************************************************************** */

}
