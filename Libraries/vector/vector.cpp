
typedef unsigned long ulong;

namespace lasd {

/* ************************************************************************** */

// Default constructor
// XXXXXXXXXXXXXXXXXX


// Specific constructor #1: Given initial dimention
template<typename Data>
Vector<Data>::Vector(const ulong mySize){

    try{

        size = mySize;
        elements = new Data[size];
    }
    
    catch(std::bad_alloc){}
}


// Specific constructor #2: Vector obtained from a MappableContainer
template <typename Data>
Vector<Data>::Vector(const MappableContainer<Data>& otherContainer) noexcept{

    Resize(otherContainer.Size());

    ulong index = 0;

    otherContainer.Map(
        [this, &index](const Data& e){

            elements[index++] = e;
        }
    );
}


// Specific constructor #3: Vector obtained from a MutableMappableContainer
template <typename Data>
Vector<Data>::Vector(MutableMappableContainer<Data>&& otherContainer) noexcept{

    Resize(otherContainer.Size());

    ulong index = 0;

    otherContainer.Map(
        [this, &index](Data& e){

            elements[index++] = std::move(e);
        }
    );
}


// Copy constructor
template <typename Data>
Vector<Data>::Vector(const Vector<Data>& oldVector){
    
    size = oldVector.size;
    elements = new Data[size];

    for(ulong i = 0; i < size; i++){

        elements[i] = oldVector.elements[i];
    }
}


// Move constructor
template <typename Data>
Vector<Data>::Vector(Vector<Data>&& otherVector) noexcept{

    std::swap(size, otherVector.size);
    std::swap(elements, otherVector.elements);
}


// Destructor
template <typename Data>
Vector<Data>::~Vector(){

    delete[] elements;
}


// Copy assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator = (const Vector<Data>& otherVector) noexcept{

    Resize(otherVector.size);

    for(ulong i = 0; i < size; i++){

        elements[i] = otherVector.elements[i];
    }

    return *this;
}


// Move assignment
template <typename Data>
Vector<Data>& Vector<Data>::operator = (Vector<Data>&& otherVector) noexcept{

    std::swap(size, otherVector.size);
    std::swap(elements, otherVector.elements);

    return (*this);
}


// Operator ==
template <typename Data>
bool Vector<Data>::operator == (const Vector<Data>& otherVector) const noexcept{

    if(size == otherVector.size){

        for(ulong i = 0; i < size; i++){

            if(elements[i] != otherVector.elements[i]){ return false; } 
        }

        return true;
    }

    else { return false; }
}


// Operator !=
template <typename Data>
bool Vector<Data>::operator != (const Vector<Data>& otherVector) const noexcept{

    return !((*this) == otherVector);
}


// Defining function Clear
template <typename Data>
void Vector<Data>::Clear() noexcept{

    Resize(0);
}


// Defining function Resize
template <typename Data>
void Vector<Data>::Resize(const ulong newSize) noexcept{

    if(newSize == 0){
        
        delete[] elements;
        elements = nullptr;
        size = 0;     
    }

    else if(size == newSize){ return; }

    else{

        Data* temp = new Data[newSize];

        if(size > newSize){

            for(ulong i = 0; i < newSize; i++){ temp[i] = elements[i]; }
        }

        else if(newSize > size){

            for(ulong i = 0; i < size; i++){ temp[i] = elements[i]; }
        }

        std::swap(elements, temp);
        size = newSize;
        delete[] temp;
    }
}


// Operator [] (Non-Mutable)
template <typename Data>
const Data& Vector<Data>::operator [] (const ulong index) const{

    if(index >= size){ throw std::out_of_range("Error: index out of range"); }
    else{ return elements[index]; }
}

// Operator [] (Mutable)
template <typename Data>
Data& Vector<Data>::operator [] (const ulong index){

    if(index >= size){ throw std::out_of_range("Error: index out of range"); }
    else{ return elements[index]; }  
}


// Override function Sort
template <typename Data>
void Vector<Data>::Sort() noexcept{

    for (ulong i = 0; i < size - 1; i++){

        ulong index = i;

        for (ulong j = i + 1; j < size; j++){

            if(elements[j] < elements[index]){ index = j; }
        }

        if (index != i){std::swap(elements[index], elements[i]);}
    }
}

}
