
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec : public virtual Queue<Data>,
                  public virtual Vector<Data>{
                  // Must extend Queue<Data>,
                  //             Vector<Data>

private:

  // ...

protected:

  using Vector<Data>::size;
  using Vector<Data>::elements;
  ulong head = 0;
  ulong rear = 0;

public:

  // Default constructor
  QueueVec();

  /* ************************************************************************ */

  // Specific constructor #1: QueueVec obtained from a MappableContainer
  QueueVec(const MappableContainer<Data>&) noexcept;

  // Specific constructor #: QueueVec obtained from a MutableMappableContainer
  QueueVec(MutableMappableContainer<Data>&&) noexcept;

  /* ************************************************************************ */

  // Copy constructor
  QueueVec(const QueueVec&);

  // Move constructor
  QueueVec(QueueVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueVec();

  /* ************************************************************************ */

  // Copy assignment
  QueueVec& operator = (const QueueVec&) noexcept;

  // Move assignment
  QueueVec& operator = (QueueVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const QueueVec&) const noexcept;
  bool operator != (const QueueVec&) const noexcept;

  /* ************************************************************************ */

  // Override functions from Queue
  
  // Non-Mutable version
  const Data& Head() const;

  // Mutable version
  Data& Head();

  void Dequeue(); // must throw std::length_error when empty
  Data HeadNDequeue(); // must throw std::length_error when empty

  void Enqueue(const Data&) noexcept; // Copy of the value
  void Enqueue(Data&&) noexcept; // Move of the value

  /* ************************************************************************ */

  // Override functions from Container

  virtual bool Empty() const noexcept override;

  virtual ulong Size() const noexcept override;

  /* ************************************************************************ */

  virtual bool Full() const noexcept;

  virtual ulong AllocatedSize() const noexcept;

  /* ************************************************************************ */

  // Override function from ClearableContainer

  virtual void Clear() noexcept override;

protected:

  // Auxiliary member functions

  virtual void Expand();
  virtual void Reduce();

  virtual ulong NextRear();
  
  // virtual void SwapVectors(const ulong);

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
