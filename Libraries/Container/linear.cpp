
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/////////////////////////////////////////////////////////////////////// LinearContainer

// Override operator ==
template <typename Data>
bool LinearContainer<Data>::operator == (const LinearContainer<Data>& otherContainer) const noexcept{

    if((*this).Size() != otherContainer.Size()){

        for(i=0; i<(this*).Size(); i++){

            if((*this)[i] != otherContainer[i]) {return false; }
        }

        return true;
    }

    else { return false; }
}

// Override operator !=
template <typename Data>
bool LinearContainer<Data>::operator != (const LinearContainer<Data>&) const noexcept{

    if((*this).Size() != otherContainer.Size()){

        for(i=0; i<(this*).Size(); i++){

            if((*this)[i] != otherContainer[i]) { return true; }
        }

        return false;
    }

    else { return true; }
}

// Override function Front (Non-Mutable version)
template <typename Data>
Data LinearContainer<Data>::Front() const {

    try{

        if((*this).Empty()) {

            throw std::length_error("Warning: empty structure!");
        }
        else {
            
            Data element = (*this)[0];
            return element;
        }

    } catch (length_error& exc) {
        
        cout << "Length error: " << exc.what() << endl;
  }

}

// Override function Front (Mutable version)
template <typename Data>
Data LinearContainer<Data>::Front() {

    // TODO
}

// Override function Back (Non-Mutable version)
template <typename Data>
Data LinearContainer<Data>::Back() const {

    try{

        if((*this).Empty()) {

            throw std::length_error("Warning: empty structure!");
        }
        else {
            
            Data element = (*this)[(*this).Size() - 1];
            return element;
        }

    } catch (length_error& exc) {
        
        cout << "Length error: " << exc.what() << endl;
  }

}

// Override function Back (Mutable version)
template <typename Data>
Data LinearContainer<Data>::Back() {

    // TODO
}

// Override function PreOrderMap (Non-Mutable version)
template <typename Data>
void LinearContainer<Data>::PreOrderMap(MapFunctor functor) const{

    // TODO
}

// Override function PostOrderMap (Non-Mutable version)
template <typename Data>
void LinearContainer<Data>::PostOrderMap(MapFunctor functor) const{

    // TODO
}

// Override function PreOrderMap (Mutable version)
template <typename Data>
void LinearContainer<Data>::PreOrderMap(MutableMapFunctor functor) const{

    // TODO
}

// Override function PostOrderMap (Mutable version)
template <typename Data>
void LinearContainer<Data>::PostOrderMap(MutableMapFunctor functor) const{

    // TODO
}

// Override function Exists
template <typename Data>
bool LinearContainer<Data>::Exists(const Data& element) const noexcept{

    for(i=0; i<(*this).Size(); i++){

        if((*this)[i] == element) { return true; }
    }

    return false;
}

}
