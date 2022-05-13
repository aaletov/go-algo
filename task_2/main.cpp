#include <iostream>
#include <unordered_map>
#include <set>

struct closed_interval_t {
  int min_;
  int max_;

  closed_interval_t(int min, int max):
    min_(min),
    max_(max)
  {}

  void update(int point) {
    if (point < min_) {
      min_ = point;
    } else if (point > max_) {
      max_ = point;
    }
  }

  bool contains_point(int point) {
    return (point >= min_) && (point <= max_);
  }
};

struct city_t {
  std::set< int > id_map_;
  closed_interval_t interval_;

  city_t(int init_id):
    id_map_(std::set< int >{init_id}),
    interval_(closed_interval_t(init_id, init_id))
  {}

  std::pair< std::set< int >::iterator, bool > insert(int id) {
    interval_.update(id);
    return id_map_.insert(id);
  }

  bool contains_in_map(closed_interval_t interval) {
    std::set< int >::iterator lower = id_map_.lower_bound(interval.min_);
    std::set< int >::iterator upper = id_map_.upper_bound(interval.max_);
    return (lower != id_map_.end()) && (lower != upper);
  }

  bool contains_from_range(closed_interval_t interval) {
    return interval.contains_point(interval_.min_) || interval.contains_point(interval_.max_) || 
      contains_in_map(interval);    
  }
};

char query(std::unordered_map< int, city_t >& population_to_cities, int l, int r, int x) {
  char is_present = '0';

  auto&& city_it = population_to_cities.find(x);
  if (city_it != population_to_cities.end()) {
    city_t city = std::get< 1 >(*(city_it));
    closed_interval_t interval(l, r);

    if (city.contains_from_range(interval)) {
      is_present = '1';
    }
  }
  
  return is_present;
}

int main() {
  int N = 0;
  int q = 0;

  std::cin >> N;
  std::unordered_map< int, city_t > population_to_cities = {};

  for (int i = 0; i < N; i++) {
    int population = 0;
    std::cin >> population;

    auto&& it = population_to_cities.find(population);
    if (it == population_to_cities.end()) {
      population_to_cities.insert({population, city_t(i + 1)});
    } else {
      std::get< 1 >(*it).insert(i + 1);
    }
  }

  std::cin >> q;

  char* out = new char[q + 1];
  out[q] = '\0';

  for (int i = 0; i < q; i++) {
    int l = 0;
    int r = 0;
    int x = 0;
    std::cin >> l >> r >> x;
    
    out[i] = query(population_to_cities, l, r, x);
  }

  std::cout << out << '\n';

  delete[] out;
}
