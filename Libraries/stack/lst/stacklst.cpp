
namespace lasd {

/* ************************************************************************** */

// Specific constructor #1: StackLst obtained from a MappableContainer
template <typename Data>
StackLst<Data>::StackLst(const MappableContainer<Data>& container) noexcept{

    container.Map(

        [this](const Data& element){ this->Push(element); }
    );
}


// Specific constructor #2: StackLst obtained from a MutableMappableContainer
template <typename Data>
StackLst<Data>::StackLst(MutableMappableContainer<Data>&& container) noexcept{

    container.Map(

        [this](const Data& element){ this->Push(std::move(element));}
    );
}


// Copy constructor
template <typename Data>
StackLst<Data>::StackLst(const StackLst& otherStack) : List<Data>(otherStack){}


// Move constructor
template <typename Data>
StackLst<Data>::StackLst(StackLst&& otherStack) noexcept : List<Data>(std::move(otherStack)){}


// Destructor
template <typename Data>
StackLst<Data>::~StackLst(){

    while(this->size != 0){ this->Pop(); }
}


// Copy assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator = (const StackLst<Data>& otherStack) noexcept{
    
    List<Data>::operator = (otherStack);
    return *this;
}


// Move assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator = (StackLst<Data>&& otherStack) noexcept{

    List<Data>::operator = (std::move(otherStack));
    return *this;
}


// Operator ==
template <typename Data>
bool StackLst<Data>::operator == (const StackLst<Data>& otherStack) const noexcept{

    return List<Data>::operator == (otherStack);
}


// Operator !=
template <typename Data>
bool StackLst<Data>::operator != (const StackLst<Data>& otherStack) const noexcept{

    return List<Data>::operator != (otherStack);
}


// Override function Top (Non-Mutable)
template <typename Data>
const Data& StackLst<Data>::Top() const{

    if(this->size == 0){ throw std::length_error("Error: the structure is empty!");}

    else{

        return List<Data>::Front();
    }
} 


// Override function Top (Mutable)
template <typename Data>
Data& StackLst<Data>::Top(){

    if(this->size == 0){ throw std::length_error("Error: the structure is empty!");}

    else{

        return List<Data>::Front();
    }
}

// Override function Pop
template <typename Data>
void StackLst<Data>::Pop(){

    if(this->size == 0){ throw std::length_error("Error: the structure is empty!");}

    else{

        List<Data>::RemoveFromFront();
    }
}


// Override function TopNPop
template <typename Data>
Data StackLst<Data>::TopNPop(){

    Data element;

    if(this->size == 0){ throw std::length_error("Error: the structure is empty!");}

    else{

        element = List<Data>::FrontNRemove();
    }

    return element;
}


// Override function Push (Copy)
template <typename Data>
void StackLst<Data>::Push(const Data& element) noexcept{

    List<Data>::InsertAtFront(element);
}


// Override function Push (Move)
template <typename Data>
void StackLst<Data>::Push(Data&& element) noexcept{

    List<Data>::InsertAtFront(element);
}


/* ************************************************************************** */

}
