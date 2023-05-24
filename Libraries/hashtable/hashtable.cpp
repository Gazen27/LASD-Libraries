
#include <string>

namespace lasd {

////////////////////////////////////////////////////////////// Hashable

// Defining Operator () for int
template<>
inline ulong Hashable<int>::operator()(const int& value) noexcept{ return value * value; }


// Defining Operator () for double
template<>
inline ulong Hashable<double>::operator()(const double& val) noexcept{

    double decimalPart = fmod(val, 1.0);

    const double scale = 1000000.0;
    unsigned int scaledDecimal = static_cast<unsigned int>(round(decimalPart * scale));

    unsigned int hash = scaledDecimal % 997;

    return hash;
}


// Defining Operator () for string
template<>
inline ulong Hashable<string>::operator()(const string& value) noexcept{
    
    unsigned int hash = 5381;

    for (char carattere : value) { hash = ((hash << 5) + hash) + carattere; }
    return hash;
}


////////////////////////////////////////////////////////////// Hashtable

//Defining function HashKey
template <typename Data>
inline ulong HashTable<Data>::HashKey(const Data& element) const{

   Hashable<Data> hasher;
   return hasher(element);
}


}
