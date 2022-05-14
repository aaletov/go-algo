#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>

const int DIMENSIONS = 2000;
using bitset = std::bitset< DIMENSIONS >;
using bts_iterator = std::vector< bitset >::iterator;
using bts_citerator = std::vector< bitset >::const_iterator;

int get_hamming_distance(const bitset& lhs, const bitset& rhs) {
  return (lhs ^ rhs).count();
}

bts_iterator get_hamming_nearest(std::vector< bitset >& vectors, const bitset& source) {
  bts_iterator nearest_it = vectors.begin();

  for (bts_iterator it = vectors.begin(); it != vectors.end(); it++) {
    if (get_hamming_distance(*it, source) < get_hamming_distance(*nearest_it, source)) {
      nearest_it = it;
    }
  }

  return nearest_it;
}

int main() {
  int N = 0;
  std::cin >> N;

  std::vector< bitset > vectors(100);

  int lbound = 0;
  int ubound = 0;

  for (int i = 0; i < N - 1; i++) {
    std::cin >> lbound >> ubound;

    for (int j = lbound + 999; j < ubound + 999; j++) {
      vectors[i][j] = true;
    }
  }

  std::cin >> lbound >> ubound;
  bitset start_point = {};
  bitset end_point = {};
  for (int j = lbound + 999; j < ubound + 999; j++) {
    end_point[j] = true;
  }

  std::vector< bitset > optimized = {};

  while ((end_point != start_point) && !vectors.empty()) {
    std::cout << end_point << '\n';

    bts_iterator nearest_it = get_hamming_nearest(vectors, end_point);
    end_point = ~((~end_point) | (*nearest_it));

    optimized.push_back(*nearest_it);
    vectors.erase(nearest_it, nearest_it);

  }  

  for (bitset bts: optimized) {
    for (int i = bts.size()-1; i > -1; --i) {
      if (bts.test(i)) {
        std::cout << i << '\n';
      }
    }
    std::cout << '\n';
  }
}