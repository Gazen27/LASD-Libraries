
namespace lasd {

////////////////////////////////////////////////////////////// Hashable

// Defining Hashable class for int
template <>
class Hashable<int>{

    public:

        ulong operator()(const int& value) const noexcept{
            return (value * value);
        }
};


// Defining Hashable class for double
template <>
class Hashable<double>{

    public:

        ulong operator()(const double& value) const noexcept{

            long intpart = floor(value);
            long fracpart = pow(2, 24) * (value - intpart);
            return (intpart * fracpart);
        }
};


// Defining Hashable class for string
template <>
class Hashable<string>{

    public:

        ulong operator()(const string& value) const noexcept{

            /////////////////////// TODO
        }
};


////////////////////////////////////////////////////////////// Hashtable

// Defining function HashKey
template <typename Data>
ulong HashTable<Data>::HashKey(const Data&) noexcept{

    ///////////////////////////////////// TODO
}


}
