
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

#include "../container/dictionary.hpp"

using std::string;

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  ulong operator()(const Data&) const noexcept = 0;

};

/* ************************************************************************** */

template <typename Data>
class HashTable : public virtual ResizableContainer<Data>,
                  public virtual DictionaryContainer<Data>{
                  // Must extend ResizableContainer,
                  //             DictionaryContainer<Data>

private:

  // ...

protected:

  using DictionaryContainer<Data>::size;

  // ...

public:

  // Destructor
  virtual ~HashTable() = default;

  // Copy assignment
  HashTable& operator = (const HashTable&) = delete;

  // Move assignment
  HashTable& operator = (HashTable&&) noexcept = delete;

  // Comparison operators
  bool operator == (const HashTable&) const noexcept = delete;
  bool operator != (const HashTable&) const noexcept = delete;

protected:

  // Auxiliary member functions

  ulong HashKey(const Data&) noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
