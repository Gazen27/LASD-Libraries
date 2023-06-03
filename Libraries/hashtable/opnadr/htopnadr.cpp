
namespace lasd {

/* ************************************************************************** */

// Default constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(){
    table = Vector<Data>(capacity);
    flags = Vector<int>(capacity);
    DefaultVector(table);
    DefaultVector(flags);
}


// Specific constructor #1
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(ulong newCapacity) noexcept{
    capacity = GreaterPower(newCapacity);
    table = Vector<Data>(capacity);
    flags = Vector<int>(capacity);
    DefaultVector(table);
    DefaultVector(flags);
}


// Specific constructor #2
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const MappableContainer<Data>& container) noexcept{
    table = Vector<Data>(capacity);
    flags = Vector<int>(capacity);
    DefaultVector(table);
    DefaultVector(flags);
    container.Map(
        [this](const Data& element){ this->Insert(element); }
    );
}


// Specific constructor #3
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(ulong newCapacity, const MappableContainer<Data>& container) noexcept{
    capacity = GreaterPower(newCapacity);
    table = Vector<Data>(capacity);
    flags = Vector<int>(capacity);
    DefaultVector(table);
    DefaultVector(flags);
    container.Map(
        [this](const Data& element){ this->Insert(element); }
    );
}


// Specific constructor #4
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MutableMappableContainer<Data>&& container) noexcept{
    table = Vector<Data>(capacity);
    flags = Vector<int>(capacity);
    DefaultVector(table);
    DefaultVector(flags);
    container.Map(
        [this](Data&& element){ this->Insert(std::move(element)); }
    );
}


// Specific constructor #5
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(ulong newCapacity, MutableMappableContainer<Data>&& container) noexcept{
    capacity = GreaterPower(newCapacity);
    table = Vector<Data>(capacity);
    flags = Vector<int>(capacity);
    DefaultVector(table);
    DefaultVector(flags);
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
    flags = Vector<int>(otherHT.flags);
}


// Move constructor
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& otherHT) noexcept{
    std::swap(capacity, otherHT);
    std::swap(size, otherHT.size);
    std::swap(hash, otherHT.hash);
    table = Vector<Data>(std::move(otherHT.table));
    flags = Vector<int>(std::move(otherHT.flags));
}


// Copy assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator = (const HashTableOpnAdr<Data>& otherHT) noexcept{
    capacity = otherHT.capacity;
    size = otherHT.size;
    hash = otherHT.hash;
    table = otherHT.table;
    flags = otherHT.flags;
    return *this;
}


// Move assignment
template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator = (HashTableOpnAdr<Data>&& otherHT) noexcept{
    std::swap(capacity, otherHT.capacity);
    std::swap(size, otherHT.size);
    std::swap(hash, otherHT.hash);
    std::swap(table, otherHT.table);
    std::swap(flags, otherHT.flags);
    return *this;
}


// Operator ==
template <typename Data>
bool HashTableOpnAdr<Data>::operator == (const HashTableOpnAdr<Data>& otherHT) const noexcept{
    if(this->size != otherHT.size){ return false; }
    if(this->size == 0){ return true; }
    for(ulong i = 0; i < capacity; i ++){
        if(flags[i] == 1 && !otherHT.Exists(this->table[i])){ return false; }
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
    if(this->Exists(element)){ return false; }
    if(size == capacity - 1){ Resize(capacity + 1); }
    ulong index = FindEmpty(element);
    if(index == capacity){ return false; }
    table[index] = element;
    size++;
    flags[index] = 1;
    return true;
}


// Defining function Insert (Move of value)
template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& element) noexcept{
    if(this->Exists(element)){ return false; }
    if(size == capacity - 1){ Resize(capacity + 1); }
    ulong index = FindEmpty(element);
    if(index == capacity){ return false; }
    table[index] = std::move(element);
    size++;
    flags[index] = 1;
    return true;
}


// Defining function Remove
template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& element) noexcept{
    if(size == 0){ return false; }
    ulong index = Find(element);
    if(index == capacity){ return false; }
    flags[index] = 2;
    size--;
    return true;
}


// Defining function Exists
template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& element) const noexcept{
    if(size == 0){ return false; }
    ulong index = Find(element);
    if(index == capacity){ return false; }
    if(table[index] == element){ return true; }
    return false;
}


// Defining function Resize
template <typename Data>
void HashTableOpnAdr<Data>::Resize(ulong newCapacity) noexcept{
    if(newCapacity == capacity){ return; }
    HashTableOpnAdr<Data> temp(GreaterPower(newCapacity));
    temp.size = 0;
    for(ulong i = 0; i < this->capacity; i++){
        if(this->flags[i] == 1){ temp.Insert(this->table[i]); }       
    }
    *this = std::move(temp);
}


// Defining function Clear
template <typename Data>
void HashTableOpnAdr<Data>::Clear() noexcept{
    if(size == 0){ return; }
    DefaultVector(table);
    DefaultVector(flags);
    size = 0;
}


// AUXILIARY - function Probing
template <typename Data>
ulong HashTableOpnAdr<Data>::Probing(const Data& element, ulong check) const noexcept{
    ulong index = (HashKey(element) + (check * (check + 1 )) / 2) % capacity;
    return index;
}


// AUXILIARY - function Find
template <typename Data>
ulong HashTableOpnAdr<Data>::Find(const Data& element) const noexcept{
    ulong index = 0;
    ulong check = 0;
    while(check < capacity){
        index = Probing(element, check);
        if(flags[index] == 1 && table[index] == element){ return index; }
        check = check + 1;
    }
    return capacity;
}


// AUXILIARY - function FindEmpty
template <typename Data>
ulong HashTableOpnAdr<Data>::FindEmpty(const Data& element) noexcept{
    ulong index = 0;
    ulong check = 0;
    while(check < capacity){
        index = Probing(element, check);
        if(flags[index] == 0 || flags[index] == 2){ return index; }
        else{
            if(table[index] == element && flags[index] == 1){ return capacity; }
            else{ check++; }
        }
    }
    return capacity;
}

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
