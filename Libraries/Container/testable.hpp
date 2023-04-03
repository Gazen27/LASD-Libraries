
#ifndef TESTABLE_HPP
#define TESTABLE_HPP

/* ************************************************************************** */

#include "container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TestableContainer : virtual public Container {
                          // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Constructors
  TestableContainer() = default;
  TestableContainer(const TestableContainer&) = default;
  TestableContainer(TestableContainer&&) = default;

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

  // Specific member function
  virtual bool Exists(const Data& element) const noexcept = 0;

};

/* ************************************************************************** */

}

#endif
