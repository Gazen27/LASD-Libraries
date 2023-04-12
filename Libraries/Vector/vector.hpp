
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : public virtual ResizableContainer,
                public virtual SortableLinearContainer<Data>{
                // Must extend ResizableContainer,
                // SortableLinearContainer<Data>

private:

  // ...

protected:

  using Container::size;
  Data* elements = nullptr;

public:

  // Default constructor
  Vector() = default;

  /* ************************************************************************ */

  // Specific constructor #1: Given initial dimention
  Vector(const ulong);

  // Specific constructor #2: Obtained from a MappableContainer
  Vector(const MappableContainer<Data>&) noexcept;
  
  // Specific constructor #3: Obtained from a MutableMappableContainer
  Vector(const MutableMappableContainer<Data>&) noexcept;

  /* ************************************************************************ */

  // Copy constructor
  Vector(const Vector&);

  // Move constructor
  Vector(Vector&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~Vector();

  /* ************************************************************************ */

  // Copy assignment
  Vector& operator = (const Vector&) noexcept;

  // Move assignment
  Vector& operator = (Vector&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const Vector&) const noexcept;
  bool operator != (const Vector&) const noexcept;

  /* ************************************************************************ */

  // Override function from ClearableContainer

  virtual void Clear() noexcept override;

  /* ************************************************************************ */

  // Override function from ResizableContainer

  virtual void Resize(ulong newSize) noexcept override;

  /* ************************************************************************ */

  // Override functions from LinearContainer

  // Non-Mutable version // throws std::out_of_range when out of range
  virtual const Data& operator [] (ulong) const override;

  // Mutable version // throws std::out_of_range when out of range
  virtual Data& operator [] (ulong) override;

  // Non-Mutable version // throws std::length_error when empty
  virtual const Data& Front() const override;

  // Mutable version // throws std::length_error when empty
  virtual Data& Front() override;
  
 // Non-Mutable version // throws std::length_error when empty
  virtual const Data& Back() const override;
  
  // Mutable version // throws std::length_error when empty  
  virtual Data& Back() override;

  /* ************************************************************************ */

  // Override function from SortableLinearContainer

  virtual void Sort(SortableLinearContainer&) noexcept override;
  

protected:

  // Auxiliary functions, if necessary

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
