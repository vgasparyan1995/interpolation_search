#include <algorithm>
#include <iostream>
#include <vector>

#include "interpolation_search.h"

template <typename T> void EXPECT_EQUAL(T actual, T expected) {
  if (actual != expected) {
    std::cout << "Fail: " << *actual << " != " << *expected << '\n';
  }
}

int main() {
  std::vector<int> vec = {-8, -3, 0, 5, 7, 7, 7, 9, 15, 28, 39};
  // lower_bound
  EXPECT_EQUAL(interpolation_lower_bound(vec.begin(), vec.end(), -10),
               std::lower_bound(vec.begin(), vec.end(), -10));
  EXPECT_EQUAL(interpolation_lower_bound(vec.begin(), vec.end(), -8),
               std::lower_bound(vec.begin(), vec.end(), -8));
  EXPECT_EQUAL(interpolation_lower_bound(vec.begin(), vec.end(), -4),
               std::lower_bound(vec.begin(), vec.end(), -4));
  EXPECT_EQUAL(interpolation_lower_bound(vec.begin(), vec.end(), -3),
               std::lower_bound(vec.begin(), vec.end(), -3));
  EXPECT_EQUAL(interpolation_lower_bound(vec.begin(), vec.end(), 0),
               std::lower_bound(vec.begin(), vec.end(), 0));
  EXPECT_EQUAL(interpolation_lower_bound(vec.begin(), vec.end(), 3),
               std::lower_bound(vec.begin(), vec.end(), 3));
  EXPECT_EQUAL(interpolation_lower_bound(vec.begin(), vec.end(), 6),
               std::lower_bound(vec.begin(), vec.end(), 6));
  EXPECT_EQUAL(interpolation_lower_bound(vec.begin(), vec.end(), 7),
               std::lower_bound(vec.begin(), vec.end(), 7));
  EXPECT_EQUAL(interpolation_lower_bound(vec.begin(), vec.end(), 9),
               std::lower_bound(vec.begin(), vec.end(), 9));
  EXPECT_EQUAL(interpolation_lower_bound(vec.begin(), vec.end(), 35),
               std::lower_bound(vec.begin(), vec.end(), 35));
  EXPECT_EQUAL(interpolation_lower_bound(vec.begin(), vec.end(), 39),
               std::lower_bound(vec.begin(), vec.end(), 39));
  EXPECT_EQUAL(interpolation_lower_bound(vec.begin(), vec.end(), 40),
               std::lower_bound(vec.begin(), vec.end(), 40));
  // upper_bound
  EXPECT_EQUAL(interpolation_upper_bound(vec.begin(), vec.end(), -10),
               std::upper_bound(vec.begin(), vec.end(), -10));
  EXPECT_EQUAL(interpolation_upper_bound(vec.begin(), vec.end(), -8),
               std::upper_bound(vec.begin(), vec.end(), -8));
  EXPECT_EQUAL(interpolation_upper_bound(vec.begin(), vec.end(), -4),
               std::upper_bound(vec.begin(), vec.end(), -4));
  EXPECT_EQUAL(interpolation_upper_bound(vec.begin(), vec.end(), -3),
               std::upper_bound(vec.begin(), vec.end(), -3));
  EXPECT_EQUAL(interpolation_upper_bound(vec.begin(), vec.end(), 0),
               std::upper_bound(vec.begin(), vec.end(), 0));
  EXPECT_EQUAL(interpolation_upper_bound(vec.begin(), vec.end(), 3),
               std::upper_bound(vec.begin(), vec.end(), 3));
  EXPECT_EQUAL(interpolation_upper_bound(vec.begin(), vec.end(), 6),
               std::upper_bound(vec.begin(), vec.end(), 6));
  EXPECT_EQUAL(interpolation_upper_bound(vec.begin(), vec.end(), 7),
               std::upper_bound(vec.begin(), vec.end(), 7));
  EXPECT_EQUAL(interpolation_upper_bound(vec.begin(), vec.end(), 9),
               std::upper_bound(vec.begin(), vec.end(), 9));
  EXPECT_EQUAL(interpolation_upper_bound(vec.begin(), vec.end(), 35),
               std::upper_bound(vec.begin(), vec.end(), 35));
  EXPECT_EQUAL(interpolation_upper_bound(vec.begin(), vec.end(), 39),
               std::upper_bound(vec.begin(), vec.end(), 39));
  EXPECT_EQUAL(interpolation_upper_bound(vec.begin(), vec.end(), 40),
               std::upper_bound(vec.begin(), vec.end(), 40));
}
