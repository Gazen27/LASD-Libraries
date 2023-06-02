
namespace lasd {

/* ************************************************************************** */

// Default constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(){ table = Vector<List<Data>>(capacity); }


// Specific constructor #1
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(ulong newSize) noexcept{
    capacity = newSize;
    table = Vector<List<Data>>(capacity);
}


// Specific constructor #2
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const MappableContainer<Data>& container) noexcept{
    table = Vector<List<Data>>(capacity);
    container.Map(
        [this](const Data& element){ this->Insert(element); }
    );
}


// Specific constructor #3
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(ulong newSize, const MappableContainer<Data>& container) noexcept{
    capacity = newSize;
    table = Vector<List<Data>>(capacity);
    container.Map(
        [this](const Data& element){ this->Insert(element); }
    );
}


// Specific constructor #4
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MutableMappableContainer<Data>&& container) noexcept{
    table = Vector<List<Data>>(capacity);
    container.Map(
        [this](Data& element){ this->Insert(std::move(element)); }
    );
}


// Specific constructor #5
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(ulong newSize, MutableMappableContainer<Data>&& container) noexcept{
    capacity = newSize;
    table = Vector<List<Data>>(capacity);
    container.Map(
        [this](Data& element){ this->Insert(std::move(element)); }
    );
}


// Copy constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& otherHT) noexcept{
    capacity = otherHT.capacity;
    size = otherHT.size;
    table = Vector<List<Data>>(otherHT.table);
}


// Move constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& otherHT) noexcept{
    std::swap(capacity, otherHT.capacity);
    std::swap(size, otherHT.size);
    table = Vector<List<Data>>(std::move(otherHT.table));
}


// Copy assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator = (const HashTableClsAdr<Data>& otherHT) noexcept{
    capacity = otherHT.capacity;
    size = otherHT.size;
    table = Vector<List<Data>>(otherHT.table);
    
    return *this;
}


// Move assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator = (HashTableClsAdr<Data>&& otherHT) noexcept{
    std::swap(capacity, otherHT.capacity);
    std::swap(size, otherHT.size);
    std::swap(table, otherHT.table);

    return *this;
}


// Operator ==
template <typename Data>
bool HashTableClsAdr<Data>::operator == (const HashTableClsAdr<Data>& otherHT) const noexcept{
    if(this->size != otherHT.size){ return false; }
    if(this->size == 0){ return true; }
    for(ulong i = 0; i < capacity; i++){
        for(ulong j = 0; j < table[i].size; j++){
            if(!otherHT.Exists(table[i][j])){ return false; }
        }
    }
    return true;
}


// Operator !=
template <typename Data>
bool HashTableClsAdr<Data>::operator != (const HashTableClsAdr<Data>& otherHT) const noexcept{

    return !((*this) == otherHT);
}


// Override function Insert (Copy of value)
template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& element) noexcept{
    if(table[HasKey(element)].Insert(element)){
        size++;
        return true;
    }
    return false;
}


// Override function Insert (Move of value)
template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& element) noexcept{
    if(table[HashKey(element)].Insert(std::move(element))){
        size++;
        return true;
    }
    return false;
}


// Override function Remove
template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& element) noexcept{
    if(table[HashKey(element)].Remove(element)){
        size--;
        return true;
    }
    return false;
}


// Override function Exists
template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& element) const noexcept{
    if(size == 0){ return false; }
    if(table[HashKey(element)].Exists(element)){ return true; }
    return false;
}


// Override function Resize
template <typename Data>
void HashTableClsAdr<Data>::Resize(ulong newCapacity) noexcept{
    if(newCapacity > capacity){ capacity = newCapacity; }
    else if(newCapacity = capacity){ return; }
    else{
        HashTableClsAdr<Data> temp(newCapacity);
        temp.size = 0;
        for(ulong i = 0; i < this->capacity; i++){
            for(ulong j = 0; j < this->table[i].size; i++){
                temp.Insert(this->table[i][j]);
            }
        }
        *this = std::move(temp);
    }
}


// Override funcion Clear
template <typename Data>
void HashTableClsAdr<Data>::Clear() noexcept{
    if(size == 0){ return; }
    for(ulong i = 0; i < size; i++){ table[i].Clear(); }
    size = 0;
}

}
