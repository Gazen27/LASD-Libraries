
#ifndef QUEUE_HPP
#define QUEUE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Queue : public virtual ClearableContainer{
              // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Default, Copy and Move constructor
  Queue() = default;
  Queue(const Queue&) = default;
  Queue(Queue&&) noexcept = default;

  // Destructor
  virtual ~Queue() = default;

  /* ************************************************************************ */

  // Copy assignment
  Queue& operator = (const Queue&) noexcept = delete;

  // Move assignment
  Queue& operator = (Queue&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const Queue&) const noexcept = delete;
  bool operator != (const Queue&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  // Non-Mutable version
  virtual const Data& Head() const = 0;

  // Mutable version
  virtual Data& Head() = 0;

  virtual void Dequeue() = 0;
  virtual Data& HeadNDequeue() = 0;

  virtual void Enqueue(const Data&) noexcept = 0; // Copy of the value
  virtual void Enqueue(Data&&) noexcept = 0; // Move of the value

};

/* ************************************************************************** */

}

#endif
