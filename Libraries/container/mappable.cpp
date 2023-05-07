
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

///////////////////////////////////////////////////////////// PreOrderMappableContainer

// Override function Map
template <typename Data>
void PreOrderMappableContainer<Data>::Map(MapFunctor functor) const{

    PreOrderMap(functor);
}


// Override function PreOrderFold
template <typename Data>
void PreOrderMappableContainer<Data>::PreOrderFold(FoldFunctor f, void* accumulator) const{

    PreOrderMap(
        [f, accumulator](const Data& element){

            f(element, accumulator);
        }
    );
}


///////////////////////////////////////////////////////////// PostOrderMappableContainer

// Override function Map
template <typename Data>
void PostOrderMappableContainer<Data>::Map(MapFunctor functor) const{

    PostOrderMap(functor);
}


// Override function PostOrderFold
template <typename Data>
void PostOrderMappableContainer<Data>::PostOrderFold(FoldFunctor f, void* accumulator) const{

    PostOrderMap(
        [f, accumulator](const Data& element){

            f(element, accumulator);
        }
    );
}


///////////////////////////////////////////////////////////// InOrderMappableContainer

// Override function Map
template <typename Data>
void InOrderMappableContainer<Data>::Map(MapFunctor functor) const{

    InOrderMap(functor);
}


// Override function InOrderFold
template <typename Data>
void InOrderMappableContainer<Data>::InOrderFold(FoldFunctor f, void* accumulator) const{

    InOrderMap(
        [f, accumulator](const Data& element){

            f(element, accumulator);
        }
    );
}


///////////////////////////////////////////////////////////// BreadthMappableContainer

// Override function Map
template <typename Data>
void BreadthMappableContainer<Data>::Map(MapFunctor functor) const{

    BreadthMap(functor);
}


// Override function BreadthFold
template <typename Data>
void BreadthMappableContainer<Data>::BreadthFold(FoldFunctor f, void* accumulator) const{

    BreadthMap(
        [f, accumulator](const Data& element){

            f(element, accumulator);
        }
    );
}

///////////////////////////////////////////////////////////// MutablePreOrderMappableContainer

// Override function Map
template <typename Data>
void MutablePreOrderMappableContainer<Data>::Map(MutableMapFunctor mapFunctor){

    PreOrderMap(mapFunctor);
}


///////////////////////////////////////////////////////////// MutablePostOrderMappableContainer

// Override function Map
template <typename Data>
void MutablePostOrderMappableContainer<Data>::Map(MutableMapFunctor mapFunctor){

    PostOrderMap(mapFunctor);
}


///////////////////////////////////////////////////////////// MutableInOrderMappableContainer

// Override function Map
template <typename Data>
void MutableInOrderMappableContainer<Data>::Map(MutableMapFunctor mapFunctor){

    InOrderMap(mapFunctor);
}


///////////////////////////////////////////////////////////// MutableBreadthMappableContainer

// Override function Map
template <typename Data>
void MutableBreadthMappableContainer<Data>::Map(MutableMapFunctor mapFunctor){

    BreadthMap(mapFunctor);
}

}

/* ************************************************************************** */
