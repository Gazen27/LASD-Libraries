
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : public virtual Queue<Data>,
                  public virtual List<Data>{
                  // Must extend Queue<Data>,
                  //             List<Data>

private:

  // ...

protected:

  using List<Data>::size;

  // ...

public:

  // Default constructor
  QueueLst() = default;

  /* ************************************************************************ */

  // Specific constructor #1: QueueLst obtained from a MappableContainer
  QueueLst(const MappableContainer<Data>&) noexcept;

  // Specific constructor #2: QueueLst obtained from a MutableMappableContainer
  QueueLst(MutableMappableContainer<Data>&&) noexcept;

  /* ************************************************************************ */

  // Copy constructor
  QueueLst(const QueueLst&);

  // Move constructor
  QueueLst(QueueLst&&) noexcept;


  // Destructor
  virtual ~QueueLst();

  /* ************************************************************************ */

  // Copy assignment
  QueueLst& operator = (const QueueLst&) noexcept;

  // Move assignment
  QueueLst& operator = (QueueLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const QueueLst&) const noexcept;
  bool operator != (const QueueLst&) const noexcept;

  /* ************************************************************************ */

  // Override functions from Queue

  // Non-Mutable version
  const Data& Head() const;

  // Mutable version
  Data& Head();

  void Dequeue();
  Data HeadNDequeue();

  void Enqueue(const Data&) noexcept; // Copy of the value
  void Enqueue(Data&&) noexcept; // Move of the value
  
  /* ************************************************************************ */

  // Override function from ClearableContainer

  using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
