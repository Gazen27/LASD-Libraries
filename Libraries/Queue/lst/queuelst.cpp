
namespace lasd {

/* ************************************************************************** */

// Default constructor
// XXXXXXXXXXXXXXXXXX

// Specific constructor #1: QueueLst obtained from a MappableContainer
template <typename Data>
QueueLst<Data>::QueueLst(const MappableContainer<Data>& container) noexcept{

    ////////// TODO
}

// Specific constructor #2: QueueLst obtained from a MutableMappableContainer
template <typename Data>
QueueLst<Data>::QueueLst(MutableMappableContainer<Data>&& container) noexcept{

    ////////// TODO
}


// Copy constructor
template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst<Data>& otherQueue){

    ///////// TODO
}


// Move constructor
template <typename Data>
QueueLst<Data>::QueueLst(QueueLst<Data>&& otherQueue) noexcept{

    ///////// TODO
}


// Destructor
template <typename Data>
QueueLst<Data>::~QueueLst(){

    ///////// TODO
}


// Copy assignment
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator = (const QueueLst<Data>& otherQueue) noexcept{

    ///////// TODO
}


// Move assignment
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator = (QueueLst<Data>&& otherQueue) noexcept{

    //////// TODO
}


// Operator ==
template <typename Data>
bool QueueLst<Data>::operator == (const QueueLst<Data>& otherQueue) const noexcept{

    //////// TODO
}


// Operator !=
template <typename Data>
bool QueueLst<Data>::operator != (const QueueLst<Data>& otherQueue) const noexcept{

    //////// TODO
}


// Override function Head (Non-Mutable)
template <typename Data>
const Data& QueueLst<Data>::Head() const{

    //////// TODO
}


// Override function Head (Mutable)
template <typename Data>
Data& QueueLst<Data>::Head(){

    ///////// TODO
}


// Override function Dequeue
template <typename Data>
void QueueLst<Data>::Dequeue(){

    ///////// TODO
}


// Override function HeadNDequeue
template <typename Data>
Data& QueueLst<Data>::HeadNDequeue(){

    ////////// TODO
}


// Override function Enqueue (Copy)
template <typename Data>
void QueueLst<Data>::Enqueue(const Data& element) noexcept{

    ////////// TODO
}


// Override function Enqueue (Move)
template <typename Data>
void QueueLst<Data>::Enqueue(Data&& element) noexcept{

    ////////// TODO
}


/* ************************************************************************** */

}
