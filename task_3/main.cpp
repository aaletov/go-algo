#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>

const int DIMENSIONS = 4;
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
  std::vector< bitset > vectors {
    bitset{"1100"},
    bitset{"1000"},
    bitset{"0100"},
    bitset{"0001"},
    bitset{"0111"}
  };

  bitset start_point{"0000"};
  bitset end_point{"1111"};

  int i = 0;
  while (end_point != start_point) {
    bts_iterator nearest_it = get_hamming_nearest(vectors, end_point);
    end_point ^= *nearest_it;

    std::cout << *nearest_it << '\n';
    std::cout << end_point << '\n';

    vectors.erase(nearest_it, nearest_it);

    if (i > 10) {
      break;
    }
    i++;
  }  
}