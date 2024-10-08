
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : public virtual MutableBinaryTree<Data>{
                      // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

  using MutableBinaryTree<Data>::size;

  struct NodeVec : public virtual MutableBinaryTree<Data>::MutableNode{ // Must extend MutableNode

  private:

    // ...

  protected:

    ulong index;
    ulong left;
    ulong right;
    using MutableBinaryTree<Data>::MutableNode::key;

    BinaryTreeVec<Data> *treePointer = nullptr;

  public:

    friend class BinaryTreeVec<Data>;

    // NodeVec Default constructor
    NodeVec() = default;

    // NodeVec Destructor
    virtual ~NodeVec() = default;

    // NodeVec Specific constructors
    NodeVec(const Data&);
    NodeVec(Data&&);

    // NodeVec Copy assignment
    NodeVec& operator = (const NodeVec&) noexcept;

    // NodeVec Move assignment
    //NodeVec& operator = (NodeVec&&) noexcept = default;

    // NodeVec Override functions
    Data& Element() noexcept override;
    const Data& Element() const noexcept override;

    bool IsLeaf() const noexcept override;
    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;

    // Left and Right child (Mutable)  
    NodeVec& LeftChild() override;
    NodeVec& RightChild() override;

    // Left and Right child (Non-Mutable)  
    const NodeVec& LeftChild() const override;
    const NodeVec& RightChild() const override;

  };

  NodeVec* nodeArray;

public:

  // Default constructor
  BinaryTreeVec() = delete;

  // Specific constructor #1: BinaryTreeVec obtained from a MappableContainer
  BinaryTreeVec(const MappableContainer<Data>&) noexcept;
  
  // Specific constructor #2: BinaryTreeVec obtained from a MutableMappableContainer
  BinaryTreeVec(MutableMappableContainer<Data>&&) noexcept;

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec&);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec&&) noexcept;

  // Destructor
  virtual ~BinaryTreeVec();

  // Copy assignment
  BinaryTreeVec& operator = (const BinaryTreeVec&);

  // Move assignment
  BinaryTreeVec& operator = (BinaryTreeVec&&) noexcept;

  // Comparison operators
  bool operator == (const BinaryTreeVec&) const noexcept;
  bool operator != (const BinaryTreeVec&) const noexcept;

  /* ************************************************************************ */

  // Override function from BinaryTree
  const NodeVec& Root() const override;

  // Override function from MutableBinaryTree
  NodeVec& Root() override;

  // Override function from ClearableContainer
  void Clear() noexcept override;

  /* ************************************************************************ */

  using typename FoldableContainer<Data>::FoldFunctor;
  using typename MappableContainer<Data>::MapFunctor;
  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // Override member function from BreadthFoldableContainer
  void BreadthFold(FoldFunctor, void*) const override;

  // Override function from BreadthMappableContainer
  void BreadthMap(MapFunctor) const override;

  // Override function from MutableBreadthMappableContainer
  void BreadthMap(MutableMapFunctor) override;

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
