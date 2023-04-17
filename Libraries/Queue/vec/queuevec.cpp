
namespace lasd {

/* ************************************************************************** */

// Default constructor
// XXXXXXXXXXXXXXXXX


// Specific constructor #1: QueueVec obtained from a MappableContainer
template <typename Data>
QueueVec<Data>::QueueVec(const MappableContainer<Data>& container) noexcept{

    size = container.size;
    elements = new Data[size];
    last = 0;

    container.Map(

        [this](const Data& e){ this->Enqueue(e); }
    );
}


// // Specific constructor #2: QueueVec obtained from a MutableMappableContainer
template <typename Data>
QueueVec<Data>::QueueVec(MutableMappableContainer<Data>&& container) noexcept{

    size = container.size;
    elements = new Data[size];
    last = 0;

    container.Map(

        [this](const Data& e){ this->Enqueue(std::move(e)); }
    );
}


// Copy constructor
template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& otherQueue){

    size = otherQueue.size;
    elements = new Data[size];
    last = 0;

    for(ulong i = 0; i < otherQueue.last; i++){
        
        this->Enqueue(otherQueue.elements[i]);
    }
}


// Move constructor
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& otherQueue) noexcept{

    size = otherQueue.size;
    elements = new Data[size];
    last = 0;

    for(ulong i = 0; i < otherQueue.last; i++){
        
        this->Enqueue(std::move(otherQueue.HeadNDequeue()));
    }
}


// Destructor
template <typename Data>
QueueVec<Data>::~QueueVec(){

    ///////// TODO
}


// Copy assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator = (const QueueVec<Data>& otherQueue) noexcept{

    Clear();
    size = otherQueue.size;
    last = 0;

    for(ulong i = 0; i < otherQueue.last; i++){

        this->Enqueue(otherQueue.elements[i]);
    }
}


// Move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator = (QueueVec<Data>&& otherQueue) noexcept{

    Clear();
    size = otherQueue.size;
    last = 0;

    for(ulong i = 0; i < otherQueue.level; i++){

        this->Push(std::move(otherQueue.HeadNDequeue()));
    }
} 


// Operator ==
template <typename Data>
bool QueueVec<Data>::operator == (const QueueVec<Data>& otherQueue) const noexcept{

    if(size == otherQueue.size && last = otherQueue.last){

        for(ulong i = 0; i < last; i++){

            if(this->elements[i] != otherQueue.elements[i]){ return false; }
        }

        return true;
    }

    else{ return false; }
}


// Operator != 
template <typename Data>
bool QueueVec<Data>::operator != (const QueueVec<Data>& otherQueue) const noexcept{

    return !((*this) == otherQueue);
}


// Override function Head (Non-Mutable)
template <typename Data>
const Data& QueueVec<Data>::Head() const{

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
