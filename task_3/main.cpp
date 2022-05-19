#include <iostream>
#include <algorithm>
#include <vector>

using viterator = std::vector< closed_interval_t >::iterator;

struct closed_interval_t {
  int begin_;
  int end_;
  closed_interval_t(int begin, int end):
    begin_(begin),
    end_(end)
  {}
};

struct coverage_interval_t {
  closed_interval_t interval_;
  std::vector< closed_interval_t > coverage_;
  bool is_covered_;
  coverage_interval_t(closed_interval_t interval):
    interval_(interval),
    coverage_(),
    is_covered_(false)
  {}
};

bool is_point_in_interval(const closed_interval_t& interval, int point) {
  return (point >= interval.begin_) && (point <= interval.end_);
}

bool is_intersected(const closed_interval_t& lhs, const closed_interval_t& rhs) {
  return is_point_in_interval(lhs, rhs.begin_) || is_point_in_interval(rhs, lhs.begin_);
}

closed_interval_t merge(const closed_interval_t& lhs, const closed_interval_t& rhs) {
  assert(is_intersected(lhs, rhs));

  int min_begin = (lhs.begin_ <= rhs.begin_) ? lhs.begin_ : rhs.begin_;
  int max_end = (lhs.end_ >= rhs.end_) ? lhs.end_ : rhs.end_;

  assert(max_end > min_begin);

  return closed_interval_t(min_begin, max_end);
}

int get_intersect_factor(const closed_interval_t& lhs, const closed_interval_t& rhs) {
  assert(is_intersected(lhs, rhs));

  int max_begin = (lhs.begin_ >= rhs.begin_) ? lhs.begin_ : rhs.begin_;
  int min_end = (lhs.end_ <= rhs.end_) ? lhs.end_ : rhs.end_;

  int intersect_factor = 0;

  if (max_begin <= min_end) {
    intersect_factor = max_end - max_begin + 1;
  }

  return intersect_factor;
}

bool is_intersected(const coverage_interval_t& coverage, const closed_interval_t& interval) {
  return is_intersected(coverage.interval_, interval);
}

void merge(coverage_interval_t& coverage, const closed_interval_t& interval) {
  coverage.interval_ = merge(coverage.interval_, interval);
}



void exclude(const closed_interval_t& lhs, const closed_interval_t& rhs) {

}

int main() {
  int N = 0;
  std::cin >> N;

  std::vector< closed_interval_t > intervals = {};
  std::vector< coverage_interval_t > coverage_intervals = {};

  int lpoint = 0;
  int rpoint = 0;

  for (int i = 0; i < N; i++) {
    std::cin >> lpoint >> rpoint;
    closed_interval_t interval(lpoint, rpoint);

    bool do_push_back = true;

    for(int j = 0; j < coverage_intervals.size(); j++) {
      if (is_intersected(interval, coverage_intervals[j].interval_)) {
        coverage_intervals[j] = coverage_interval_t(merge(interval, merged_intervals[j].interval_));
        do_push_back = false;
      }
    }

    if (do_push_back) {
      merged_intervals.push_back(interval);
    }

    intervals.push_back(interval);
  }

  for (const closed_interval_t& interval: intervals) {
    int max_intersect_factor = 0;
    int current_intersect_factor = 0;
    const closed_interval_t& max_intersect_interval = intervals[0]; 

    for (viterator it = merged_intervals.begin(); it != merged_intervals.end(); it++) {
      if (is_intersected(interval, *it)) {
        current_intersect_factor = get_intersect_factor(interval, *it);
        if (current_intersect_factor > max_intersect_factor) {
          max_intersect_factor = current_intersect_factor;
          max_intersect_interval = interval;
        }
      }
    }

    if (interval == (*it)) {
      merged_intervals.erase(it);
    } else {
      exclude((*it), interval);
    }
  }


}