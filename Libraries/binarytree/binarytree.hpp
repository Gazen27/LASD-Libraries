
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

#include "../stack/vec/stackvec.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : public virtual PreOrderMappableContainer<Data>,
                    public virtual PostOrderMappableContainer<Data>,
                    public virtual InOrderMappableContainer<Data>,
                    public virtual BreadthMappableContainer<Data> {
                    // Must extend PreOrderMappableContainer<Data>,
                    //             PostOrderMappableContainer<Data>,
                    //             InOrderMappableContainer<Data>,
                    //             BreadthMappableContainer<Data>

private:

  // ...

protected:

  using Container::size;

public:

  struct Node {

  protected:

    // Comparison operators
    bool operator==(const Node&) const noexcept ;
    bool operator!=(const Node&) const noexcept ;

  public:

    friend class BinaryTree<Data>;

    // Destructor
    virtual ~Node() = default;

    // Copy assignment
    Node& operator = (Node&) = delete;

    // Move assignment
    Node& operator = (Node&&) = delete;

    /* ********************************************************************** */

    // Specific member functions

    virtual const Data& Element() const  = 0;

    virtual bool IsLeaf() const noexcept ;
    virtual bool HasLeftChild() const noexcept = 0 ;
    virtual bool HasRightChild() const noexcept = 0;

    virtual const Node& LeftChild() const = 0 ; // (concrete function must throw std::out_of_range when not existent)
    virtual const Node& RightChild() const  = 0; // (concrete function must throw std::out_of_range when not existent)

  };

  // Destructor
  virtual ~BinaryTree() = default;

  // Copy assignment
  BinaryTree& operator = (const BinaryTree&) const = delete;

  // Move assignment
  BinaryTree& operator=(BinaryTree&&) = delete;

  // Comparison operators
  bool operator==(const BinaryTree& ) const noexcept ;
  bool operator!=(const BinaryTree&) const noexcept ;

  /* ************************************************************************ */

  // Specific member function
  virtual const Node& Root() const  = 0; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  using typename FoldableContainer<Data>::FoldFunctor;

  // Override function from FoldableContainer
  virtual void Fold(FoldFunctor , void*) const override ;

  /* ************************************************************************ */

  using typename MappableContainer<Data>::MapFunctor;

  // Override function from MappableContainer
  virtual void Map(MapFunctor) const override;

  // Override function from PreOrderMappableContainer
  virtual void PreOrderMap(MapFunctor) const override;

  // Override function from PostOrderMappableContainer
  virtual void PostOrderMap(MapFunctor) const override;

  // Override function from InOrderMappableContainer
  virtual void InOrderMap(MapFunctor) const override;

  // Override function from BreadthMappableContainer
  virtual void BreadthMap(MapFunctor) const override;

protected:

  // Auxiliary member functions

  void PreOrderMap(MapFunctor, const Node& ) const;

  void PostOrderMap(MapFunctor , const Node& ) const ;

  void InOrderMap(MapFunctor , const  Node& ) const ;

  void BreadthMap(MapFunctor , const Node& ) const ;

  //Auxiliary function to compare two binary tree
  bool AuxEqualsBinaryTree (const Node* , const Node*) const noexcept;
};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree : public virtual ClearableContainer,
                          public virtual BinaryTree<Data>,
                          public virtual MutablePreOrderMappableContainer<Data>,
                          public virtual MutablePostOrderMappableContainer<Data>,
                          public virtual MutableInOrderMappableContainer<Data>,
                          public virtual MutableBreadthMappableContainer<Data> {
                          // Must extend ClearableContainer,
                          //             BinaryTree<Data>,
                          //             MutablePreOrderMappableContainer<Data>,
                          //             MutablePostOrderMappableContainer<Data>,
                          //             MutableInOrderMappableContainer<Data>,
                          //             MutableBreadthMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  struct MutableNode : BinaryTree<Data>::Node {
                        // Must extend Node

    public:

    friend class MutableBinaryTree<Data>;

    // Destructor
    virtual ~MutableNode() = default;

    // Copy assignment
    MutableNode& operator = (const MutableNode&) = delete;

    // Move assignment
    MutableNode& operator = (MutableNode&&) = delete;

    /* ********************************************************************** */

    // Specific member functions

    virtual Data& Element() noexcept = 0;
    virtual MutableNode& LeftChild() = 0 ; // (concrete function must throw std::out_of_range when not existent)
    virtual MutableNode& RightChild() = 0 ; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */

  // Destructor
  ~MutableBinaryTree() = default;

  // Copy assignment
  MutableBinaryTree& operator = (const MutableBinaryTree&) const = delete;

  // Move assignment
  MutableBinaryTree& operator = ( MutableBinaryTree&&) const = delete;

  /* ************************************************************************ */

  // Specific member function
  virtual MutableNode& Root() = 0;

  /* ************************************************************************ */

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  // Override function from MutableMappableContainer
  void Map(MutableMapFunctor) override ;

  // Override function from MutablePreOrderMappableContainer
  virtual void PreOrderMap(MutableMapFunctor) override;

  // Override function from MutablePostOrderMappableContainer
  virtual void PostOrderMap(MutableMapFunctor) override;

  // Override function from MutableInOrderMappableContainer
  virtual void InOrderMap(MutableMapFunctor) override;

  // Override function from MutableBreadthMappableContainer
  virtual void BreadthMap(MutableMapFunctor) override;

protected:

  // Auxiliary member functions

  void PreOrderMap(MutableMapFunctor, MutableNode&);

  void PostOrderMap(MutableMapFunctor, MutableNode&);

  void InOrderMap(MutableMapFunctor, MutableNode&);

  void BreadthMap(MutableMapFunctor, MutableNode&);

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : public virtual ForwardIterator<Data>,
                            public virtual ResettableIterator<Data>{
                           // Must extend ForwardIterator<Data>,
                           //             ResettableIterator<Data>

private:

  const typename BinaryTree<Data>::Node * current =nullptr;
  const typename BinaryTree<Data>::Node * root = nullptr;
  StackLst<const typename BinaryTree<Data>::Node *> elements ;

protected:

  // ...

public:
  
  // Specific constructor: Iterator over a given binary tree
  BTPreOrderIterator(const BinaryTree<Data>&) ;

  // Copy constructor
  BTPreOrderIterator(const BTPreOrderIterator&) ;

  // Move constructor
  BTPreOrderIterator(BTPreOrderIterator&&) ;

  // Destructor
  virtual ~BTPreOrderIterator();

  // Copy assignment
  BTPreOrderIterator& operator = (const BTPreOrderIterator&) ;

  // Move assignment
  BTPreOrderIterator& operator = (BTPreOrderIterator&&) ;

  // Comparison operators
  bool operator == (const BTPreOrderIterator&) const noexcept ;
  bool operator != (const BTPreOrderIterator&) const noexcept ;

  /* ************************************************************************ */

  // Specific member functions inherited from Iterator

  const Data& operator*() const;

  bool Terminated() const noexcept override ;

  /* ************************************************************************ */

  // Specific member function (inherited from ForwardIterator)
  BTPreOrderIterator<Data>& operator++() ;

  // Specific member function (inherited from ResettableIterator)
  void Reset() noexcept ;

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator : public virtual BTPreOrderIterator<Data>,
                                  public virtual MutableIterator<Data>{
                                  // Must extend MutableIterator<Data>,
                                  //             BTPreOrderIterator<Data>

private:

  typename MutableBinaryTree<Data>::MutableNode * current = nullptr;
  typename MutableBinaryTree<Data>::MutableNode * root = nullptr;
  StackLst <typename MutableBinaryTree<Data>::MutableNode *> elements ;

protected:

  // ...

public:
 
  // Specific constructor: Iterator over a given mutable binary tree
  BTPreOrderMutableIterator(MutableBinaryTree<Data>&) ;

  // Copy constructor
  BTPreOrderMutableIterator(const BTPreOrderMutableIterator&);

  // Move constructor
  BTPreOrderMutableIterator(BTPreOrderMutableIterator&&);

  // Destructor
  virtual ~BTPreOrderMutableIterator();

  // Copy assignment
  BTPreOrderMutableIterator& operator = (const BTPreOrderMutableIterator&);

  // Move assignment
  BTPreOrderMutableIterator& operator = (BTPreOrderMutableIterator&&);

  // Comparison operators
  bool operator==(const BTPreOrderMutableIterator&) const noexcept;
  bool operator!=(const BTPreOrderMutableIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  const Data& operator*() const {return BTPreOrderIterator<Data>::operator*();}

  bool Terminated() const noexcept {return BTPreOrderIterator<Data>::Terminated();} 

  Data& operator*();

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : public virtual ForwardIterator<Data>,
                            public virtual ResettableIterator<Data>{
                            // Must extend ForwardIterator<Data>,
                            //             ResettableIterator<Data>

private:

  const typename BinaryTree<Data>::Node* current = nullptr ;
  const typename BinaryTree<Data>::Node* root = nullptr ;
  StackLst<const typename BinaryTree<Data>::Node*> elements ;

protected:

  // ...

public:
 
  // Specific constructor: Iterator over a given binary tree
  BTPostOrderIterator(const BinaryTree<Data>&);

  // Copy constructor
  BTPostOrderIterator(const BTPostOrderIterator&);

  // Move constructor
  BTPostOrderIterator(BTPostOrderIterator&&);

  // Destructor
  virtual ~BTPostOrderIterator();

  // Copy assignment
  BTPostOrderIterator& operator=(const BTPostOrderIterator&);

  // Move assignment
  BTPostOrderIterator& operator=(BTPostOrderIterator&&) ;

  // Comparison operators
  bool operator==(const BTPostOrderIterator& ) const noexcept;
  bool operator!=(const BTPostOrderIterator& ) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const;

  bool Terminated() const noexcept;

  /* ************************************************************************ */

  // Specific member function (inherited from ForwardIterator)
  BTPostOrderIterator& operator++() ;

  // Specific member function (inherited from ResettableIterator)
  void Reset() noexcept ;


private:

  // Auxiliary function
  void MostLeftLeaf(const typename BinaryTree<Data>::Node* );

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderMutableIterator : public virtual MutableIterator<Data>,
                                    public virtual BTPostOrderIterator<Data>{
                                  // Must extend MutableIterator<Data>,
                                  //             BTPostOrderIterator<Data>

private:

  typename MutableBinaryTree<Data>::MutableNode* current = nullptr;
  typename MutableBinaryTree<Data>::MutableNode* root = nullptr;
  StackLst<typename MutableBinaryTree<Data>::MutableNode*> elements ;

protected:

  // ...

public:
  
  // Specific constructor: Iterator over a given mutable binary tree
  BTPostOrderMutableIterator(MutableBinaryTree<Data>&);

  // Copy constructor
  BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data>&) ;

  // Move constructor
  BTPostOrderMutableIterator(BTPostOrderMutableIterator<Data>&&) ;

  // Destructor
  virtual ~BTPostOrderMutableIterator();

  // Copy assignment
  BTPostOrderMutableIterator<Data>& operator = (const BTPostOrderMutableIterator<Data>&);

  // Move assignment
  BTPostOrderMutableIterator<Data>& operator = (BTPostOrderMutableIterator<Data>&&);

  // Comparison operators
  bool operator==(const BTPostOrderMutableIterator<Data>& ) const noexcept ;
  bool operator!=(const BTPostOrderMutableIterator<Data>& ) const noexcept ;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  const Data& operator*() const {return BTPostOrderIterator<Data>::operator*();}

  bool Terminated() const noexcept {return BTPostOrderIterator<Data>::Terminated();} 

  Data& operator*();

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : public virtual ForwardIterator<Data>,
                          public virtual ResettableIterator<Data>{
                          // Must extend ForwardIterator<Data>,
                          //             ResettableIterator<Data>

private:

  const typename BinaryTree<Data>::Node* current = nullptr;
  const typename BinaryTree<Data>::Node* root = nullptr ;
  StackLst<const typename BinaryTree<Data>::Node* > elements ;

protected:

  // ...

public:
  
  // Specific constructor: Iterator over a given binary tree
  BTInOrderIterator(const BinaryTree<Data>& );

  // Copy constructor
  BTInOrderIterator(const BTInOrderIterator<Data>&) ;

  // Move constructor
  BTInOrderIterator(BTInOrderIterator<Data>&&) ;

  // Destructor
  virtual ~BTInOrderIterator() ; 

  // Copy assignment
  BTInOrderIterator<Data>& operator = (const BTInOrderIterator<Data>& );

  // Move assignment
  BTInOrderIterator<Data>& operator = (BTInOrderIterator&&) ;

  // Comparison operators
  bool operator==(const BTInOrderIterator<Data>& ) const noexcept ;
  bool operator!=(const BTInOrderIterator<Data>&) const noexcept ;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const;

  bool Terminated() const noexcept;

  /* ************************************************************************ */

  // Specific member function (inherited from ForwardIterator)
  BTInOrderIterator<Data>& operator++() ;

  // Specific member function (inherited from ResettableIterator)
  void Reset() noexcept ;

  private:

  // Auxiliary function
  void MostLeftLeaf(const typename BinaryTree<Data>::Node* );

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderMutableIterator : public virtual MutableIterator<Data>,
                                public virtual BTInOrderIterator<Data>{
                                  // Must extend MutableIterator<Data>,
                                  //             BTInOrderIterator<Data>

private:

  typename MutableBinaryTree<Data>::MutableNode* current = nullptr ;
  typename MutableBinaryTree<Data>::MutableNode* root = nullptr;
  StackLst<typename MutableBinaryTree<Data>::MutableNode* > elements;

protected:

  // ...

public:
  
  // Specific constructor: Iterator over a given mutable binary tree
  BTInOrderMutableIterator(MutableBinaryTree<Data>&);

  // Copy constructor
  BTInOrderMutableIterator(const BTInOrderMutableIterator<Data>&);

  // Move constructor
  BTInOrderMutableIterator(BTInOrderMutableIterator<Data>&& );

  // Destructor
  virtual ~BTInOrderMutableIterator();

  // Copy assignment
  BTInOrderMutableIterator<Data>& operator = (const BTInOrderMutableIterator<Data>&) ;

  // Move assignment
  BTInOrderMutableIterator<Data>& operator = (BTInOrderMutableIterator<Data>&&) ;

  // Comparison operators
  bool operator == (const BTInOrderMutableIterator<Data>& ) const noexcept ;
  bool operator != (const BTInOrderMutableIterator<Data>& ) const noexcept ;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  const Data& operator*() const {return BTInOrderIterator<Data>::operator*();}

  bool Terminated() const noexcept {return BTInOrderIterator<Data>::Terminated();} 

  Data& operator*() ;

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : public virtual ForwardIterator<Data>,
                          public virtual ResettableIterator<Data>{
                          // Must extend ForwardIterator<Data>,
                          //             ResettableIterator<Data>

private:

  const typename BinaryTree<Data>::Node* current = nullptr;
  const typename BinaryTree<Data>::Node* root = nullptr ;
  QueueLst<const typename BinaryTree<Data>::Node* > elements;

protected:

  // ...

public:
 
  // Specific constructor: Iterator over a given binary tree
  BTBreadthIterator(const BinaryTree<Data>&);

  // Copy constructor
  BTBreadthIterator(const BTBreadthIterator<Data>&);

  // Move constructor
  BTBreadthIterator(BTBreadthIterator<Data>&&);

  // Destructor
  virtual ~BTBreadthIterator();

  // Copy assignment
  BTBreadthIterator<Data>& operator=(const BTBreadthIterator<Data>& );

  // Move assignment
  BTBreadthIterator<Data>& operator=(BTBreadthIterator&&);

  // Comparison operators
  bool operator==(const BTBreadthIterator<Data>&) const noexcept;
  bool operator!=(const BTBreadthIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  const Data& operator*() const ;

  bool Terminated() const noexcept ;

  /* ************************************************************************ */

  // Specific member function (inherited from ForwardIterator)
  BTBreadthIterator& operator++() ;

  // Specific member function (inherited from ResettableIterator)
  void Reset() noexcept ;

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthMutableIterator : public virtual MutableIterator<Data>,
                                  public virtual BTBreadthIterator<Data>{
                                  // Must extend MutableIterator<Data>,
                                  //             BTBreadthIterator<Data>

private:

  typename MutableBinaryTree<Data>::MutableNode* current = nullptr;
  typename MutableBinaryTree<Data>::MutableNode* root = nullptr ;
  QueueLst<typename MutableBinaryTree<Data>::MutableNode*> elements;

protected:

  // ...

public: 
 
  // Specific constructor: Iterator over a given mutable binary tree
  BTBreadthMutableIterator(MutableBinaryTree<Data>&);

  // Copy constructor
  BTBreadthMutableIterator(const BTBreadthMutableIterator<Data>&);

  // Move constructor
  BTBreadthMutableIterator(BTBreadthMutableIterator&&);

  // Destructor
  virtual ~BTBreadthMutableIterator();

  // Copy assignment
  BTBreadthMutableIterator<Data>& operator=(const BTBreadthMutableIterator<Data>&) ;

  // Move assignment
  BTBreadthMutableIterator<Data>& operator=(BTBreadthMutableIterator<Data>&&) ;

  // Comparison operators
  bool operator==(const BTBreadthMutableIterator<Data>&) const noexcept;
  bool operator!=(const BTBreadthMutableIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  const Data& operator*() const {return BTBreadthIterator<Data>::operator*();}

  bool Terminated() const noexcept {return BTBreadthIterator<Data>::Terminated();} 

  Data& operator*();

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
