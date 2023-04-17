
namespace lasd {

/* ************************************************************************** */

// Default constructor
// XXXXXXXXXXXXXXXXXX

// Specific constructor #1: StackVec obtained from a MappableContainer
template <typename Data>
StackVec<Data>::StackVec(const MappableContainer<Data>& container) noexcept{

    size = container.size;
    elements = new Data[size];
    level = 0;

    container.Map(

        [this](const Data& e){ this->Push(e); }
    );
}


// Specific constructor #2: StackVec obtained from a MutableMappableContainer
template <typename Data>
StackVec<Data>::StackVec(MutableMappableContainer<Data>&& container) noexcept{

    size = container.size;
    elements = new Data[size];
    level = 0;

    container.Map(

        [this](const Data& e){ this->Push(std::move(e)); }
    );
}


// Copy constructor
template <typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& otherStack){

    size = otherStack.size;
    elements = new Data[size];
    level = 0;

    for(ulong i = 0; i < otherStack.level; i++){

        this->Push(otherStack.elements[i]);
    }
}


// Move constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& otherStack) noexcept{

    size = otherStack.size;
    elements = new Data[size];
    level = 0;

    for(ulong i = 0; i < otherStack.level; i++){

        this->Push(std::move(otherStack.TopNPop()));
    }
}


// Destructor
template <typename Data>
StackVec<Data>::~StackVec(){

    Clear();
    delete[] elements;
}


// Copy assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator = (const StackVec<Data>& otherStack) noexcept{

    Clear();
    size = otherStack.size;
    level = 0;

    for(ulong i = 0; i < otherStack.level; i++){

        this->Push(otherStack.elements[i]);
    }
}


// Move assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator = (StackVec<Data>&& otherStack) noexcept{

    Clear();
    size = otherStack.size;
    level = 0;

    for(ulong i = 0; i < otherStack.level; i++){

        this->Push(std::move(otherStack.TopNPop()));
    }
}


// Operator ==
template <typename Data>
bool StackVec<Data>::operator == (const StackVec<Data>& otherStack) const noexcept{

    if(this->size == otherStack.size && this->level == otherStack.level){

        for(ulong i = 0; i < level; i++){

            if(this->elements[i] != otherStack.elements[i]){ return false; }
        }

        return true;
    }

    else{ return false; }
}


// Operator !=
template <typename Data>
bool StackVec<Data>::operator != (const StackVec<Data>& otherStack) const noexcept{

    return !((*this) == otherStack);
}


// Override function Top (Non-Mutable)
template <typename Data>
const Data& StackVec<Data>::Top() const{

    if(this.level == 0 || this->size == 0){ throw std::length_error("Error: the structure is empty!"); }

    Data& e = elements[level - 1];
    return e;
} 


// Override function Top (Mutable)
template <typename Data>
Data& StackVec<Data>::Top(){

    if(this.level == 0 || this->size == 0){ throw std::length_error("Error: the structure is empty!"); }

    Data& e = std::move(elements[level - 1]);
    return e;
}

// Override function Pop
template <typename Data>
void StackVec<Data>::Pop(){

    if(this.level == 0 || this->size == 0){ throw std::length_error("Error: the structure is empty!"); }

    level = level - 1;
}


// Override function TopNPop
template <typename Data>
Data StackVec<Data>::TopNPop(){

    if(this.level == 0 || this->size == 0){ throw std::length_error("Error: the structure is empty!"); }

    Data e = this->Top();
    this->Pop();

    return e;
}


// Override function Push (Copy)
template <typename Data>
void StackVec<Data>::Push(const Data& e) noexcept{

    if(size == 0){ size = 1; }

    if(level == size){ this->Expand(); }

    level = level + 1;
    elements[level] = e;
}


// Override function Push (Move)
template <typename Data>
void StackVec<Data>::Push(Data&& e) noexcept{

    if(size == 0){ size = 1; }

    if(level == size){ this->Expand(); }

    level = level + 1;
    elements[level] = std::move(e);
}


// Override function Empty
template <typename Data>
bool StackVec<Data>::Empty() const noexcept{

    if(this->level == 0 || this->size == 0){ return true; }
    else{ return false; }
}


// Override function Size
template <typename Data>
ulong StackVec<Data>::Size() const noexcept{

    return this->level;
}


// Override function Clear
template <typename Data>
void StackVec<Data>::Clear() noexcept{

    size = 0; 
    level = 0;
}


// Defining function Expand
template <typename Data>
void StackVec<Data>::Expand(){

    this->size = size*2;
}


// Defining function Reduce
template <typename Data>
void StackVec<Data>::Reduce(){

    if(this->level <= size/2){ size = size/2; }
    else{

        size = size/2;
        level = size;
    }
}

/* ************************************************************************** */

}
