
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

  virtual void Insert(const Data&) = 0;  // Copy of the value
  virtual void Insert(Data&&) = 0;  // Move of the value
  
  virtual void Remove(const Data&) = 0;


  virtual bool InsertAll(const MappableContainer&) noexcept; // Copy of the value
  virtual bool InsertAll(MutableMappableContainer&&) noexcept; // Move of the value
 
  virtual bool RemoveAll(const MappableContainer&) noexcept;
  
  // type InsertSome(argument) specifiers; // Copy of the value; From MappableContainer; True if some is inserted
  // type InsertSome(argument) specifiers; // Move of the value; From MutableMappableContainer; True if some is inserted
  // type RemoveSome(argument) specifiers; // From MappableContainer; True if some is removed

};

/* ************************************************************************** */

}

#include "dictionary.cpp"

#endif
