#include <iostream>
#include <set>
#include <algorithm>

struct city_t {
  int id_;
  int population_;

  city_t(int id, int population):
    id_(id),
    population_(population)
  {}
};

bool operator<(const city_t& lhs, const city_t& rhs) {
  return (lhs.population_ < rhs.population_) || ((lhs.population_ == rhs.population_) && (lhs.id_ < rhs.id_));
}

int main() {
  int N = 0;
  int q = 0;

  std::cin >> N;
  std::set< city_t > cities = {};

  for (int i = 0; i < N; i++) {
    int population = 0;
    std::cin >> population;

    cities.insert(city_t(i + 1, population));
  }

  std::cin >> q;

  char* out = new char[q + 1];
  out[q] = '\0';

  for (int i = 0; i < q; i++) {
    int l = 0;
    int r = 0;
    int x = 0;
    std::cin >> l >> r >> x;
    
    out[i] = '0';

    city_t lower_f = city_t(l, x);
    city_t upper_f = city_t(r, x);

    std::set< city_t >::const_iterator lower = cities.lower_bound(lower_f);
    std::set< city_t >::const_iterator upper = cities.upper_bound(upper_f);

    for (; lower != upper; lower++) {
      if ((*lower).population_ == x) {
        out[i] = '1';
      }
    }
  }

  std::cout << out << '\n';

  delete[] out;
}
