
#include <stdexcept>

/* ************************************************************************** */

typedef unsigned long ulong;

namespace lasd {

/////////////////////////////////////////////////////////////////////// LinearContainer

// Override operator ==
template <typename Data>
bool LinearContainer<Data>::operator == (const LinearContainer<Data>& otherContainer) const noexcept{

    if(size != otherContainer.size){

        for(ulong i = 0; i < size; i++){

            if((*this)[i] != otherContainer[i]) {return false; }
        }

        return true;
    }

    else { return false; }
}

// Override operator !=
template <typename Data>
bool LinearContainer<Data>::operator != (const LinearContainer<Data>& otherContainer) const noexcept{

    if(size != otherContainer.size){

        for(ulong i = 0; i < size; i++){

            if((*this)[i] != otherContainer[i]) { return true; }
        }

        return false;
    }

    else { return true; }
}

// Override function Front (Non-Mutable version)
template <typename Data>
const Data& LinearContainer<Data>::Front() const {

    if(size == 0) { throw std::length_error("Error: empty structure!"); }
        
    else { return (*this)[0]; }

}

// Override function Front (Mutable version)
template <typename Data>
Data& LinearContainer<Data>::Front() {

    if(size == 0) { throw std::length_error("Error: empty structure!"); }

    else { return (*this)[0]; }
}

// Override function Back (Non-Mutable version)
template <typename Data>
const Data& LinearContainer<Data>::Back() const {

    if(size == 0) { throw std::length_error("Error: empty structure!"); }

    else { return (*this)[size - 1]; }
}

// Override function Back (Mutable version)
template <typename Data>
Data& LinearContainer<Data>::Back() {

    if(size == 0) { throw std::length_error("Error: empty structure!"); }

    else { return (*this)[size - 1]; }
}

// Override function PreOrderMap (Non-Mutable version)
template <typename Data>
void LinearContainer<Data>::PreOrderMap(MapFunctor functor) const{

    if(!this->Empty()){

        for(ulong i=0; i < size; i++){

            functor((*this)[i]);
        }
    }
}

// Override function PostOrderMap (Non-Mutable version)
template <typename Data>
void LinearContainer<Data>::PostOrderMap(MapFunctor functor) const{

    if(!this->Empty()){

        for(ulong i = size; i > 0; i--){

            functor((*this)[i - 1]);
        }
    }
}

// Override function PreOrderMap (Mutable version)
template <typename Data>
void LinearContainer<Data>::PreOrderMap(MutableMapFunctor functor) {

    if(!this->Empty()){

        for(ulong i = 0; i < size; i++){

            functor((*this)[i]);
        }
    }
}

// Override function PostOrderMap (Mutable version)
template <typename Data>
void LinearContainer<Data>::PostOrderMap(MutableMapFunctor functor) {

    if(!this->Empty()){

        for(ulong i = size; i > 0; i--){

            functor((*this)[i - 1]);
        }
    }
}

// Override function Exists
template <typename Data>
bool LinearContainer<Data>::Exists(const Data& element) const noexcept{

    for(ulong i = 0; i < size; i++){

        if((*this)[i] == element) { return true; }
    }

    return false;
}

}
