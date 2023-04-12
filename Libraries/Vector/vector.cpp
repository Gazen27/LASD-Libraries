
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

    size = otherVector.Size();
    elements = new Data[size];

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
}

}
