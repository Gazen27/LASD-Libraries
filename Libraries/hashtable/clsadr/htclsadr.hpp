
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

#include "../hashtable.hpp"
#include "../../list/list.hpp"
#include "../../vector/vector.hpp"


namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr : virtual public HashTable<Data>{
                        // Must extend HashTable<Data>

private:

  // ...

protected:

  Vector<List<Data>> vec;

public:

  using HashTable<Data>::size;
  using HashTable<Data>::HashKey;

  // Default constructor
  HashTableClsAdr();

  // Specific constructor #1: HashTable of a given size
  HashTableClsAdr(const ulong);

  // Specific constructor #2: HashTable obtained from a MappableContainer
  HashTableClsAdr(const MappableContainer<Data>&);
  
  // Specific constructor #3: HashTable of a given size obtained from a MappableContainer
  HashTableClsAdr(const ulong, const MappableContainer<Data>&);
  
  // Specific constructor #4: HashTable obtained from a MutableMappableContainer
  HashTableClsAdr(MutableMappableContainer<Data>&&);
  
  // Specific constructor #5: HashTable of a given size obtained from a MutableMappableContainer
  HashTableClsAdr(const ulong, MutableMappableContainer<Data>&&);

  // Copy constructor
  HashTableClsAdr(const HashTableClsAdr<Data>&);

  // Move constructor
  HashTableClsAdr(HashTableClsAdr<Data>&&);

  // Destructor
  virtual ~HashTableClsAdr() = default;

  // Copy assignment
  HashTableClsAdr<Data>& operator = (const HashTableClsAdr<Data>&);

  // Move assignment
  HashTableClsAdr<Data>& operator = (HashTableClsAdr<Data>&&) noexcept;

  // Comparison operators
  bool operator == (const HashTableClsAdr<Data>&) const noexcept;
  bool operator != (const HashTableClsAdr<Data>&) const noexcept;

 
  /* ************************************************************************ */

  // Override functions from DictionaryContainer

  bool Insert(const Data&) noexcept override; // Copy of the value
  bool Insert(Data&&) noexcept override; // Move of the value
  bool Remove(const Data&) noexcept override;

  /* ************************************************************************ */

  // Override function from TestableContainer
  bool Exists(const Data&) const noexcept override;

  // Override function from ResizableContainer
  void Resize(const ulong) noexcept override;

  // Override function from ClearableContainer
  void Clear() noexcept override;

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
