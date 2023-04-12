
#include <stdexcept>

/* ************************************************************************** */

typedef unsigned long ulong;

namespace lasd {

// Defining function InsertAll (Non-Mutable version)
template <typename Data>
bool DictionaryContainer<Data>::InsertAll(const MappableContainer<Data>& container) noexcept{
    
    bool check = true;

    container.Map(

        [this, &check](const Data& element){ check = Insert(element); }
    );

    return check;
}


// Defining function InsertAll (Mutable version)
template <typename Data>
bool DictionaryContainer<Data>::InsertAll(MutableMappableContainer<Data>&& container) noexcept{

    bool check = true;

    container.Map(

        [this, &check](const Data& element){ check = Insert(std::move(element)); }
    );

    return check;
}


// Defining function RemoveAll
template <typename Data>
bool DictionaryContainer<Data>::RemoveAll(const MappableContainer<Data>& container) noexcept{

    bool check = true;

    container.Map(

        [this, &check](const Data& element){ check = Remove(element); }
    );

    return check;
}


// Defining function InsertSome (Non-Mutable version)
template <typename Data>
bool DictionaryContainer<Data>::InsertSome(const MappableContainer<Data>& container) noexcept{
    
    bool check = false;

    container.Map(

        [this, &check](const Data& element){ check = Insert(element); }
    );

    return check;
}


// Defining function InsertSome (Mutable version)
template <typename Data>
bool DictionaryContainer<Data>::InsertSome(MutableMappableContainer<Data>&& container) noexcept{

    bool check = false;

    container.Map(

        [this, &check](const Data& element){ check = Insert(std::move(element)); }
    );

    return check;
}


// Defining function RemoveSome
template <typename Data>
bool DictionaryContainer<Data>::RemoveSome(const MappableContainer<Data>& container) noexcept{

    bool check = false;

    container.Map(

        [this, &check](const Data& element){ check = Remove(element); }
    );

    return check;
}

}
