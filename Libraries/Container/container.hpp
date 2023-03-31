
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

typedef unsigned int uint;

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  uint size = 0;

public:

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

  // Specific member functions

  virtual bool Empty() const noexcept{
    if(size == 0) { return true; }
    else { return false; }
  }

  virtual uint Size() const noexcept{
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
  bool operator != (const ClearableContainer&&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function
  virtual void Clear() = 0;

};

/* ************************************************************************** */

class ResizableContainer : public virtual ClearableContainer{
                            // Must extend ClearableContainer

private:

  // ...

protected:

  // ...

public:

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

  // Specific member function
  virtual void Resize(uint s) noexcept { this->size = s; }

  /* ************************************************************************ */

  // Function Clear() inherited from ClearableContainer
};

/* ************************************************************************** */

}

#endif
