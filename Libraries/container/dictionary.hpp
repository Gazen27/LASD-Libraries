
#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

/* ************************************************************************** */

#include "testable.hpp"
#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class DictionaryContainer : public virtual TestableContainer<Data> {
                            // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Default, Copy and Move constructors
  DictionaryContainer() = default;
  DictionaryContainer(const DictionaryContainer&) = default;
  DictionaryContainer(DictionaryContainer&&) = default;

  // Destructor
  virtual ~DictionaryContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  DictionaryContainer& operator = (const DictionaryContainer&) noexcept = delete;

  // Move assignment
  DictionaryContainer& operator = (DictionaryContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const DictionaryContainer&) const noexcept = delete;
  bool operator != (const DictionaryContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Insert(const Data&) noexcept = 0;  // Copy of the value
  virtual bool Insert(Data&&) noexcept = 0;  // Move of the value
  virtual bool Remove(const Data&) noexcept = 0;

  virtual bool InsertAll(const MappableContainer<Data>&) noexcept; // Copy of the value
  virtual bool InsertAll(MutableMappableContainer<Data>&&) noexcept; // Move of the value
  virtual bool RemoveAll(const MappableContainer<Data>&) noexcept;
  
  virtual bool InsertSome(const MappableContainer<Data>&) noexcept; // Copy of the value
  virtual bool InsertSome(MutableMappableContainer<Data>&&) noexcept; // Move of the value
  virtual bool RemoveSome(const MappableContainer<Data>&) noexcept;

};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
