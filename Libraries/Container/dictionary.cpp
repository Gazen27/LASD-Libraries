
#include <stdexcept>

/* ************************************************************************** */

typedef unsigned long ulong;

namespace lasd {

template <typename Data>
bool DictionaryContainer<Data>::InsertAll(const MappableContainer& container) noexcept{

    container.Map(

        [/*???*/](const Data& element){ Insert(element); }
    )
}

template <typename Data>
bool DictionaryContainer<Data>::InsertAll(MappableContainer&& container) noexcept{

    //////// TODO
}

}
