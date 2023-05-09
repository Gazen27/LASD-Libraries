
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : public virtual MutableBinaryTree<Data> {
                      // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  using BinaryTree<Data>::size;

  // ...

  struct NodeLnk : public virtual MutableBinaryTree<Data>::MutableNode{ // Must extend MutableNode

  private:

    // ...

  public:

    friend class BinaryTreeLnk<Data>;
	
    NodeLnk* left = nullptr;
    NodeLnk* right = nullptr;
    using MutableBinaryTree<Data>::MutableNode::key;

  public:

    // NodeLnk Destructor
    virtual ~NodeLnk();

    // NodeLnk Specific constructor #1
    NodeLnk(const Data&, NodeLnk*, NodeLnk*);
    
    // NodeLnk Specific constructor #2
    NodeLnk(const Data&);

    // NodeLnk Specific constructor #3
    NodeLnk(Data&&) noexcept;

    // NodeLnk Copy and Move constructor
    NodeLnk(const NodeLnk&);
    NodeLnk(NodeLnk&&) noexcept;

    // NodeLnk Copy and Move Assignment
    NodeLnk& operator = (const NodeLnk&) = delete;
    NodeLnk& operator = (NodeLnk&&) noexcept = delete;

    // NodeLnk Specific functions
    virtual bool IsLeaf() const noexcept;
    virtual bool HasLeftChild() const noexcept;
    virtual bool HasRightChild() const noexcept;

    // NodeLnk Override functions from MutableNode (and Node)
    NodeLnk& LeftChild() override;
    NodeLnk& RightChild() override;

    NodeLnk& LeftChild() const override;
    NodeLnk& RightChild() const override;

  };

protected:

  NodeLnk* root = nullptr;


public:

  // Default constructor
  BinaryTreeLnk() = default;

  // Specific constructor #1: BinaryTreeLnk obtained from a MappableContainer
  BinaryTreeLnk(const MappableContainer<Data>&) noexcept;
  
  // Specific constructor #2: BinaryTreeLnk obtained from a MutableMappableContainer
  BinaryTreeLnk(MutableMappableContainer<Data>&&) noexcept;

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk<Data>&);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk<Data>&&) noexcept;

  // Destructor
  virtual ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk<Data>& operator = (const BinaryTreeLnk<Data>&);

  // Move assignment
  BinaryTreeLnk<Data>& operator = (BinaryTreeLnk<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators 
  bool operator == (const BinaryTreeLnk<Data>&) const noexcept;
  bool operator != (const BinaryTreeLnk<Data>&) const noexcept;

  /* ************************************************************************ */

  // Override function from BinaryTree
  NodeLnk& Root() const override;
  
   // Override function from MutableBinaryTree
  NodeLnk& Root() override;

  /* ************************************************************************ */

  // Override function from ClearableContainer
  void Clear() override;

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
