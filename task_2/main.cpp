#include <iostream>
#include <vector>
#include <algorithm>

struct city_t {
  int id_;
  int population_;

  city_t():
    id_(0),
    population_(0)
  {}

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
  std::vector< city_t > cities(70000);

  for (int i = 0; i < N; i++) {
    int population = 0;
    std::cin >> population;

    cities[i] = city_t(i + 1, population);
  }

  std::sort(cities.begin(), cities.end());

  std::cin >> q;

  char* out = new char[q + 1];
  out[q] = '\0';

  for (int i = 0; i < q; i++) {
    int l = 0;
    int r = 0;
    int x = 0;
    std::cin >> l >> r >> x;
    
    out[i] = '0';

    city_t lower_city(l, x);
    city_t upper_city(r, x);

    std::vector< city_t >::const_iterator lower = std::lower_bound(cities.cbegin(), cities.cend(), lower_city);
    std::vector< city_t >::const_iterator upper = std::upper_bound(cities.cbegin(), cities.cend(), upper_city);

    for (; lower != upper; lower++) {
      if ((*lower).population_ == x) {
        out[i] = '1';
      }
    }
  }

  std::cout << out << '\n';

  delete[] out;
}
