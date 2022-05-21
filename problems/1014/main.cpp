#include <iostream>
#include <vector>
#include <algorithm>

std::vector< int > get_dig_divisors(int N) {
  const int divisors_number = 8;
  const int divisors[] = {9, 8, 7, 6, 5, 4, 3, 2};
  std::vector< int > found_divisors = {};

  if (N == 1) {
    return std::vector< int >{1};
  }

  while (N != 1) {
    int found_divisor = 0;
    for (int i = 0; i < divisors_number; i++) {
      if (N % divisors[i] == 0) {
        found_divisor = divisors[i];
        break;
      }
    }
    if (found_divisor == 0) {
      return std::vector< int >();
    } else {
      found_divisors.push_back(found_divisor);
    }

    N /= found_divisor;
  }

  return found_divisors;
}

int main() {
  int N = 0;
  std::cin >> N;

  if (N == 0) {
    std::cout << 10 << '\n';
    return 0;
  }

  std::vector< int > dig_divisors = get_dig_divisors(N);

  if (dig_divisors.empty()) {
    std::cout << -1 << '\n';
  } else {
    std::sort(dig_divisors.begin(), dig_divisors.end());
    for (int i = 0; i < dig_divisors.size(); i++) {
      std::cout << dig_divisors[i];
    }
    std::cout << '\n';
  }
}