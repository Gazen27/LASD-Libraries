
namespace lasd {

/* ************************************************************************** */

// Default constructor
// XXXXXXXXXXXXXXXXXX

// Specific constructor #1: QueueLst obtained from a MappableContainer
template <typename Data>
QueueLst<Data>::QueueLst(const MappableContainer<Data>& container) noexcept{

    container.Map(

        [this](const Data& element){ this->Enqueue(element); }
    );
}

// Specific constructor #2: QueueLst obtained from a MutableMappableContainer
template <typename Data>
QueueLst<Data>::QueueLst(MutableMappableContainer<Data>&& container) noexcept{

    container.Map(

        [this](const Data& element){ this->Enqueue(std::move(element)); }
    );
}


// Copy constructor
template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst<Data>& otherQueue) : List<Data>(otherQueue){}


// Move constructor
template <typename Data>
QueueLst<Data>::QueueLst(QueueLst<Data>&& otherQueue) noexcept : List<Data>(std::move(otherQueue)){}


// Destructor
template <typename Data>
QueueLst<Data>::~QueueLst(){

    while(this->size != 0){ this->Dequeue(); }
}


// Copy assignment
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator = (const QueueLst<Data>& otherQueue) noexcept{

    return List<Data>::operator = (otherQueue);
}


// Move assignment
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator = (QueueLst<Data>&& otherQueue) noexcept{

    return List<Data>::operator = (std::move(otherQueue));
}


// Operator ==
template <typename Data>
bool QueueLst<Data>::operator == (const QueueLst<Data>& otherQueue) const noexcept{

    return List<Data>::operator == (otherQueue);
}


// Operator !=
template <typename Data>
bool QueueLst<Data>::operator != (const QueueLst<Data>& otherQueue) const noexcept{

    return List<Data>::operator != (otherQueue);
}


// Override function Head (Non-Mutable)
template <typename Data>
const Data& QueueLst<Data>::Head() const{

    if(this->size == 0){ throw std::length_error("Error: the structure is empty"); }

    else{

        return List<Data>::Front();
    }
}


// Override function Head (Mutable)
template <typename Data>
Data& QueueLst<Data>::Head(){

    if(this->size == 0){ throw std::length_error("Error: the structure is empty"); }

    else{

        Data& element = std::move(List<Data>::Front());
        return element;
    }
}


// Override function Dequeue
template <typename Data>
void QueueLst<Data>::Dequeue(){

    if(this->size == 0){ throw std::length_error("Error: the structure is empty"); }

    else{

        List<Data>::RemoveFromFront();
    }
}


// Override function HeadNDequeue
template <typename Data>
Data QueueLst<Data>::HeadNDequeue(){

    Data element;

    if(this->size == 0){ throw std::length_error("Error: the structure is empty"); }

    else{

        element = List<Data>::FrontNRemove();
        return element;
    }
}


// Override function Enqueue (Copy)
template <typename Data>
void QueueLst<Data>::Enqueue(const Data& element) noexcept{

    List<Data>::InsertAtBack(element);
}


// Override function Enqueue (Move)
template <typename Data>
void QueueLst<Data>::Enqueue(Data&& element) noexcept{

    List<Data>::InsertAtBack(std::move(element));
}


/* ************************************************************************** */

}
