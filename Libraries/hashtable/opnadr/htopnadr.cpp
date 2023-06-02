
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
    capacity = newCapacity;
    table = Vector<Data>(capacity);
    slots = Vector<int>(capacity);
    DefaultVector(table);
    DefaultVector(slots);
}


// Specific constructor #2
// Specific constructor #3
// Specific constructor #4
// Specific constructor #5
// Copy constructor
// Move constructor
// Destructor
// Copy assignment
// Move assignment
// Operator ==
// Operator !=
// Defining function Insert (Copy of value)
// Defining function Insert (Move of value)
// Defining function Remove
// Defining function Exists
// Defining function Resize
// Defining function Clear
// AUXILIARY - function HashKey
// AUXILIARY - function Find
// AUXILIARY - function FindEmpty
// AUXILIARY - function Remove

/**************************    Initializing Vectors     **************************/

// Initializing INT vectors
template <typename Data>
void HashTableOpnAdr<Data>::DefaultVector(Vector<int>& vec){
    for(ulong i = 0; i < vec.Size(); i++){ vec[i] = 0; }
}

// Initializing DOUBLE vectors
template <typename Data>
void HashTableOpnAdr<Data>::DefaultVector(Vector<double>& vec){
    for(ulong i = 0; i < vec.Size(); i++){ vec[i] = 0; }
}

// Initializing STRING vectors
template <typename Data>
void HashTableOpnAdr<Data>::DefaultVector(Vector<string>& vec){
    for(ulong i = 0; i < vec.Size(); i++){ vec[i] = ""; }
}

}
