#include <vector>
#include <gtest/gtest.h>
#include "main.cpp"

TEST(TestSuite, Contest) {
    int n = 4;
    int k = 11;
    
    double* lengths = new double[n]{8.02, 7.43, 4.57, 5.39};
    
    EXPECT_STREQ(task(n, k, lengths), "2.00");
    
    delete[] lengths;
}

TEST(TestSuite, SingleValue) {
    int tests_count = 5;
    
    int n = 1;
    int k_values[] = {1, 2, 3, 4, 5};
    double* lengths = new double[n]{3};
    std::vector< const char* > expected = {"3.00, 1.50, 1.00, 0.75, 0.60"};

    for (int i = 0; i < tests_count; i++) {
        EXPECT_STREQ(task(n, k_values[i], lengths), expected[i]);
    }
    
    delete[] lengths;
}

TEST(TestSuite, TwoValuesCheck) {
    int tests_count = 5;
    
    int n = 2;
    int k_values[] = {1, 2, 3, 4, 5};
    double* lengths = new double[n]{2, 3};
    std::vector< const char* > expected = {"3.00, 2.00, 1.50, 1.00, 1.00"};

    for (int i = 0; i < tests_count; i++) {
        EXPECT_STREQ(task(n, k_values[i], lengths), expected[i]);
    }
    
    delete[] lengths;
}