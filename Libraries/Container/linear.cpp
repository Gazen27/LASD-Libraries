
#include <stdexcept>

/* ************************************************************************** */

typedef unsigned long ulong;

namespace lasd {

/////////////////////////////////////////////////////////////////////// LinearContainer

// Override operator ==
template <typename Data>
bool LinearContainer<Data>::operator == (const LinearContainer<Data>& otherContainer) const noexcept{

    if((*this).Size() != otherContainer.Size()){

        for(ulong i=0; i<(this*).Size(); i++){

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

        for(ulong i=0; i<(this*).Size(); i++){

            if((*this)[i] != otherContainer[i]) { return true; }
        }

        return false;
    }

    else { return true; }
}

// Override function Front (Non-Mutable version)
template <typename Data>
Data LinearContainer<Data>::Front() const {

    if((*this).Empty()) { throw std::length_error("Warning: empty structure!"); }
        
    else { return (*this)[0]; }

}

// Override function Front (Mutable version)
template <typename Data>
Data LinearContainer<Data>::Front() {

    if((*this).Empty()) { throw std::length_error("Warning: empty structure!"); }

    else { return (*this)[0]; }
}

// Override function Back (Non-Mutable version)
template <typename Data>
Data LinearContainer<Data>::Back() const {

    if((*this).Empty()) { throw std::length_error("Warning: empty structure!"); }

    else { return (*this)[(*this).Size() - 1]; }
}

// Override function Back (Mutable version)
template <typename Data>
Data LinearContainer<Data>::Back() {

    if((*this).Empty()) { throw std::length_error("Warning: empty structure!"); }

    else { return (*this)[(*this).Size() - 1]; }
}

// Override function PreOrderMap (Non-Mutable version)
template <typename Data>
void LinearContainer<Data>::PreOrderMap(MapFunctor functor) const{

    if(!(*this).Empty()){

        for(ulong i=0; i<(*this).Size(); i++){

            functor((*this)[i]);
        }
    }
}

// Override function PostOrderMap (Non-Mutable version)
template <typename Data>
void LinearContainer<Data>::PostOrderMap(MapFunctor functor) const{

    if(!(*this).Empty()){

        for(ulong i=(*this).Size()-1; i>0; i--){

            functor((*this)[i]);
        }
    }
}

// Override function PreOrderMap (Mutable version)
template <typename Data>
void LinearContainer<Data>::PreOrderMap(MutableMapFunctor functor) {

    if(!(*this).Empty()){

        for(ulong i=0; i<(*this).Size(); i++){

            functor((*this)[i]);
        }
    }
}

// Override function PostOrderMap (Mutable version)
template <typename Data>
void LinearContainer<Data>::PostOrderMap(MutableMapFunctor functor) {

    if(!(*this).Empty()){

        for(ulong i=(*this).Size()-1; i>0; i--){

            functor((*this)[i]);
        }
    }
}

// Override function Exists
template <typename Data>
bool LinearContainer<Data>::Exists(const Data& element) const noexcept{

    for(ulong i=0; i<(*this).Size(); i++){

        if((*this)[i] == element) { return true; }
    }

    return false;
}


/////////////////////////////////////////////////////////////////////// SortableLinearContainer

// Override function Sort
template <typename Data>
void SortableLinearContainer<Data>::Sort(SortableLinearContainer& container) noexcept{

    ulong j;
    Data temp;

    for(ulong i=1; i<(*this).Size(); i++) {
        
		temp = (*this)[i];
        j=i-1;
        
		while(((*this)[j] > temp) && (j >= 0)) { 
		    
			(*this)[j+1] = (*this)[j]; 
            j--;
        }

		(*this)[j+1] = temp;

		}
};

}
