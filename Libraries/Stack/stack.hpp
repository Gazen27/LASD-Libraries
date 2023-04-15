
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Stack : public virtual ClearableContainer{
              // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Default, Copy and Move constructor
  Stack() = default;
  Stack(const Stack&) = default;
  Stack(Stack&&) noexcept = default;

  // Destructor
  virtual ~Stack() = default;

  /* ************************************************************************ */

  // Copy assignment
  Stack& operator = (const Stack&) noexcept = delete;

  // Move assignment
  Stack& operator = (Stack&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const Stack&) const noexcept = delete;
  bool operator != (const Stack&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // Non-Mutable version
  virtual const Data& Top() = 0;
  
  // Mutable version
  virtual Data& Top() = 0; 
  
  virtual void Pop() = 0;
  virtual Data& TopNPop() = 0;
  
  virtual void Push(const Data&) noexcept = 0; // Copy of the value
  virtual void Push(Data&&) noexcept = 0; // Move of the value

};

/* ************************************************************************** */

}

#endif
