
typedef unsigned long ulong;

namespace lasd {

/* ************************************************************************** */

// Default constructor
// XXXXXXXXXXXXXXXXXX


// Specific constructor #1
template<typename Data>
Vector<Data>::Vector(const ulong mySize){

    size = mySize;
    elements = new Data[size];
}


// Specific constructor #2
template <typename Data>
Vector<Data>::Vector(const MappableContainer<Data>& otherContainer) noexcept{

    size = otherContainer.Size();
    elements = new Data[size];

    ulong index = 0;

    otherContainer.Map(
        [this, &index](const Data& e){

            elements[index++] = e;
        }
    );
}


// Specific constructor #3
template <typename Data>
Vector<Data>::Vector(MutableMappableContainer<Data>&& otherContainer) noexcept{

    size = otherContainer.Size();
    elements = new Data[size];

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
    
    size = oldVector.Size();
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

    Resize(otherVector.Size());

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

    size = 0;
    delete[] elements;
    elements = nullptr;
}


// Defining function Resize
template <typename Data>
void Vector<Data>::Resize(const ulong newSize) noexcept{

    if(newSize == 0) { Clear(); }

    else{

        Data* temp = new Data[newSize];

        if(size > newSize){

            for(ulong i = 0; i < newSize; i++){
                temp[i] = elements[i];
            }
        }

        else{

            for(ulong i = 0; i < size; i++){
                temp[i] = elements[i];
            }
        }

        size = newSize;
        std::swap(elements, temp);
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
void Vector<Data>::Sort() noexcept{ // PROBABILE ERRORE: J >=0 A CAUSA DI ULONG

    ulong j;
    Data temp;

    for(ulong i = 1; i < size; i++) {
        
		temp = elements[i];
        j = i - 1;
        
		while((elements[j] > temp) && (j >= 0)) { 
		    
			elements[j+1] = elements[j]; 
            j--;
        }

		elements[j + 1] = temp;
	}
}

}
