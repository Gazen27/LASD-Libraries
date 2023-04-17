
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec : public virtual Stack<Data>,
                  public virtual Vector<Data>{
                  // Must extend Stack<Data>,
                  //             Vector<Data>

private:

  // ...

protected:

  using Vector<Data>::size;
  using Vector<Data>::elements;

  ulong level = 0;

public:

  // Default constructor
  StackVec() = default;

  /* ************************************************************************ */

  // Specific constructor #1: StackVec obtained from a MappableContainer
  StackVec(const MappableContainer<Data>&) noexcept;

  // Specific constructor #2: StackVec obtained from a MutableMappableContainer
  StackVec(MutableMappableContainer<Data>&&) noexcept;

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec&);

  // Move constructor
  StackVec(StackVec&&) noexcept;


  // Destructor
  virtual ~StackVec();

  /* ************************************************************************ */

  // Copy assignment
  StackVec& operator = (const StackVec&) noexcept;

  // Move assignment
  StackVec& operator = (StackVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const StackVec&) const noexcept;
  bool operator != (const StackVec&) const noexcept;

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

  // Override functions from Container

  virtual bool Empty() const noexcept override;

  virtual ulong Size() const noexcept override;

  /* ************************************************************************ */

  // Override function from ClearableContainer

  virtual void Clear() noexcept override;

protected:

  // Auxiliary member functions

  virtual void Expand();
  virtual void Reduce(); 
};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
