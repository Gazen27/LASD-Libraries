
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

// Override function from TestableContainer
template<typename Data>
bool FoldableContainer<Data>::Exists(const Data& element) const noexcept{

    FoldFunctor f = [element](const Data& value, void * accumulator){ 
    
        if(element == value){ accumulator = true; }
    };

    bool acc = false;
    Fold(f, &acc);

    return acc;
}


// Override function Fold from PreOrderFoldableContainer
template<typename Data>
void PreOrderFoldableContainer<Data>::Fold(FoldFunctor f, void* accumulator) const{
    
    PreOrderFold(f, accumulator);
}


// Override function Fold from PostOrderFoldableContainer
template<typename Data>
void PostOrderFoldableContainer<Data>::Fold(FoldFunctor f, void* accumulator) const{

    PostOrderFold(f, accumulator);
}

/* ************************************************************************** */

}
