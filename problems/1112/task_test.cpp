#include <vector>
#include <gtest/gtest.h>
#include <set>
#include "main.cpp"

void test_no_overlap(closed_interval_t fixed, int begin, std::vector< int > no_overlap_ends, int expected_size) {
  for (int i = 0; i < no_overlap_ends.size(); i++) {
    std::vector< closed_interval_t > intervals {
      fixed,
      closed_interval_t(begin, no_overlap_ends[i])
    };
    std::vector< closed_interval_t > filtered_intervals = task(intervals);
    EXPECT_EQ(expected_size, filtered_intervals.size());
  }
}

void test_overlap(closed_interval_t fixed, int begin, std::vector< int > overlap_ends, int expected_size) {
  for (int i = 0; i < overlap_ends.size(); i++) {
    std::vector< closed_interval_t > intervals {
      fixed,
      closed_interval_t(begin, overlap_ends[i])
    };
    std::vector< closed_interval_t > filtered_intervals = task(intervals);
    EXPECT_EQ(expected_size, filtered_intervals.size());
  }
}

TEST(TestTask, BeginBeforeBegin) {
  closed_interval_t fixed = closed_interval_t(1, 5);
  int begin = -5;
  std::vector< int > no_overlap_ends {-3, 1};
  std::vector< int > overlap_ends {3, 5, 7};

  test_no_overlap(fixed, begin, no_overlap_ends, 2);
  test_overlap(fixed, begin, overlap_ends, 1);
}

TEST(TestTask, BeginEqualBegin) {
  closed_interval_t fixed = closed_interval_t(1, 5);
  int begin = 1;
  std::vector< int > overlap_ends {3, 5, 7};

  test_overlap(fixed, begin, overlap_ends, 1);
}

TEST(TestTask, BeginAfterBeginBeforeEnd) {
  closed_interval_t fixed = closed_interval_t(1, 5);
  int begin = 3;
  std::vector< int > overlap_ends {4, 5, 7};

  test_overlap(fixed, begin, overlap_ends, 1);
}

TEST(TestTask, BeginEqualEnd) {
  closed_interval_t fixed = closed_interval_t(1, 5);
  int begin = 5;
  std::vector< int > no_overlap_ends {7};

  test_no_overlap(fixed, begin, no_overlap_ends, 2);
}

TEST(TestTask, BeginAfterEnd) {
  closed_interval_t fixed = closed_interval_t(1, 5);
  int begin = 7;
  std::vector< int > no_overlap_ends {9};

  test_no_overlap(fixed, begin, no_overlap_ends, 2);
}

TEST(TestTask, TestTwoPointed) {
  closed_interval_t first = closed_interval_t(1, 2);
  closed_interval_t second = closed_interval_t(1, 2);

  std::vector< closed_interval_t > intervals{first, second};

  std::vector< closed_interval_t > filtered_intervals = task(intervals);

  EXPECT_EQ(1, filtered_intervals.size());
}