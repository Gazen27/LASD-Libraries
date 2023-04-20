
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : public virtual Stack<Data>,
                  public virtual List<Data>{
                  // Must extend Stack<Data>,
                  //             List<Data>

private:

  // ...

protected:

  using List<Data>::size;

public:

  // Default constructor
  StackLst() = default;

  /* ************************************************************************ */

  // Specific constructor #1: Stacklst obtained from a MappableContainer
  StackLst(const MappableContainer<Data>&) noexcept;

  // Specific constructor #2: Stacklst obtained from a MutableMappableContainer
  StackLst(MutableMappableContainer<Data>&&) noexcept;


  // Copy constructor
  StackLst(const StackLst&);

  // Move constructor
  StackLst(StackLst&&) noexcept;


  // Destructor
  virtual ~StackLst();

  /* ************************************************************************ */

  // Copy assignment
  StackLst& operator = (const StackLst&) noexcept;

  // Move assignment
  StackLst& operator = (StackLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const StackLst&) const noexcept;
  bool operator != (const StackLst&) const noexcept;

  /* ************************************************************************ */

  // Override functions from Stack

  //Non-Mutable version
  virtual const Data& Top() const;
 
  // Mutable version
  virtual Data& Top();
  
  virtual void Pop();
  virtual Data TopNPop();
  
  virtual void Push(const Data&) noexcept; // Copy of the value
  virtual void Push(Data&&) noexcept; // Move of the value

  /* ************************************************************************ */

  // Override function from ClearableContainer
  using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
