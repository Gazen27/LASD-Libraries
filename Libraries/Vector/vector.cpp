
typedef unsigned long ulong;

namespace lasd {

/* ************************************************************************** */

// Default constructor
// XXXXXXXXXXXXXXXXXX


// Specific constructor #1
template<typename Data>
Vector<Data>::Vector(const ulong mySize){

    elements = new Data[mySize];
    (*this).size = mySize;
}


// Specific constructor #2
// ???????????????????????


// Specific constructor #3
// ???????????????????????


// Copy constructor
template <typename Data>
Vector<Data>::Vector(const Vector<Data>& oldVector){
    
    (*this).size = oldVector.Size();
    elements = new Data[(*this).size];

    for(ulong i = 0; i < (*this).size; i++){
        elements[i] = oldVector[i];
    }
}


}
