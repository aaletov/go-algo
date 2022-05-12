#include <iostream>
#include <vector>

int main() {
  int N = 0;
  int q = 0;

  std::cin >> N;
  std::vector< int > population_vector(N);

  for (int i = 0; i < N; i++) {
    int population = 0;
    std::cin >> population;
    population_vector[i] = population;
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
    for (int j = l - 1; j < r; j++) {
      if (population_vector[j] == x) {
        out[i] = '1';
      }
    }
  }

  std::cout << out << '\n';

  delete[] out;
}