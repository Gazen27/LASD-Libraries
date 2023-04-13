
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/dictionary.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : public virtual ClearableContainer,
              public virtual DictionaryContainer<Data>,
              public virtual LinearContainer<Data> {
              // Must extend ClearableContainer,
              //             DictionaryContainer<Data>,
              //             LinearContainer<Data>

private:

  // ...

protected:

  using Container::size;

  struct Node {

    // Data
    Data key;
    Node* next = nullptr;

    /* ********************************************************************** */

    // Specific constructor #1: Given initial value (copy)
    Node(const Data&); 

    // Specific constructor #2: Given initial value (move)
    Node(Data&&); 

    // Copy constructor
    Node(const Node&);

    // Move constructor
    Node(Node&&);

    // Destructor
    ~Node();

    /* ********************************************************************** */

    // Comparison operators
    bool operator == (const Node&) const noexcept;
    bool operator != (const Node&) const noexcept;

    /* ********************************************************************** */

    // Specific member functions

    // ...

  };

  // Initializing head and tail
  Node* head = nullptr;
  Node* tail = nullptr;

public:

  // Default constructor
  List() = default;

  /* ************************************************************************ */

  // Specific constructor #1: List obtained from a MappableContainer
  List(const MappableContainer<Data>&) noexcept;

  // Specific constructor #2: List obtained from a MutableMappableContainer
  List(MutableMappableContainer<Data>&&) noexcept;


  // Copy constructor
  List(const List&);

  // Move constructor
  List(List&&) noexcept;


  // Destructor
  virtual ~List();

  /* ************************************************************************ */

  // Copy assignment
  List& operator = (const List&) noexcept;

  // Move assignment
  List& operator = (List&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const List&) const noexcept;
  bool operator != (const List&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  void InsertAtFront(const Data&); // Copy of the value
  void InsertAtFront(Data&&); // Move of the value
  void RemoveFromFront();
  
  Data& FrontNRemove(); // (must throw std::length_error when empty)

  void InsertAtBack(const Data&); // Copy of the value
  void InsertAtBack(Data&&); // Move of the value

  /* ************************************************************************ */

  // Override function from ClearableContainer

  void Clear() noexcept override;

  /* ************************************************************************ */

  // Override function Exists
  bool Exists(const Data& e) const noexcept override;

  // Override functions from DictionaryContainer

  bool Insert(const Data&) override;   // Copy of the value
  bool Insert(Data&&) override;  // Move of the value
  bool Remove(const Data&) override;

  /* ************************************************************************ */

  // Override functions from LinearContainer

  // Non-Mutable version
  const Data& operator [] (const ulong) const override; // must throw std::out_of_range when out of range
  
  // Mutable version
  Data& operator [] (const ulong) override; // must throw std::out_of_range when out of range

  // Non-Mutable version
  const Data& Front() const override;
  
  // Mutable version
  Data& Front() override;

  // Mutable version
  const Data& Back() const override;

  // Non-Mutable version
  Data& Back() override;

  /* ************************************************************************ */

  using typename FoldableContainer<Data>::FoldFunctor;

  // Override function from FoldableContainer
  void Fold(FoldFunctor, void*) const override;

  // Override function from PreOrderFoldableContainer
  void PreOrderFold(FoldFunctor, void*) const override;

  // Override function from PostOrderFoldableContainer
  void PostOrderFold(FoldFunctor, void*) const override;

  /* ************************************************************************ */

  using typename MappableContainer<Data>::MapFunctor;

  // Override function from MappableContainer
  void Map(MapFunctor) const override;

  // Override function from PreOrderMappableContainer
  void PreOrderMap(MapFunctor) const override;

  // Override function from PostOrderMappableContainer
  void PostOrderMap(MapFunctor) const override;

  /* ************************************************************************ */

  using typename MutableMappableContainer<Data>::MutableMapFunctor;
  
  // Override function from MutableMappableContainer
  void Map(MutableMapFunctor) override;

  // Override function from MutablePreOrderMappableContainer
  void PreOrderMap(MutableMapFunctor) override;

  // Override function from MutablePostOrderMappableContainer
  void PostOrderMap(MutableMapFunctor) override;

protected:

  // Auxiliary member functions (for PreOrderFoldableContainer & PostOrderFoldableContainer)

  // type PreOrderFold(arguments) specifiers; // Accessory function executing from one point of the list onwards
  // type PostOrderFold(arguments) specifiers; // Accessory function executing from one point of the list onwards

  /* ************************************************************************ */

  // Auxiliary member functions (for PreOrderMappableContainer & PostOrderMappableContainer)

  // type PreOrderMap(arguments) specifiers; // Accessory function executing from one point of the list onwards
  // type PostOrderMap(arguments) specifiers; // Accessory function executing from one point of the list onward

  /* ************************************************************************ */

  // Auxiliary member functions (for MutablePreOrderMappableContainer & MutablePostOrderMappableContainer)

  // type PreOrderMap(arguments) specifiers; // Accessory function executing from one point of the list onwards
  // type PostOrderMap(arguments) specifiers; // Accessory function executing from one point of the list onward

  /* ************************************************************************ */

};


}

#include "list.cpp"

#endif
