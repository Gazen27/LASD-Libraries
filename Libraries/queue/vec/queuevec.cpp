
namespace lasd {

/* ************************************************************************** */

// Default constructor
template <typename Data>
QueueVec<Data>::QueueVec() : Vector<Data>::Vector(8){}


// Specific constructor #1: QueueVec obtained from a MappableContainer
template <typename Data>
QueueVec<Data>::QueueVec(const MappableContainer<Data>& container) noexcept{

    size = container.Size();
    elements = new Data[size];
    last = 0;

    container.Map(

        [this](const Data& e){ this->Enqueue(e); }
    );
}


// Specific constructor #2: QueueVec obtained from a MutableMappableContainer
template <typename Data>
QueueVec<Data>::QueueVec(MutableMappableContainer<Data>&& container) noexcept{

    size = container.Size();
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
        
        this->Enqueue(std::move(otherQueue.elements[i]));
    }
}


// Destructor
template <typename Data>
QueueVec<Data>::~QueueVec(){

    Clear();
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

    return *this;
}


// Move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator = (QueueVec<Data>&& otherQueue) noexcept{

    Clear();
    size = otherQueue.size;
    last = 0;

    for(ulong i = 0; i < otherQueue.last; i++){

        this->Enqueue(std::move(otherQueue.HeadNDequeue()));
    }

    return *this;
} 


// Operator ==
template <typename Data>
bool QueueVec<Data>::operator == (const QueueVec<Data>& otherQueue) const noexcept{

    if(size == otherQueue.size && last == otherQueue.last){

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

    if(this->size == 0 || this->last == 0){ throw std::length_error("Error: the structure is empty!"); }

    return this->elements[0];
}


// Override function Head (Mutable)
template <typename Data>
Data& QueueVec<Data>::Head(){

    if(this->size == 0 || this->last == 0){ throw std::length_error("Error: the structure is empty!"); }

    return this->elements[0];
}


// Override function Dequeue
template <typename Data>
void QueueVec<Data>::Dequeue(){

    if(this->size == 0 || this->last == 0){ throw std::length_error("Error: the structure is empty!"); }

    for(ulong i = 1; i < last; i ++){

        elements[i - 1] = elements[i];
    }

    last = last - 1;

    if(last < size/2){ Reduce(); }
}


// Override function HeadNDequeue
template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){

    if(this->size == 0 || this->last == 0){ throw std::length_error("Error: the structure is empty!"); }

    Data e = this->Head();
    this->Dequeue();

    return e;
}


// Override function Enqueue (Copy)
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& e) noexcept{

    if(last == size){this->Expand(); }

    this->elements[last] = e;
    last = last + 1; 
}


// Override function Enqueue (Move)
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& e) noexcept{

    if(last == size){this->Expand(); }
    
    this->elements[last] = std::move(e);
    last = last + 1;
}


// Override function Empty
template <typename Data>
bool QueueVec<Data>::Empty() const noexcept{

    if(this->size == 0 || this->last == 0){ return true; }
    return false;
}


// Override function Size
template <typename Data>
ulong QueueVec<Data>::Size() const noexcept{

    return this->last;
}


// Override function Clear
template <typename Data>
void QueueVec<Data>::Clear() noexcept{

    size = 1;
    last = 0;
    delete[] elements;

    elements = new Data[size];
}


// Defining function Expand (double the vector)
template <typename Data>
void QueueVec<Data>::Expand(){

    Vector<Data>::Resize(size*2);
}


// Defining function Reduce (half the vector)
template <typename Data>
void QueueVec<Data>::Reduce(){

    Vector<Data>::Resize(size/2);
}


// Defining function SwapVectors
template <typename Data>
void QueueVec<Data>::SwapVectors(QueueVec<Data>&& otherQueue) noexcept{

    ///////// TODO
}

/* ************************************************************************** */

}
