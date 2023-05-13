
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

  // Specific constructor #1: BST obtained from a MappableContainer
  BST(const MappableContainer<Data>&) noexcept;

  // Specific constructor #2: BST obtained from a MutableMappableContainer
  BST(MutableMappableContainer<Data>&&) noexcept;

  // Copy constructor
  BST(const BST& tree);

  // Move constructor
  BST(BST&& tree);

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

  const Data& Predecessor(const Data&) const; // (concrete function must throw std::length_error when not found)
  Data PredecessorNRemove(const Data&); // (concrete function must throw std::length_error when not found)
  void RemovePredecessor (const Data&); // (concrete function must throw std::length_error when not found)

  const Data& Successor(const Data&) const; // (concrete function must throw std::length_error when not found)
  Data SuccessorNRemove(const Data&); // (concrete function must throw std::length_error when not found)
  void RemoveSuccessor(const Data&); // (concrete function must throw std::length_error when not found)

  /* ************************************************************************ */

  // Override functions from DictionaryContainer

  bool Insert(const Data&) noexcept override; // Copy of the value
  bool Insert(Data&&) noexcept override; // Move of the value
  bool Remove(const Data&) noexcept override;

  /* ************************************************************************ */

  // Override function from TestableContainer
  bool Exists(const Data&) const noexcept override;

  // Override function from ClearableContainer
  using BinaryTreeLnk<Data>::Clear;
  
  using BinaryTree<Data>::Map;
  using BinaryTree<Data>::PreOrderMap;
  using BinaryTree<Data>::InOrderMap;
  using BinaryTree<Data>::PostOrderMap;
  using BinaryTree<Data>::BreadthMap;

protected:

  // Auxiliary member functions

  void Detach(NodeLnk*&);
  NodeLnk*& DetachMin(NodeLnk*&, NodeLnk*&) ;

  NodeLnk* Skip2Left(NodeLnk*&);
  NodeLnk* Skip2Right(NodeLnk*&);

  NodeLnk* const & FindPointerToMin(NodeLnk*const&) const;
  NodeLnk*& FindPointerToMin(NodeLnk*&);

  NodeLnk* const & FindPointerToMax(NodeLnk*const&) const;
  NodeLnk*& FindPointerToMax(NodeLnk*&);

  NodeLnk* const & FindPointerTo(NodeLnk* const&, const Data&) const;
  NodeLnk*& FindPointerTo(NodeLnk*&, const Data&);

  NodeLnk* const & FindPointerToPredecessor( NodeLnk* const&, const Data&) const;
  NodeLnk*& FindPointerToPredecessor(NodeLnk*&, const Data&) ;

  NodeLnk* const & FindPointerToSuccessor( NodeLnk* const &, const Data&) const;
  NodeLnk*& FindPointerToSuccessor(NodeLnk*&, const Data&);

  // type DataNDelete(argument) specifiers;

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
