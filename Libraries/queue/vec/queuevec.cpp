
namespace lasd {

/* ************************************************************************** */
// CIRCOLAR QUEUE >>> This is the implementation of a circular queue; the implementation of a linear queue is written below

// Default constructor
template <typename Data>
QueueVec<Data>::QueueVec() : Vector<Data>::Vector(4){}


// Specific constructor #1: Queuevec obtained from a MappableContainer
template <typename Data>
QueueVec<Data>::QueueVec(const MappableContainer<Data>& container) noexcept /*: Vector<Data>(container)*/{

    size = 4;
    head = 0;
    elements = new Data[size];

    container.Map(

        [this](const Data& e){ Enqueue(e); }
    );
}


// Specific constructor #2: QueueVec obtained from a MutableMappableContainer
template <typename Data>
QueueVec<Data>::QueueVec(MutableMappableContainer<Data>&& container) noexcept /*: Vector<Data>(std::move(container))*/{

    size = 4;
    head = 0;
    elements = new Data[size];

    container.Map(

        [this](Data& e){ Enqueue(std::move(e)); }
    );
}


// Copy constructor
template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& otherQueue) : Vector<Data>((Vector<Data>&)otherQueue){

    head = otherQueue.head;
    length = otherQueue.length;
}


// Move constructor
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& otherQueue) noexcept : Vector<Data>(std::move(otherQueue)){

    std::swap(head, otherQueue.head);
    std::swap(length, otherQueue.length);
}


// Destructor
template <typename Data>
QueueVec<Data>::~QueueVec(){}   // ~QueueVec() = default;


// Copy assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator = (const QueueVec<Data>& otherQueue) noexcept{

    Vector<Data>::operator = (otherQueue);
    head = otherQueue.head;
    length = otherQueue.length;

    return *this;
}


// Move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator = (QueueVec<Data>&& otherQueue) noexcept{

    Vector<Data>::operator = (std::move(otherQueue));
    std::swap(head, otherQueue.head);
    std::swap(length, otherQueue.length);

    return *this;
} 


// Operator ==
template <typename Data>
bool QueueVec<Data>::operator == (const QueueVec<Data>& otherQueue) const noexcept{

    if(this->length == otherQueue.length){

        ulong tempHead = head;
        ulong otherHead = otherQueue.head;

        for(ulong i = 0; i < length; i++){

            if(elements[tempHead] != otherQueue.elements[otherHead]){ return false; }

            tempHead = (tempHead + 1) % size;
            otherHead = (otherHead + 2) % otherQueue.size;
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

    if(this->Empty()){ throw std::length_error("Error: the structure is empty"); }

    else{ return elements[head]; }
}


// Override function Head (Mutable)
template <typename Data>
Data& QueueVec<Data>::Head(){

    if(this->Empty()){ throw std::length_error("Error: the structure is empty"); }
    
    else{ return elements[head]; }
}


// Override function Dequeue
template <typename Data>
void QueueVec<Data>::Dequeue(){

    if(this->Empty()){ throw std::length_error("Error: the structure is empty"); }

    else{
        
        head = (head + 1) % size;
        length = length - 1;

        if(length <= (size / 4)){ Reduce(); }
    }
}


// Override function HeadNDequeue
template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){

    if(this->Empty()){ throw std::length_error("Error: the structure is empty"); }

    Data value = Head();
    Dequeue();

    return value;
}


// Override function Enqueue (Copy)
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& e) noexcept{

    if(length == size - 1){ Expand(); }

    ulong rear = NextRear();

    if(Empty()){

        elements[0] = e;
        length = length + 1;
    }

    else{

        elements[rear] = e;
        length = length + 1;
    }
}


// Override function Enqueue (Move)
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& e) noexcept{

    if(length == size - 1){ Expand(); }

    ulong rear = NextRear();

    if(Empty()){

        elements[0] = std::move(e);
        length = length + 1;
    }

    else{

        elements[rear] = std::move(e);
        length = length + 1;
    }
}


// Override function Empty
template <typename Data>
bool QueueVec<Data>::Empty() const noexcept{

    return(length == 0);
}


// Defining function Full
template <typename Data>
bool QueueVec<Data>::Full() const noexcept{

    if(this->NextRear() == head){ return true; }

    return false;
}


// Defining function NextRear
template <typename Data>
ulong QueueVec<Data>::NextRear() const{

    return (head + length) % size;
}


// Defining my extra function AllocatedSize
template <typename Data>
ulong QueueVec<Data>::AllocatedSize() const noexcept{

    return this->size;
}


// Override function Size
template <typename Data>
ulong QueueVec<Data>::Size() const noexcept{

    return this->length;
}


// Override function Clear
template <typename Data>
void QueueVec<Data>::Clear() noexcept{

    delete[] elements;
    elements = nullptr;

    size = 2;
    length = 0;
    head = 0;
}


// Defining function SwapVectors
template <typename Data>
void QueueVec<Data>::SwapVectors(const ulong newSize){

    size = newSize;

    Data* temp = new Data[newSize];

    ulong tempIndex = head;

    for(ulong i = 0; i < length; i++){

        temp[i] = elements[tempIndex];

        tempIndex = (tempIndex + 1) % size;
    }

    //size = newSize;
    head = 0;

    std::swap(elements, temp);
    delete[] temp;
}


// Defining function Expand (double the vector)
template <typename Data>
void QueueVec<Data>::Expand(){

    SwapVectors(size*2);
}


// Defining function Reduce (half the vector)
template <typename Data>
void QueueVec<Data>::Reduce(){

    SwapVectors(size/2);
}


/* ************************************************************************** */
// LINEAR QUEUE >>>>>>>>>> This is the implementation of a linear queue; this queue passes every test just like the circular one.

/*
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
// not used for a linear container


*/  // < De-comment here to use the linear queue

/* ************************************************************************** */

}
