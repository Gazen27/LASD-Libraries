
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

typedef unsigned long ulong;

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer : public virtual MutablePreOrderMappableContainer<Data>,
                        public virtual MutablePostOrderMappableContainer<Data>{
                        // Must extend MutablePreOrderMappableContainer<Data>,
                        //             MutablePostOrderMappableContainer<Data>

private:

  // ...

protected:

  using Container::size;

public:

  // Default, Copy and Move constructors
  LinearContainer() = default;
  LinearContainer(const LinearContainer&) = default;
  LinearContainer(LinearContainer&&) = default;

  // Destructor
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  LinearContainer& operator = (const LinearContainer&) noexcept = delete;

  // Move assignment
  LinearContainer& operator = (LinearContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const LinearContainer&) const noexcept;
  bool operator != (const LinearContainer&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // Non-mutable version // Concrete function must throw std::out_of_range when out of range
  virtual const Data& operator [] (ulong) const = 0;

  // Mutable version // Concrete function must throw std::out_of_range when out of range
  virtual Data& operator [] (ulong) = 0;

  // Non-mutable version
  virtual const Data& Front() const;

  // Mutable version
  virtual Data& Front();

  // Non-mutable version
  virtual const Data& Back() const;
  
  // Mutable version
  virtual Data& Back();

  /* ************************************************************************ */

  using typename MappableContainer<Data>::MapFunctor;

  // Override function from PreOrderMappableContainer
  virtual void PreOrderMap(MapFunctor) const override;


  // Override function from PostOrderMappableContainer
  virtual void PostOrderMap(MapFunctor) const override;

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // Override function from MutablePreOrderMappableContainer
  virtual void PreOrderMap(MutableMapFunctor) override;


  // Override function from MutablePostOrderMappableContainer
  virtual void PostOrderMap(MutableMapFunctor) override;


  // Override function from Testable
  virtual bool Exists(const Data&) const noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer : public virtual LinearContainer<Data>{
                                // Must extend LinearContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Default, Copy and Move constructors
  SortableLinearContainer() = default;
  SortableLinearContainer(const SortableLinearContainer&) = default;
  SortableLinearContainer(SortableLinearContainer&&) = default;

  // Destructor
  virtual ~SortableLinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  SortableLinearContainer& operator = (const SortableLinearContainer&) noexcept = delete;

  // Move assignment
  SortableLinearContainer& operator = (SortableLinearContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const SortableLinearContainer&) const noexcept;
  bool operator != (const SortableLinearContainer&) const noexcept;

  /* ************************************************************************ */

  // Specific member function
  virtual void Sort(SortableLinearContainer&) noexcept;

};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
