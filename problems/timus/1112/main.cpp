#include <iostream>
#include <algorithm>
#include <vector>

const int SIZE = 1999;
const int SHIFT = 999;

const char TRUE = '1';
const char FALSE = '0';
const char BEGIN = '(';
const char END = ')';

struct closed_interval_t {
  int begin_;
  int end_;
  int intersects_;
  closed_interval_t(int begin, int end):
    begin_(begin + SHIFT),
    end_(end + SHIFT),
    intersects_(0)
  {}
  int get_unshifted_begin() {
    return begin_ - SHIFT;
  }
  int get_unshifted_end() {
    return end_ - SHIFT;
  }
};

bool is_point_in_interval(const closed_interval_t& interval, int point) {
  return (point > interval.begin_) && (point < interval.end_);
}

bool is_two_pointed(const closed_interval_t& lhs) {
  return lhs.end_ - lhs.begin_ == 1;
}

bool is_intersected(const closed_interval_t& lhs, const closed_interval_t& rhs) {
  return is_point_in_interval(lhs, rhs.begin_) || is_point_in_interval(rhs, lhs.begin_)
    || is_point_in_interval(lhs, rhs.end_) || is_point_in_interval(rhs, lhs.end_) 
    || ((lhs.begin_ == rhs.begin_) && (lhs.end_ == rhs.end_));
}

bool does_have_inner_points(const std::vector< char >& coverage, const closed_interval_t& interval) {
  if (is_two_pointed(interval) && ((coverage[interval.begin_] == BEGIN) || (coverage[interval.end_] == END) 
    || ((coverage[interval.begin_] == TRUE) || (coverage[interval.end_] == TRUE)))) {
    return true;
  }
  // covers all cases with inner points but two-pointed intervals doesn't have inner points
  for (int i = interval.begin_ + 1; i < interval.end_; i++) {
    if (coverage[i] != FALSE) {
      return true;
    }
  }
  return false;
}

void add(std::vector< char >& coverage, const closed_interval_t& interval) {
  if ((coverage[interval.begin_] == END) && (coverage[interval.end_] == BEGIN)) {
    for (int i = interval.begin_; i < interval.end_ + 1; i++) {
      coverage[i] = TRUE;
    }
    return;
  }

  coverage[interval.begin_] = BEGIN;
  coverage[interval.end_] = END;

  for (int i = interval.begin_ + 1; i < interval.end_; i++) {
    coverage[i] = TRUE;
  }
}

void calculate_intersects(std::vector< closed_interval_t >& intervals) {
  for (int i = 0; i < intervals.size() - 1; i++) {
    for (int j = i + 1; j < intervals.size(); j++) {
      if (is_intersected(intervals[i], intervals[j])) {
        intervals[i].intersects_++;
        intervals[j].intersects_++;
      }
    }
  }
}

bool intersect_comparator(const closed_interval_t& lhs, const closed_interval_t& rhs) {
  return lhs.intersects_ < rhs.intersects_;
}

bool coordinate_comparator(const closed_interval_t& lhs, const closed_interval_t& rhs) {
  return lhs.begin_ < rhs.begin_;
}

std::vector< closed_interval_t > task(std::vector< closed_interval_t >& intervals) {
  std::vector< char > coverage(SIZE);

  for (int i = 0; i < SIZE; i++) {
    coverage[i] = FALSE;
  }
  
  calculate_intersects(intervals);
  std::sort(intervals.begin(), intervals.end(), intersect_comparator);

  std::vector< closed_interval_t > filtered_intervals = {};

  for (int i = 0; i < intervals.size(); i++) {
    if (!does_have_inner_points(coverage, intervals[i])) {
      add(coverage, intervals[i]);
      filtered_intervals.push_back(intervals[i]);
    }
  }

  std::sort(filtered_intervals.begin(), filtered_intervals.end(), coordinate_comparator);

  return filtered_intervals;
}

int main() {
  int N = 0;
  std::cin >> N;

  std::vector< closed_interval_t > intervals = {};

  int lpoint = 0;
  int rpoint = 0;

  for (int i = 0; i < N; i++) {
    std::cin >> lpoint >> rpoint;
    intervals.push_back(closed_interval_t(lpoint, rpoint));
  }

  std::vector< closed_interval_t > filtered_intervals = task(intervals);

  std::cout << filtered_intervals.size() << '\n';
  for (int i = 0; i < filtered_intervals.size(); i++) {
    std::cout << filtered_intervals[i].get_unshifted_begin() << ' ' << filtered_intervals[i].get_unshifted_end() 
              << '\n';
  }  
}
