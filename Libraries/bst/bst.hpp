
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : public virtual ClearableContainer,
            public virtual DictionaryContainer<Data>,
            public virtual BinaryTree<Data>,
            public virtual BinaryTreeLnk<Data>{
            // Must extend ClearableContainer,
            //             DictionaryContainer<Data>,
            //             BinaryTree<Data>,
            //             BinaryTreeLnk<Data>

private:

  // ...

protected:

  using BinaryTreeLnk<Data>::size;
  using BinaryTreeLnk<Data>::root;
  using typename BinaryTreeLnk<Data>::NodeLnk;
  
  // ...

public:

  // Default constructor
  BST() = default;

  // Specific constructor #1: BinaryTreeLnk obtained from a MappableContainer
  BST(const MappableContainer<Data>&) noexcept;

  // Specific constructor #2: BinaryTreeLnk obtained from a MutableMappableContainer
  BST(MutableMappableContainer<Data>&&) noexcept;

  // Copy constructor
  BST(const BST& tree) : BinaryTreeLnk<Data>::BinaryTreeLnk(tree){ };

  // Move constructor
  BST(BST&& tree) : BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(tree)){ };

  // Destructor
  virtual ~BST() = default;

  // Copy assignment
  BST& operator = (const BST&);

  // Move assignment
  BST& operator = (BST&&) noexcept;

  // Comparison operators 
  bool operator == (const BST&) const noexcept;
  bool operator != (const BST&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  const Data& Min() const; // (concrete function must throw std::length_error when empty)
  Data MinNRemove(); // (concrete function must throw std::length_error when empty)
  inline void RemoveMin(); // (concrete function must throw std::length_error when empty)

  const Data& Max() const; // (concrete function must throw std::length_error when empty)
  Data MaxNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMax(); // (concrete function must throw std::length_error when empty)

  // type Predecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  // type PredecessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  // type RemovePredecessor(argument) specifiers; // (concrete function must throw std::length_error when not found)

  // type Successor(argument) specifiers; // (concrete function must throw std::length_error when not found)
  // type SuccessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when not found)
  // type RemoveSuccessor(argument) specifiers; // (concrete function must throw std::length_error when not found)

  /* ************************************************************************ */

  // Override functions from DictionaryContainer

  bool Insert(const Data&) noexcept override; // Copy of the value
  bool Insert(Data&&) noexcept override; // Move of the value
  bool Remove(const Data&) noexcept override;

  /* ************************************************************************ */

  // Override function from TestableContainer
  bool Exists(const Data&) const noexcept;

  // Override function from ClearableContainer
  using BinaryTreeLnk<Data>::Clear;

protected:

  // Auxiliary member functions

  // type DataNDelete(argument) specifiers;

  void Detach(NodeLnk*&);

  // type DetachMin(argument) specifiers;
  // type DetachMax(argument) specifiers;

  // type Skip2Left(argument) specifiers;
  // type Skip2Right(argument) specifiers;

  // type FindPointerToMin(argument) specifiers; // Both mutable & unmutable versions
  // type FindPointerToMax(argument) specifiers; // Both mutable & unmutable versions

  // type FindPointerTo(argument) specifiers; // Both mutable & unmutable versions

  // type FindPointerToPredecessor(argument) specifiers; // Both mutable & unmutable versions
  // type FindPointerToSuccessor(argument) specifiers; // Both mutable & unmutable versions

  // Auxiliary functions

  NodeLnk*& Search(const Data&, NodeLnk*&) noexcept;

  void RemoveLeaf(NodeLnk*&);
  void SimpleRemove(NodeLnk*&);
  void FullRemove(NodeLnk*&);

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
