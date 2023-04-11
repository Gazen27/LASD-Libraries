
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
  Vector(Vector&&);

  /* ************************************************************************ */

  // Destructor
  virtual ~Vector() = default; // ????????????????

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;
  Vector& operator = (const Vector&) noexcept;

  // Move assignment
  // type operator=(argument) specifiers;
  Vector& operator = (Vector&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  bool operator == (const Vector&) const noexcept;
  // type operator!=(argument) specifiers;
  bool operator != (const Vector&) const noexcept;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  // type Clear() specifiers; // Override ClearableContainer member
  virtual void Clear() noexcept override;

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  // type Resize(argument) specifiers; // Override ResizableContainer member


  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type operator[](argument) specifiers; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  // type operator[](argument) specifiers; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  // type Front() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  // type Front() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  // type Back() specifiers; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  // type Back() specifiers; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from SortableLinearContainer)

  // type Sort() specifiers; // Override SortableLinearContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
