
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

  using MutableBinaryTree<Data>::size;

  struct NodeLnk : public virtual MutableBinaryTree<Data>::MutableNode{ // Must extend MutableNode

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
    NodeLnk& operator = (const NodeLnk&);
    NodeLnk& operator = (NodeLnk&&) noexcept;

    // NodeLnk Specific functions

    Data& Element() noexcept override;
    const Data& Element() const noexcept override;

    virtual bool IsLeaf() const noexcept override;
    virtual bool HasLeftChild() const noexcept override;
    virtual bool HasRightChild() const noexcept override;

    // NodeLnk Override functions from MutableNode (and Node)
    NodeLnk& LeftChild() override;
    NodeLnk& RightChild() override;

    NodeLnk& LeftChild() const override;
    NodeLnk& RightChild() const override;

  };

protected:

  NodeLnk* root = nullptr;

  // Default constructor
  BinaryTreeLnk() = default;

public:

  // Specific constructor #1: BinaryTreeLnk obtained from a MappableContainer
  BinaryTreeLnk(const MappableContainer<Data>&) noexcept;
  
  // Specific constructor #2: BinaryTreeLnk obtained from a MutableMappableContainer
  BinaryTreeLnk(MutableMappableContainer<Data>&&) noexcept;

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk&);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk&&) noexcept;

  // Destructor
  virtual ~BinaryTreeLnk();

  // Copy assignment
  BinaryTreeLnk<Data>& operator = (const BinaryTreeLnk&);

  // Move assignment
  BinaryTreeLnk<Data>& operator = (BinaryTreeLnk&&) noexcept;

  // Comparison operators 
  bool operator == (const BinaryTreeLnk&) const noexcept;
  bool operator != (const BinaryTreeLnk&) const noexcept;

  /* ************************************************************************ */

  // Override function from BinaryTree
  const NodeLnk& Root() const override;
  
   // Override function from MutableBinaryTree
  NodeLnk& Root() override;

  /* ************************************************************************ */

  // Override function from ClearableContainer
  void Clear() noexcept override;

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
