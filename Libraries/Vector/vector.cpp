
namespace lasd {

/* ************************************************************************** */

// Default constructor
// XXXXXXXXXXXXXXXXXX


// Specific constructor #1
template<typename Data>
Vector<Data>::Vector(const ulong mySize){

    elements = new Data[mySize];
    size = newSize;
}


// Specific constructor #2
// ???????????????????????


// Specific constructor #3
// ???????????????????????


// Copy constructor
template <typename Data>
Vector<Data>::Vector(const Vector<Data>& oldVector){
    
    size = oldVector.Size();
    elements = new Data[size];

    for(int i = 0; i < size; i++){
        elements[i] = oldVector[i];
    }
}

/* ************************************************************************** */

}
