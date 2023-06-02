
namespace lasd {

/* ************************************************************************** */

// Default constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(){
    table = Vector<Data>(capacity);
    slots = Vector<int>(capacity);
    DefaultVector(table);
    DefaultVector(slots);
}


// Specific constructor #1
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(ulong newCapacity) noexcept{
    capacity = GreaterPower(newCapacity);
    table = Vector<Data>(capacity);
    slots = Vector<int>(capacity);
    DefaultVector(table);
    DefaultVector(slots);
}


// Specific constructor #2
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const MappableContainer<Data>& container) noexcept{
    table = Vector<Data>(capacity);
    slots = Vector<int>(capacity);
    DefaultVector(table);
    DefaultVector(slots);
    container.Map(
        [this](const Data& element){ this->Insert(element); }
    );
}


// Specific constructor #3
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(ulong newCapacity, const MappableContainer<Data>& container) noexcept{
    capacity = GreaterPower(newCapacity);
    table = Vector<Data>(capacity);
    slots = Vector<int>(capacity);
    DefaultVector(table);
    DefaultVector(slots);
    container.Map(
        [this](const Data& element){ this->Insert(element); }
    );
}


// Specific constructor #4
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MutableMappableContainer<Data>&& container) noexcept{
    table = Vector<Data>(capacity);
    slots = Vector<int>(capacity);
    DefaultVector(table);
    DefaultVector(slots);
    container.Map(
        [this](Data&& element){ this->Insert(std::move(element)); }
    );
}


// Specific constructor #5
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(ulong newCapacity, MutableMappableContainer<Data>&& container) noexcept{
    capacity = GreaterPower(newCapacity);
    table = Vector<Data>(capacity);
    slots = Vector<int>(capacity);
    DefaultVector(table);
    DefaultVector(slots);
    container.Map(
        [this](Data&& element){ this->Insert(std::move(element)); }
    );
}


// Copy constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data>& otherHT) noexcept{
    capacity = otherHT.capacity;
    size = otherHT.size;
    hash = otherHT.hash;
    table = Vector<Data>(otherHT.table);
    slots = Vector<int>(otherHT.slots);
}


// Move constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& otherHT) noexcept{
    std::swap(capacity, otherHT);
    std::swap(size, otherHT.size);
    std::swap(hash, otherHT.hash);
    table = Vector<Data>(std::move(otherHT.table));
    slots = Vector<int>(std::move(otherHT.slots));
}


// Copy assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator = (const HashTableOpnAdr<Data>& otherHT) noexcept{
    capacity = otherHT.capacity;
    size = otherHT.size;
    hash = otherHT.hash;
    table = otherHT.table;
    slots = otherHT.slots;
    return *this;
}


// Move assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator = (HashTableOpnAdr<Data>&& otherHT) noexcept{
    std::swap(capacity, otherHT.capacity);
    std::swap(size, otherHT.size);
    std::swap(hash, otherHT.hash);
    std::swap(table, otherHT.table);
    std::swap(slots, otherHT.slots);
    return *this;
}


// Operator ==
template <typename Data>
bool HashTableOpnAdr<Data>::operator == (const HashTableOpnAdr<Data>& otherHT) const noexcept{
    if(this->size != otherHT.size){ return false; }
    if(this->size == 0){ return true; }
    for(ulong i = 0; i < capacity; i ++){
        if(!otherHT.Exists(this->table[i])){ return false; }
    }
    return true;
}


// Operator !=
template <typename Data>
bool HashTableOpnAdr<Data>::operator != (const HashTableOpnAdr<Data>& otherHT) const noexcept{
    return !((*this) == otherHT);
}


// Defining function Insert (Copy of value)
template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& element) noexcept{
    //////////////////////////// TODO
    return true;
}


// Defining function Insert (Move of value)
template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& element) noexcept{
    //////////////////////////// TODO
    return true;
}


// Defining function Remove
template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& element) noexcept{
    //////////////////////////// TODO
    return true;
}


// Defining function Exists
template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& element) const noexcept{
    /////////////////////////// TODO
    return true;
}


// Defining function Resize
template <typename Data>
void HashTableOpnAdr<Data>::Resize(ulong newCapacity) noexcept{
    /////////////////////////// TODO
}


// Defining function Clear
template <typename Data>
void HashTableOpnAdr<Data>::Clear() noexcept{
    /////////////////////////// TODO
}


// AUXILIARY - function HashKey
// AUXILIARY - function Find
// AUXILIARY - function FindEmpty
// AUXILIARY - function Remove

/**************************    Initializing Vectors     **************************/

// Initializing INT vectors
template <typename Data>
void HashTableOpnAdr<Data>::DefaultVector(Vector<int>& vec){
    for(ulong i = 0; i < capacity; i++){ vec[i] = 0; }
}

// Initializing DOUBLE vectors
template <typename Data>
void HashTableOpnAdr<Data>::DefaultVector(Vector<double>& vec){
    for(ulong i = 0; i < capacity; i++){ vec[i] = 0; }
}

// Initializing STRING vectors
template <typename Data>
void HashTableOpnAdr<Data>::DefaultVector(Vector<std::string>& vec){
    for(ulong i = 0; i < capacity; i++){ vec[i] = ""; }
}

}
