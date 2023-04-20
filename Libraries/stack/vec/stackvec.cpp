
namespace lasd {

/* *****************************************************************************/

// Default constructor
template <typename Data>
StackVec<Data>::StackVec() : Vector<Data>::Vector(8) {}


// Specific constructor #1: StackVec obtained from a MappableContainer
template <typename Data>
StackVec<Data>::StackVec(const MappableContainer<Data>& container) : Vector<Data>::Vector(container) { 
    
    level = size; 
}


// Specific constructor #2: StackVec obtained from a MutableMappableContainer
template <typename Data>
StackVec<Data>::StackVec(MutableMappableContainer<Data>&& container) : Vector<Data>(std::move(container)) {
   
    level = size;
}


// Copy constructor
template <typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& otherStack) : Vector<Data>((Vector<Data>&)otherStack) {
   
    level = otherStack.level;
}


// Move constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& otherStack) {
    
    std::swap(size, otherStack.size);
    std::swap(level, otherStack.level);
    std::swap(elements, otherStack.elements);
}


// Destructor
template <typename Data>
StackVec<Data>::~StackVec(){}   // ~StackVec() = default;


// Copy assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator = (const StackVec<Data>& otherStack) noexcept{
   
    Vector<Data>::operator=(otherStack);
    level = otherStack.level;
    return *this;
}


// Move assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator = (StackVec<Data>&& otherStack) noexcept {
 
    Vector<Data>::operator=(std::move(otherStack));
    std::swap(level, otherStack.level);
    return *this;
}


// Operator ==
template <typename Data>
bool StackVec<Data>::operator == (const StackVec<Data>& otherStack) const noexcept{
   
    if(level == otherStack.level){

        for(ulong i = 0; i < level; i++){

            if(elements[i] != otherStack.elements[i]){ return false; }
        }

        return true;
    }

    return false;
}


// Operator !=
template <typename Data>
bool StackVec<Data>::operator != (const StackVec<Data>& otherStack) const noexcept{

    return !((*this) == otherStack);
}


// Override function Top (Non-Mutable)
template <typename Data>
const Data& StackVec<Data>::Top() const{
   
    if(this->level == 0 || this->size == 0){ throw std::length_error("Error: the structure is empty!"); }
    return elements[level - 1];;
} 


// Override function Top (Mutable)
template <typename Data>
Data& StackVec<Data>::Top(){
 
    if(this->level == 0 || this->size == 0){ throw std::length_error("Error: the structure is empty!"); }
    return elements[level - 1];
}


// Override function Pop
template <typename Data>
void StackVec<Data>::Pop(){
   
    if(this->level == 0 || this->size == 0){ throw std::length_error("Error: the structure is empty!"); }
    
    level = level - 1;
  
    if(level < size/4){ Reduce(); }
}


// Override function TopNTop
template <typename Data>
Data StackVec<Data>::TopNPop(){
    
    if(this->level == 0 || this->size == 0){ throw std::length_error("Error: the structure is empty!"); }
 
    Data e = this->Top();
    this->Pop();
    
    return e;
}


// Override function Push (Copy)
template <typename Data>
void StackVec<Data>::Push(const Data& e) noexcept{
   
    if(level > size - 1){ Expand(); }

    elements[level] = e;
    level = level + 1;
}


// Override function Push (Move)
template <typename Data>
void StackVec<Data>::Push(Data&& e) noexcept{

    if(level < size){ Expand(); }

    elements[level] = std::move(e);
    level = level + 1;
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


// Defining my extra function AllocatedSize
template <typename Data>
ulong StackVec<Data>::AllocatedSize() const noexcept{

    return this->size;
}


// Override function Clear
template <typename Data>
void StackVec<Data>::Clear() noexcept{
    
    Vector<Data>::Clear();
    
    elements = new Data[8];
    size = 8;
    level = 0;
}


// Override function Expand
template <typename Data>
void StackVec<Data>::Expand(){

    Vector<Data>::Resize(size*2 + 1);
}


// Override function Reduce
template <typename Data>
void StackVec<Data>::Reduce(){
    
    Vector<Data>::Resize(size/2);
}

}
