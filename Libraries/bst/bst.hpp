
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../vector/vector.hpp"

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

public:

  // Default constructor
  BST() = default;

  // Specific constructor #1: BST obtained from a MappableContainer
  BST(const MappableContainer<Data>&) noexcept;

  // Specific constructor #2: BST obtained from a MutableMappableContainer
  BST(MutableMappableContainer<Data>&&) noexcept;

  // Copy constructor
  //BST(const BST<Data>& otherBst) : BinaryTreeLnk<Data>(otherBst){};
  BST(const BST&);

  // Move constructor
  //BST(BST<Data>&& otherBst) noexcept : BinaryTreeLnk<Data>(std::move(otherBst)){};
  BST(BST&&) noexcept;

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

  Data& Min() const; // (concrete function must throw std::length_error when empty)
  Data MinNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMin(); // (concrete function must throw std::length_error when empty)

  Data& Max() const; // (concrete function must throw std::length_error when empty)
  Data MaxNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMax(); // (concrete function must throw std::length_error when empty)

  Data& Predecessor(const Data&) const; // (concrete function must throw std::length_error when not found)
  Data PredecessorNRemove(const Data&); // (concrete function must throw std::length_error when not found)
  void RemovePredecessor(const Data&); // (concrete function must throw std::length_error when not found)

  Data& Successor(const Data&) const; // (concrete function must throw std::length_error when not found)
  Data SuccessorNRemove(const Data&); // (concrete function must throw std::length_error when not found) 
  void RemoveSuccessor(const Data&); // (concrete function must throw std::length_error when not found)

  /* ************************************************************************ */

  // Override functions from DictionaryContainer

  bool Insert(const Data&) override; // Copy of value
  bool Insert(Data&&) override; // Move of value
  bool Remove(const Data&) override;

  /* ************************************************************************ */

  // Override function from TestableContainer
  bool Exists(const Data&) const noexcept override;
  
  // Override function from ClearableContainer
  // function Clear() already overrided in BinaryTreeLnk

protected:

  // Auxiliary member functions

  Data DataNDelete(struct BST::NodeLnk*);

  struct BST::NodeLnk* Detach(struct BST::NodeLnk*&) noexcept;

  struct BST::NodeLnk* DetachMin(struct BST::NodeLnk*&) noexcept;
  struct BST::NodeLnk* DetachMax(struct BST::NodeLnk*&) noexcept;

  struct BST::NodeLnk* Skip2Left(struct BST::NodeLnk*&) noexcept;
  struct BST::NodeLnk* Skip2Right(struct BST::NodeLnk*&) noexcept;

  struct BST::NodeLnk* const& FindPointerToMin(struct BST::NodeLnk* const&) const noexcept;
  struct BST::NodeLnk*& FindPointerToMin(struct BST::NodeLnk*&) noexcept;

  struct BST::NodeLnk* const& FindPointerToMax(struct BST::NodeLnk* const&) const noexcept;
  struct BST::NodeLnk*& FindPointerToMax(struct BST::NodeLnk*&) noexcept;

  struct BST::NodeLnk* const& FindPointerTo(struct BST::NodeLnk* const&, const Data&) const noexcept;
  struct BST::NodeLnk*& FindPointerTo(struct BST::NodeLnk*&, const Data&) noexcept;
  
  struct BST::NodeLnk* const* FindPointerToPredecessor(struct BST::NodeLnk* const&, const Data&) const noexcept;
  struct BST::NodeLnk** FindPointerToPredecessor(struct BST::NodeLnk*&, const Data&) noexcept;

  struct BST::NodeLnk* const* FindPointerToSuccessor(struct BST::NodeLnk* const&, const Data&) const noexcept;
  struct BST::NodeLnk** FindPointerToSuccessor(struct BST::NodeLnk*&, const Data&) noexcept;

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif