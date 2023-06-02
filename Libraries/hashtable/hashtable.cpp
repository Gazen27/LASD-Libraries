#include <string>

namespace lasd {

/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////// Hashable

// Defining class for int type
template <>
class Hashable<int>{
    private:

        ulong A = Random();
        ulong B = Random();
    
    public:
        ulong operator()(const int& value) const noexcept{ return A * (value * value) + B;}
};


// Defining class for double type
template <>
class Hashable<double>{
    private:

        ulong A = Random();
        ulong B = Random();
        ulong C = Random();
        ulong D = Random();
    
    public:
        ulong operator()(const double& value) const noexcept{
            long intergerpart = floor(value);
            long fracpart = value - intergerpart;
            return (A * intergerpart + B) + (C * fracpart + D);
        }
};


// Defining class for double type
template <>
class Hashable<std::string>{
    private:
   
        ulong A = Random();
    
    public:
        ulong operator()(const std::string& value) const noexcept{
            ulong hashcrypt = A;
            for(ulong i = 0; i < value.size(); i++){
                hashcrypt = (hashcrypt * 12763) ^ (21179 * (int)value[i]);
            }
            return hashcrypt;
        }
};


// AUXILIARY - Random function
template <typename Data>
ulong Hashable<Data>::Random() noexcept{
    ulong result;
    std::default_random_engine randomGenerator(std::random_device{}());
    std::uniform_int_distribution<uint> randomDist(1, 27457);
    return result = randomDist(randomGenerator);
}

////////////////////////////////////////////////////////////////////////// HashTable

// Defining function HashKey
template <typename Data>
ulong HashTable<Data>::HashKey(const Data& element) const noexcept{
    return (hash(element) % capacity);
}

}
