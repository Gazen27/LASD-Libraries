
namespace lasd {

/* ************************************************************************** */

// Default constructor
template <typename Data>
QueueVec<Data>::QueueVec() : Vector<Data>::Vector(4){}


// Specific constructor #1: Queuevec obtained from a MappableContainer
template <typename Data>
QueueVec<Data>::QueueVec(const MappableContainer<Data>& container) noexcept{

    size = 4;
    elements = new Data[size];

    container.Map(

        [this](const Data& e){ Enqueue(e); }
    );
}


// Specific constructor #2: QueueVec obtained from a MutableMappableContainer
template <typename Data>
QueueVec<Data>::QueueVec(MutableMappableContainer<Data>&& container) noexcept{

    size = 4;
    elements = new Data[size];

    container.Map(

        [this](Data& e){ Enqueue(std::move(e)); }
    );
}


// Copy constructor
template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& otherQueue) : Vector<Data>(otherQueue){

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
            otherHead = (otherHead + 1) % size;
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

    // CONDIZIONE EMPTY? (elements[0] = e; length++; )

    elements[rear] = e;
    length = length + 1;
}


// Override function Enqueue (Move)
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& e) noexcept{

    if(length == size - 1){ Expand(); }

    ulong rear = NextRear();

    // CONDIZIONE EMPTY? (elements[0] = e; length++; )

    elements[rear] = std::move(e);
    length = length + 1;
}


// Override function Empty
template <typename Data>
bool QueueVec<Data>::Empty() const noexcept{

    return(length == 0);
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

    size = 4;
    length = 0;
    head = 0;
    elements = new Data[size];

}


// Defining function SwapVectors
template <typename Data>
void QueueVec<Data>::SwapVectors(const ulong newSize){

    size = newSize;

    Data* temp = new Data[newSize];

    ulong thisHead = head;

    for(ulong i = 0; i < length; i++){

        temp[i] = elements[thisHead];

        thisHead = (thisHead + 1) % size;
    }

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

}
