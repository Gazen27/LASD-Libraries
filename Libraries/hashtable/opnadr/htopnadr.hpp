
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableOpnAdr : public virtual HashTable<Data>{
                        // Must extend HashTable<Data>

private:

  // ...

protected:

  using HashTable<Data>::size;
  using HashTable<Data>::capacity;
  using HashTable<Data>::HashKey;
  using HashTable<Data>::GreaterPower;
  using HashTable<Data>::hash;

  ulong skulled = 0;

  Vector<Data> table;
  Vector<int> flags; // 0 - free slot // 1 - occuped slot // 2 - removed value
                       // enumerations would be fine the same way (probably better)

public:

  // Default constructor
  HashTableOpnAdr();

  // Specific constructor #1: HashTable of a given size
  HashTableOpnAdr(ulong) noexcept;

  // Specific constructor #2 and #3: HashTable obtained from a MappableContainer
  HashTableOpnAdr(const MappableContainer<Data>&) noexcept;
  HashTableOpnAdr(ulong, const MappableContainer<Data>&) noexcept;

  // Specific constructor #4 and #5: HashTable obtained from a MutableMappableContainer
  HashTableOpnAdr(MutableMappableContainer<Data>&&) noexcept;
  HashTableOpnAdr(ulong, MutableMappableContainer<Data>&&) noexcept;

  // Copy constructor
  HashTableOpnAdr(const HashTableOpnAdr<Data>&) noexcept;

  // Move constructor
  HashTableOpnAdr(HashTableOpnAdr<Data>&&) noexcept;

  // Destructor
  virtual ~HashTableOpnAdr() = default;

  // Copy assignment
  HashTableOpnAdr& operator = (const HashTableOpnAdr&) noexcept;

  // Move assignment
  HashTableOpnAdr& operator = (HashTableOpnAdr&&) noexcept;

  // Comparison operators
  bool operator == (const HashTableOpnAdr&) const noexcept;
  bool operator != (const HashTableOpnAdr&) const noexcept;

  /* ************************************************************************ */

  // Override functions from DictionaryContainer
  bool Insert(const Data&) noexcept override; // Copy of value
  bool Insert(Data&&) noexcept override; // Move of value
  bool Remove(const Data&) noexcept override;

  /* ************************************************************************ */

  // Override function from TestableContainer
  bool Exists(const Data&) const noexcept override;

  // Override function from ResizableContainer
  void Resize(ulong) noexcept override;

  // Override function from ClearableContainer
  void Clear() noexcept override;

public:

  // Auxiliary member functions

  // type HashKey(argument) specifiers;
  // type Find(argument) specifiers;
  // type FindEmpty(argument) specifiers;
  // type Remove(argument) specifiers;

  // Initializing vectors
  void DefaultVector(Vector<int>&);
  void DefaultVector(Vector<double>&);
  void DefaultVector(Vector<std::string>&);

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
