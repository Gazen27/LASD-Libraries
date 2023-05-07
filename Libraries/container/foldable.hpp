
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
class InOrderFoldableContainer : public virtual FoldableContainer<Data>{
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~InOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  InOrderFoldableContainer& operator = (const InOrderFoldableContainer&) = delete;

  // Move assignment
  InOrderFoldableContainer& operator = (InOrderFoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const InOrderFoldableContainer&) const noexcept = delete;
  bool operator != (const InOrderFoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  using typename FoldableContainer<Data>::FoldFunctor;

  // Specific member function
  virtual void InOrderFold(FoldFunctor, void*) const = 0;

  /* ************************************************************************ */

  // Override function from FoldableContainer
  virtual void Fold(FoldFunctor, void *) const override;

};

/* ************************************************************************** */

template <typename Data>
class BreadthFoldableContainer : public virtual FoldableContainer<Data>{
                                  // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~BreadthFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  BreadthFoldableContainer& operator = (const BreadthFoldableContainer&) = delete;

  // Move assignment
  BreadthFoldableContainer& operator = (BreadthFoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const BreadthFoldableContainer&) const noexcept = delete;
  bool operator != (const BreadthFoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  using typename FoldableContainer<Data>::FoldFunctor;

  // Specific member function
  virtual void BreadthFold(FoldFunctor, void*) const = 0;

  /* ************************************************************************ */

  // Override function from FoldableContainer
  virtual void Fold(FoldFunctor, void*) const override;

};

/* ************************************************************************** */

}

#include "foldable.cpp"

#endif
