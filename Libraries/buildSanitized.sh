
#! /bin/bash

# Sanitize version (remove comment to build)
g++ -O3 -std=c++20 -fsanitize=address -o main main.cpp \
  zmytest/test.cpp zlasdtest/test.cpp zlasdtest/container/container.cpp \
  zlasdtest/exercise1a/simpletest.cpp zlasdtest/exercise1a/fulltest.cpp \
  zlasdtest/exercise1b/simpletest.cpp zlasdtest/exercise1b/fulltest.cpp \
  zmytest/allTest/vectest.cpp zmytest/allTest/listtest.cpp zmytest/allTest/stacktest.cpp