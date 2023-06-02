
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr : public virtual HashTable<Data>{
                        // Must extend HashTable<Data>

private:

  // ...

protected:

  using HashTable<Data>::size;
  using HashTable<Data>::capacity;
  using HashTable<Data>::HashKey;

  Vector<List<Data>> table;

public:

  // Default constructor
  HashTableClsAdr();

  // Specific constructor #1: HashTable of a given size
  HashTableClsAdr(ulong) noexcept;

  // Specific constructor #2 and #3: HashTable obtained from MappableContainer
  HashTableClsAdr(const MappableContainer<Data>&) noexcept;
  HashTableClsAdr(ulong, const MappableContainer<Data>&) noexcept;
  
  // Specific constructor #4 and #5: HashTable obtained from MutableMappableContainer
  HashTableClsAdr(MutableMappableContainer<Data>&&) noexcept;
  HashTableClsAdr(ulong, MutableMappableContainer<Data>&&) noexcept;

  // Copy constructor
  HashTableClsAdr(const HashTableClsAdr&) noexcept;
    
  // Move constructor
  HashTableClsAdr(HashTableClsAdr&&) noexcept;
    
  // Destructor
  virtual ~HashTableClsAdr() = default;

  // Copy assignment  
  HashTableClsAdr& operator = (const HashTableClsAdr&) noexcept;
    
  // Move assignment
  HashTableClsAdr& operator = (HashTableClsAdr&&) noexcept;

  // Comparison operators
  bool operator == (const HashTableClsAdr&) const noexcept;
  bool operator != (const HashTableClsAdr&) const noexcept;

  /* ************************************************************************ */

  // Override functions from DictionaryContainer
  bool Insert(const Data&) noexcept override; // Copy of value
  bool Insert(Data&&) noexcept override; // Move of value
  bool Remove(const Data&) noexcept override;
    
  // Override function from TestableContainer
  bool Exists(const Data&) const noexcept override;

  // Override function from ResizableContainer
  void Resize(ulong) noexcept override;

  // Override function from ClearableContainer
  void Clear() noexcept override;

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
