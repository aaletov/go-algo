#include <iostream>
#include <algorithm>
#include <vector>

const int SIZE = 1999;
const int SHIFT = 999;

struct closed_interval_t {
  int begin_;
  int end_;
  closed_interval_t(int begin, int end):
    begin_(begin + SHIFT),
    end_(end + SHIFT)
  {}
  int get_unshifted_begin() {
    return begin_ - SHIFT;
  }
  int get_unshifted_end() {
    return end_ - SHIFT;
  }
};

bool does_have_inner_points(const std::vector< bool >& coverage, const closed_interval_t& interval) {
  for (int i = interval.begin_ + 1; i < interval.end_; i++) {
    if (coverage[i] == true) {
      return true;
    }
  }
  return false;
}

void add(std::vector< bool >& coverage, const closed_interval_t& interval) {
  for (int i = interval.begin_; i < interval.end_ + 1; i++) {
    coverage[i] = true;
  }
}

bool length_comparator(const closed_interval_t& lhs, const closed_interval_t& rhs) {
  return (lhs.end_ - lhs.begin_) < (rhs.end_ - rhs.begin_);
}

bool coordinate_comparator(const closed_interval_t& lhs, const closed_interval_t& rhs) {
  return lhs.begin_ < rhs.begin_;
}

std::vector< closed_interval_t > to_intervals(const std::vector< bool >& coverage) {
  std::vector< closed_interval_t > intervals = {};

  int begin = 0;
  int end = 0;

  for (int i = 0; i < coverage.size(); i++) {
    if ((begin == 0) && (coverage[i] == 1)) {
      begin = i - SHIFT;
    }
    if ((begin != 0) && (coverage[i] == 0)) {
      end = i - 1 - SHIFT;
      intervals.push_back(closed_interval_t(begin, end));
      begin = 0;
      end = 0;
    }
  }

  return intervals;
}

int main() {
  int N = 0;
  std::cin >> N;

  std::vector< bool > coverage(SIZE);

  for (int i = 0; i < SIZE; i++) {
    coverage[i] = false;
  }

  std::vector< closed_interval_t > intervals = {};

  int lpoint = 0;
  int rpoint = 0;

  for (int i = 0; i < N; i++) {
    std::cin >> lpoint >> rpoint;
    intervals.push_back(closed_interval_t(lpoint, rpoint));
  }

  std::sort(intervals.begin(), intervals.end(), length_comparator);
  std::vector< closed_interval_t > filtered_intervals = {};

  for (int i = 0; i < N; i++) {
    if (!does_have_inner_points(coverage, intervals[i])) {
      add(coverage, intervals[i]);
      filtered_intervals.push_back(intervals[i]);
    }
  }

  std::sort(filtered_intervals.begin(), filtered_intervals.end(), coordinate_comparator);

  std::cout << filtered_intervals.size() << '\n';
  for (int i = 0; i < filtered_intervals.size(); i++) {
    std::cout << filtered_intervals[i].get_unshifted_begin() << ' ' << filtered_intervals[i].get_unshifted_end() 
              << '\n';
  }  

}