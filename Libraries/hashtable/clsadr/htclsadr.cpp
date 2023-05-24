
namespace lasd {

/* ************************************************************************** */

// Default constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(){
    
    size = 0;
    vec = Vector<List<Data>>(2);
}


// Specific constructor #1
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong otherSize){
    
    size = otherSize;
    vec = Vector<List<Data>>(otherSize);
}


// Specific constructor #2
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const MappableContainer<Data>& container){
    
    vec = Vector<List<Data>>(container.Size());

    container.Map(
        
        [this](const Data& data){ this->Insert(data); });
}


// Specific constructor #3
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong otherSize, const MappableContainer<Data>& container){
    
    vec = Vector<List<Data>>(otherSize);
    
    container.Map([this](const Data& data){ this->Insert(data); });
}


// Specific constructor #4
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MutableMappableContainer<Data>&& container){
    
    vec = Vector<List<Data>>(container.Size());
    
    container.Map([this](Data& data){ this->Insert(std::move(data)); });
}


// Specific constructor #5
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const ulong otherSize, MutableMappableContainer<Data>&& container){
    
    vec = Vector<List<Data>>(otherSize);
    
    container.Map([this](Data& data){ this->Insert(std::move(data)); });
}


// Copy Constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& hashtable){
    
    size = hashtable.size;
    vec = hashtable.vec;
}


// Move Constructor
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& hashtable){
    
    std::swap(size, hashtable.size);
    std::swap(vec, hashtable.vec);
}


// Copy Assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator = (const HashTableClsAdr<Data>& hashtable){
    
    size = hashtable.size;
    vec = hashtable.vec;
    return *this;
}


// Move Assignment
template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data>&& hashtable) noexcept{
    
    std::swap(size, hashtable.size);
    std::swap(vec, hashtable.vec);
    return *this;
}


// Operator ==
template <typename Data>
bool HashTableClsAdr<Data>::operator == (const HashTableClsAdr<Data>& hashtable) const noexcept{

    if(size != hashtable.Size()){return false;}; 

    bool check = true;

    for (ulong i = 0; i < vec.Size(); i++){

        hashtable.vec[i].Map([this, &check](const Data& data){

            if(!this->Exists(data)){check = false;}; 
        });
    }
    
    return check;
}


// Operator !=
template <typename Data>
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr<Data>& hashtable) const noexcept{
    
    return !(operator == (hashtable));
}


// Overrides function Insert (Copy of value)
template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& data) noexcept{
    
    ulong hash = HashKey(data) % vec.Size();
    
    if(vec[hash].Insert(data)){
        
        size++;
        return true;
    }
    
    return false;
}


// Override function Insert (Move of the value)
template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& data) noexcept{

    ulong hash = HashKey(data) % vec.Size();
    
    if (vec[hash].Insert(std::move(data))){
        
        size++;
        return true;
    }
    
    return false;
}


// Override function Remove
template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& data) noexcept{
    
    ulong hash = HashKey(data) % vec.Size();
    
    if(vec[hash].Remove(data)){
    
        size--;
        return true;
    }
    
    return false;
}


// Override function Exists
template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data) const noexcept{
    
    ulong hash = HashKey(data) % vec.Size();

    return vec[hash].Exists(data);
}


// Override function Resize
template <typename Data>
void HashTableClsAdr<Data>::Resize(const ulong newSize) noexcept{

    if(newSize == 0){ Clear(); }

    else{
    
        HashTableClsAdr<Data> temp(newSize);
        temp.size = 0;
    
        for(ulong i = 0; i < vec.Size(); i++){

            vec[i].Map(
                
                [this, &temp](const Data& data){ temp.Insert(data); });
        }
    
        std::swap(*this, temp);
    }
}


// Override function Clear
template <typename Data>
void HashTableClsAdr<Data>::Clear() noexcept{
    
    size = 0;    
    vec.Clear();
    vec.Resize(2);
}

/* ************************************************************************** */

}
