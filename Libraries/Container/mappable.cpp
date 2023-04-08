
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

///////////////////////////////////////////////////////////// PreOrderMappableContainer

// Override function Map
template <typename Data>
void PreOrderMappableContainer<Data>::Map(MapFunctor functor) const{

    PreOrderMap(functor);
}

// Override function Fold
template <typename Data>
void PreOrderMappableContainer<Data>::Fold(FoldFunctor f, void* accumulator) const{

    PreOrderFold(f, accumulator);
}

// Override function PreOrderFold
template <typename Data>
void PreOrderMappableContainer<Data>::PreOrderFold(FoldFunctor f, void* accumulator) const{

    // ??????????????????????????????????????
}


///////////////////////////////////////////////////////////// PostOrderMappableContainer

// Override function Map
template <typename Data>
void PostOrderMappableContainer<Data>::Map(MapFunctor functor) const{

    PostOrderMap(functor);
}

// Override function Fold
template <typename Data>
void PostOrderMappableContainer<Data>::Fold(FoldFunctor f, void* accumulator) const{

    PostOrderFold(f, accumulator);
}

// Override function PostOrderFold
template <typename Data>
void PostOrderMappableContainer<Data>::PostOrderFold(FoldFunctor f, void* accumulator) const{

    // ??????????????????????????????????????

}


}
