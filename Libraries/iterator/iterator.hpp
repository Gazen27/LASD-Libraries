
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Iterator {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~Iterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  Iterator& operator = (const Iterator&) = delete;

  // Move assignment
  Iterator& operator = (Iterator&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const Iterator&) const noexcept = delete;
  bool operator != (const Iterator&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data& operator * () const = 0; // Non-mutable version // Concrete function must throw std::out_of_range when terminated

  virtual bool Terminated() const noexcept = 0;

};

/* ************************************************************************** */

template <typename Data>
class MutableIterator : public virtual Iterator<Data>{
                        // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~MutableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  MutableIterator& operator = (const MutableIterator&) = delete;

  // Move assignment
  MutableIterator& operator = (MutableIterator&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const MutableIterator&) const noexcept = delete;
  bool operator != (const MutableIterator&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual Data& operator * () = 0; // Mutable version // Concrete function must throw std::out_of_range when terminated

};

/* ************************************************************************** */

template <typename Data>
class ForwardIterator : public virtual Iterator<Data>{
                        // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~ForwardIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  ForwardIterator& operator = (const ForwardIterator&) = delete;

  // Move assignment
  ForwardIterator& operator = (ForwardIterator&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const ForwardIterator&) const noexcept = delete;
  bool operator != (const ForwardIterator&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual ForwardIterator& operator ++ () = 0; // (concrete function must throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BackwardIterator : public virtual Iterator<Data>{
                          // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~BackwardIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BackwardIterator& operator = (const BackwardIterator&) = delete;

  // Move assignment
  BackwardIterator& operator = (BackwardIterator&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const BackwardIterator&) const noexcept = delete;
  bool operator != (const BackwardIterator&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual BackwardIterator& operator -- () = 0; // (concrete function must throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BidirectionalIterator : public virtual ForwardIterator<Data>,
                              public virtual BackwardIterator<Data>{
                              // Must extend ForwardIterator<Data>,
                              //             BackwardIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~BidirectionalIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BidirectionalIterator& operator = (const BidirectionalIterator&) = delete;

  // Move assignment
  BidirectionalIterator& operator = (BidirectionalIterator&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const BidirectionalIterator&) const noexcept = delete;
  bool operator != (const BidirectionalIterator&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions
  // THE FOLLOWING FUNCTIONS ARE NOT DECLARED. THIS ITERATOR IS NOT USED IN THE ENTIRE LIBRARY

  // type Terminated() specifiers; // Override Iterator member

  // type ForwardTerminated() specifiers; // (concrete function should not throw exceptions)

  // type BackwardTerminated() specifiers; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class ResettableIterator : public virtual Iterator<Data>{
                            // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~ResettableIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  ResettableIterator& operator = (const ResettableIterator&) = delete;

  // Move assignment
  ResettableIterator& operator = (ResettableIterator&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const ResettableIterator&) const noexcept = delete;
  bool operator != (const ResettableIterator&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual void Reset() noexcept = 0;

};

/* ************************************************************************** */

}

#endif
