
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

#include "../container/dictionary.hpp"

/* ************************************************************************** */

using std::string;

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable 
{

public:

  ulong operator()(const Data&) noexcept;

};

/* ************************************************************************** */

template <typename Data>
class HashTable : virtual public ResizableContainer,
                  virtual public DictionaryContainer<Data>{

private:

  // ...

protected:

  using DictionaryContainer<Data>::size;
  
  // ...

public:

  // Destructor
  virtual ~HashTable() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTable& operator = (const HashTable&) = delete;

  // Move assignment
  HashTable& operator = (HashTable&&) = delete;

  // Comparison operators
  bool operator == (const HashTable&) const noexcept = delete;
  bool operator != (const HashTable&) const noexcept = delete;


protected:

  // Auxiliary member function
  ulong HashKey(const Data&) const;
  
};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
