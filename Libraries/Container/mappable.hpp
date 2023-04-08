
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "foldable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MappableContainer : public virtual FoldableContainer<Data>{
                          // Must extend FoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Default, Copy and Move constructors
  MappableContainer() = default;
  MappableContainer(const MappableContainer&) = default;
  MappableContainer(MappableContainer&&) = default;

  // Destructor
  virtual ~MappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MappableContainer& operator = (const MappableContainer&) noexcept = delete;

  // Move assignment
  MappableContainer& operator = (MappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const MappableContainer&) const noexcept = delete;
  bool operator != (const MappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  using MapFunctor = std::function<void(const Data &)>;

  // Specific member function
  virtual void Map(MapFunctor) const = 0;

  /* ************************************************************************ */

  using typename FoldableContainer<Data>::FoldFunctor;
  
  // Override function from FoldableContainer
  // Fold function not declared here but specifically into PreOrder and PostOrder
};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer : public virtual MappableContainer<Data>,
                                  public virtual PreOrderFoldableContainer<Data>{
                                  // Must extend MappableContainer<Data>,
                                  // PreOrderFoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Default, Copy and Move constructors
  PreOrderMappableContainer() = default;
  PreOrderMappableContainer(const PreOrderMappableContainer&) = default;
  PreOrderMappableContainer(PreOrderMappableContainer&&) = default;

  // Destructor
  virtual ~PreOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderMappableContainer& operator = (const PreOrderMappableContainer&) noexcept = delete;

  // Move assignment
  PreOrderMappableContainer& operator = (PreOrderMappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (PreOrderMappableContainer&) const noexcept = delete;
  bool operator != (PreOrderMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFunctor;

  virtual void PreOrderMap(MapFunctor) const = 0;

  /* ************************************************************************ */

  // Override function from MappableContainer
  virtual void Map(MapFunctor) const override;

  /* ************************************************************************ */

  using typename FoldableContainer<Data>::FoldFunctor;

  // Override function from FoldableContainer
  virtual void Fold(FoldFunctor, void *) const override;

  // Override function from PreOrderFoldableContainer
  virtual void PreOrderFold(FoldFunctor, void *) const override;
};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer : public virtual MappableContainer<Data>,
                                    public virtual PostOrderFoldableContainer<Data>{
                                  // Must extend MappableContainer<Data>,
                                  //             PostOrderFoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Default, Copy and Move constructors
  PostOrderMappableContainer() = default;
  PostOrderMappableContainer(const PostOrderMappableContainer&) = default;
  PostOrderMappableContainer(PostOrderMappableContainer&&) = default;

  // Destructor
  virtual ~PostOrderMappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderMappableContainer& operator = (const PostOrderMappableContainer&) noexcept = delete;

  // Move assignment
  PostOrderMappableContainer& operator = (PostOrderMappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const PostOrderMappableContainer&) const noexcept = delete;
  bool operator != (const PostOrderMappableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFunctor;

  virtual void PostOrderMap(MapFunctor) const = 0

  /* ************************************************************************ */

  // Override function from MappableContainer
  virtual void Map(MapFunctor) const override;

  /* ************************************************************************ */

  using typename FoldableContainer<Data>::FoldFunctor;

  // Override function FoldableContainer
  virtual void Fold(FoldFunctor, void *) const override;

  /* ************************************************************************ */

  // Override function from PostOrderFoldableContainer
  virtual void PostOrderFold(FoldFunctor, void *) const override;

};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer {
                                  // Must extend MappableContainer<Data>,
                                  //             InOrderFoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~InOrderMappableContainer() specifiers

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

  // using typename MappableContainer<Data>::MapFunctor;

  // type InOrderMap(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderFoldableContainer)

  // type InOrderFold(arguments) specifiers; // Override InOrderFoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer {
                                  // Must extend MappableContainer<Data>,
                                  //             BreadthFoldableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthMappableContainer() specifiers

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

  // using typename MappableContainer<Data>::MapFunctor;

  // type BreadthMap(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  // type Map(argument) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type Fold(arguments) specifiers; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthFoldableContainer)

  // type BreadthFold(arguments) specifiers; // Override BreadthFoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableMappableContainer {
                                  // Must extend MappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~MutableMappableContainer() specifiers

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

  // using MutableMapFunctor = std::function<void(Data &)>;

  // type Map(argument) specifiers;

};

/* ************************************************************************** */

template <typename Data>
class MutablePreOrderMappableContainer {
                                          // Must extend MutableMappableContainer<Data>,
                                          //             PreOrderMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~MutablePreOrderMappableContainer() specifiers

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

  // using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // type PreOrderMap(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // type Map(argument) specifiers; // Override MutableMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutablePostOrderMappableContainer {
                                          // Must extend MutableMappableContainer<Data>,
                                          //             PostOrderMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~MutablePostOrderMappableContainer() specifiers

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

  // using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // type PostOrderMap(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // type Map(argument) specifiers; // Override MutableMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableInOrderMappableContainer {
                                        // Must extend MutableMappableContainer<Data>,
                                        //             InOrderMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~MutableInOrderMappableContainer() specifiers

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

  // using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // type InOrderMap(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // type Map(argument) specifiers; // Override MutableMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class MutableBreadthMappableContainer {
                                        // Must extend MutableMappableContainer<Data>,
                                        //             BreadthMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~MutableBreadthMappableContainer() specifiers

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

  // using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // type BreadthMap(argument) specifiers;

  /* ************************************************************************ */

  // Specific member function (inherited from MutableMappableContainer)

  // type Map(argument) specifiers; // Override MutableMappableContainer member

};

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif
