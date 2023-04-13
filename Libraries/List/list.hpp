
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
  const Data& Front() const override; // must throw std::length_error when empty
  
  // Mutable version
  Data& Front() override; // must throw std::length_error when empty

  // Mutable version
  const Data& Back() const override; // must throw std::length_error when empty

  // Non-Mutable version
  Data& Back() override; // must throw std::length_error when empty

  /* ************************************************************************ */

  // Override function from FoldableContainer
  // using typename FoldableContainer<Data>::FoldFunctor;
  // type Fold(arguments) specifiers; // Override FoldableContainer member


  // Override function from PreOrderFoldableContainer
  // type PreOrderFold(arguments) specifiers;


  // Override function from PostOrderFoldableContainer
  // type PostOrderFold(arguments) specifiers;


  // Override function from MappableContainer
  // using typename MappableContainer<Data>::MapFunctor;
  // type Map(argument) specifiers;


  // Override function from PreOrderMappableContainer
  // type PreOrderMap(argument) specifiers;


  // Override function from PostOrderMappableContainer
  // type PostOrderMap(argument) specifiers;


  // Override function from MutableMappableContainer
  // using typename MutableMappableContainer<Data>::MutableMapFunctor;
  // type Map(argument) specifiers;


  // Override function from MutablePreOrderMappableContainer
  // type PreOrderMap(argument) specifiers;


  // Override function from MutablePostOrderMappableContainer
  // type PostOrderMap(argument) specifiers;

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
