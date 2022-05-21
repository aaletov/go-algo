#include <unordered_map>
#include <set>

struct city_t {
  std::set< int > ids_;
  city_t(int init_id):
    ids_(std::set{init_id})
  {}
};

int main() {
  std::unordered_map< int, city_t > map = {};

  for (int i = 0; i < 70000; i++) {
    map.insert({i, city_t(i)});
  }
}