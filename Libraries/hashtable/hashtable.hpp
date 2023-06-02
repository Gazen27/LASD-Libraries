
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  ulong operator()(const Data&) const noexcept; // (concrete function should not throw exceptions)

private:

  ulong Random() noexcept;

};

/* ************************************************************************** */

template <typename Data>
class HashTable : public virtual ResizableContiner,
                  public virtual DictionaryContainer<Data>{
                  // Must extend ResizableContainer,
                  //             DictionaryContainer<Data>

private:

  // ...

protected:

  using DictionaryContainer<Data>::size;
  Hashable<Data> hash;
  ulong capacity = 64;

public:

  // Default constructor
  HashTable() = default;

  // Destructor
  virtual ~HashTable() = default;

  // Copy assignment
  HashTable& operator = (const HashTable&) = delete;

  // Move assignment
  HashTable& operator = (HashTable&&) = delete;

  // Comparison operators
  bool operator == (const HashTable&) const noexcept = delete;
  bool operator == (const HashTable&) const noexcept = delete;

protected:

  // Auxiliary member function
  ulong HashKey(const Data&) const noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
