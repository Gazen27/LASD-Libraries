
#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */

#include "container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TestableContainer : public virtual Container {
                          // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Default, Copy and Move constructor
  TestableContainer() = default;
  TestableContainer(const TestableContainer&) = default;
  TestableContainer(TestableContainer&&) noexcept = default;

  // Destructor
  virtual ~TestableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  TestableContainer& operator = (const TestableContainer&) noexcept = delete;

  // Move assignment
  TestableContainer& operator = (TestableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const TestableContainer&) const noexcept = delete;
  bool operator != (const TestableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member function: Check if a given element is contained
  virtual bool Exists(const Data& element) const noexcept = 0;

};

/* ************************************************************************** */

}

#endif
