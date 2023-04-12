
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

typedef unsigned int uint;
typedef unsigned long ulong;

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  ulong size = 0;

public:

  // Default, Copy and Move constructor
  Container() = default;
  Container(const Container&) = default;
  Container(Container&&) noexcept = default;

  // Destructor
  virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
  Container& operator = (const Container&) noexcept = delete;

  // Move assignment
  Container& operator = (const Container&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const Container&) const noexcept = delete;
  bool operator != (const Container&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function #1: Check if the container is empty
  virtual bool Empty() const noexcept{
    if(size == 0) { return true; }
    else { return false; }
  }

  // Specific member function #2: Gives the actual size of the container
  virtual ulong Size() const noexcept{
    return this->size;
  }

};

/* ************************************************************************** */

class ClearableContainer : public virtual Container{
                            // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Default, Copy and Move constructor
  ClearableContainer() = default;
  ClearableContainer(const ClearableContainer&) = default;
  ClearableContainer(ClearableContainer&&) noexcept = default;

  // Destructor
  virtual ~ClearableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ClearableContainer& operator = (const ClearableContainer&) noexcept = delete;

  // Move assignment
  ClearableContainer& operator = (const ClearableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const ClearableContainer&) const noexcept = delete;
  bool operator != (const ClearableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function: Clears the container
  virtual void Clear() noexcept = 0;

};

/* ************************************************************************** */

class ResizableContainer : public virtual ClearableContainer{
                            // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

  // Default, Copy and Move constructor
  ResizableContainer() = default;
  ResizableContainer(const ResizableContainer&) = default;
  ResizableContainer(ResizableContainer&&) noexcept = default;

  // Destructor
  virtual ~ResizableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  ResizableContainer& operator = (const ResizableContainer&) noexcept = delete;

  // Move assignment
  ResizableContainer& operator = (const ResizableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const ResizableContainer&) const noexcept = delete;
  bool operator != (const ResizableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function #1: Change the size of the container
  virtual void Resize(const ulong) noexcept = 0;

  /* ************************************************************************ */

  // Override function from ClearableContainer
  virtual void Clear() noexcept override { Resize(0); }  
};

/* ************************************************************************** */

}

#endif
