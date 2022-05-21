#include <vector>
#include <gtest/gtest.h>
#include "main.cpp"

TEST(TestSuite, Contest) {
  const int LEN = 5;
  char expected[LEN] = {'1', '0', '1', '0', '1'};

  const int N = 5;
  const int Q = 5;

  std::unordered_map< int, city_t > population_to_cities = {};

  population_to_cities.insert({1234567, city_t(1)});
  population_to_cities.insert({666666, city_t(2)});
  population_to_cities.insert({3141593, city_t(3)});
  population_to_cities.insert({666666, city_t(4)});
  population_to_cities.insert({4343434, city_t(5)});

  EXPECT_EQ(query(population_to_cities, 1, 5, 3141593), '1');
  EXPECT_EQ(query(population_to_cities, 1, 5, 578202), '0');
  EXPECT_EQ(query(population_to_cities, 2, 4, 666666), '1');
  EXPECT_EQ(query(population_to_cities, 4, 4, 7135610), '0');
  EXPECT_EQ(query(population_to_cities, 1, 1, 1234567), '1');
}

TEST(TestClosedInterval, UpdateExisting) {
  const int MIN = 1;
  const int MAX = 1;

  closed_interval_t interval(MIN, MAX);
  interval.update(1);
  EXPECT_EQ(interval.min_, MIN);
  EXPECT_EQ(interval.max_, MAX);
}

TEST(TestClosedInterval, UpdateLower) {
  const int MIN = 5;
  const int MAX = 5;

  const int NEW_MIN = 1;

  closed_interval_t interval(MIN, MAX); 
  interval.update(NEW_MIN);
  EXPECT_EQ(interval.min_, NEW_MIN);
  EXPECT_EQ(interval.max_, MAX);
}

TEST(TestClosedInterval, UpdateUpper) {
  const int MIN = 5;
  const int MAX = 5;

  const int NEW_MAX = 10;

  closed_interval_t interval(MIN, MAX); 
  interval.update(NEW_MAX);
  EXPECT_EQ(interval.min_, MIN);
  EXPECT_EQ(interval.max_, NEW_MAX);
}

TEST(TestClosedInterval, ContainsPointInNormalInterval) {
  const int MIN = 5;
  const int MAX = 10;

  closed_interval_t interval(MIN, MAX);

  EXPECT_TRUE(interval.contains_point(5));
  EXPECT_TRUE(interval.contains_point(7));
  EXPECT_TRUE(interval.contains_point(10));

  EXPECT_FALSE(interval.contains_point(1));
}

TEST(TestClosedInterval, ContainsPointInDegenerateInterval) {
  const int MIN = 5;
  const int MAX = 5;

  closed_interval_t interval(MIN, MAX);

  EXPECT_TRUE(interval.contains_point(5));
  EXPECT_FALSE(interval.contains_point(2));
}

TEST(TestCity, WithOneId) {
  city_t city(6);

  EXPECT_TRUE(city.contains_from_range({1, 7}));
  EXPECT_TRUE(city.contains_from_range({6, 10}));
  EXPECT_TRUE(city.contains_from_range({1, 6}));
  EXPECT_TRUE(city.contains_from_range({6, 6}));

  EXPECT_FALSE(city.contains_from_range({8, 9}));
}

TEST(TestCity, Insert) {
  city_t city(6);

  EXPECT_FALSE(city.contains_from_range({7, 7}));
  city.insert(7);
  EXPECT_TRUE(city.contains_from_range({7, 7}));
}

TEST(TestCity, WithMultipleId) {
  city_t city(4);
  city.insert(6);
  city.insert(9);

  EXPECT_TRUE(city.contains_from_range({4, 9}));

  EXPECT_TRUE(city.contains_from_range({1, 9}));
  EXPECT_TRUE(city.contains_from_range({1, 5}));
  EXPECT_TRUE(city.contains_from_range({1, 4}));

  EXPECT_TRUE(city.contains_from_range({4, 12}));
  EXPECT_TRUE(city.contains_from_range({5, 12}));
  EXPECT_TRUE(city.contains_from_range({9, 12}));

  EXPECT_TRUE(city.contains_from_range({5, 8}));

  EXPECT_TRUE(city.contains_from_range({7, 9}));
  EXPECT_TRUE(city.contains_from_range({7, 10}));
  
  EXPECT_FALSE(city.contains_from_range({7, 8}));
  EXPECT_FALSE(city.contains_from_range({5, 5}));
}