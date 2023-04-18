
#ifndef FOLDABLE_HPP
#define FOLDABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class FoldableContainer : public virtual TestableContainer<Data> {
                          // Must extend TestableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Default, Copy and Move constructors
  FoldableContainer() = default;
  FoldableContainer(const FoldableContainer&) = default;
  FoldableContainer(FoldableContainer&&) = default;

  // Destructor
  virtual ~FoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  FoldableContainer& operator = (const FoldableContainer&) noexcept = delete;

  // Move assignment
  FoldableContainer& operator = (FoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const FoldableContainer&) const noexcept = delete;
  bool operator != (const FoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Declaring the functor
  using FoldFunctor = std::function<void(const Data&, void *)>;

  // type Fold(arguments) specifiers;
  virtual void Fold(FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Override function from TestableContainer
  virtual bool Exists(const Data& element) const noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderFoldableContainer : public virtual FoldableContainer<Data>{
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Default, Copy and Move constructors
  PreOrderFoldableContainer() = default;
  PreOrderFoldableContainer(const PreOrderFoldableContainer&) = default;
  PreOrderFoldableContainer(PreOrderFoldableContainer&&) = default;

  // Destructor
  virtual ~PreOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderFoldableContainer& operator = (const PreOrderFoldableContainer&) noexcept = delete;

  // Move assignment
  PreOrderFoldableContainer& operator = (PreOrderFoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const PreOrderFoldableContainer&) const noexcept = delete;
  bool operator != (const PreOrderFoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  using typename FoldableContainer<Data>::FoldFunctor;

  // Specific member function
  virtual void PreOrderFold(FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Override function from FoldableContainer
  virtual void Fold(FoldFunctor, void *) const override;

/* ************************************************************************** */

};

template <typename Data>
class PostOrderFoldableContainer : public virtual FoldableContainer<Data>{
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Default, Copy and Move constructors
  PostOrderFoldableContainer() = default;
  PostOrderFoldableContainer(const PostOrderFoldableContainer&) = default;
  PostOrderFoldableContainer(PostOrderFoldableContainer&&) = default;

  // Destructor
  virtual ~PostOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderFoldableContainer& operator = (const PostOrderFoldableContainer&) noexcept = delete;

  // Move assignment
  PostOrderFoldableContainer& operator = (PostOrderFoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const PostOrderFoldableContainer&) const noexcept = delete;
  bool operator != (const PostOrderFoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  using typename FoldableContainer<Data>::FoldFunctor;

  // Specific member function
  virtual void PostOrderFold(FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Override function from FoldableContainer
  virtual void Fold(FoldFunctor, void *) const override;

};

/* ************************************************************************** */

template <typename Data>
class InOrderFoldableContainer {
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~InOrderFoldableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type InOrderFold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // type Fold(arguments) specifiers; // Override FoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class BreadthFoldableContainer {
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthFoldableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type BreadthFold(arguments) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // type Fold(arguments) specifiers; // Override FoldableContainer member

};

/* ************************************************************************** */

}

#include "foldable.cpp"

#endif
