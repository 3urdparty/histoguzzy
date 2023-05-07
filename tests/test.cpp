#include <gtest/gtest.h>
#include <histoguzzy/histoguzzy.hpp>
#include <string>
// Demonstrate some basic assertions.
TEST(HelloTest, Histogram) {
    cout << "\n\n";
    vector<string> headers = {"header", "values", "asdf", "Asdf"};
    vector<float> values = {1, 20, 32, 12};
    testing::internal::CaptureStdout();
    displayVerticalHistogram(headers, values);
    string graph = testing::internal::GetCapturedStdout();
    // std::cerr << graph;
    // std::cerr << "\n\n";
    EXPECT_NE(10, 11)
      << graph;
    // GetCapturedStdout();
    ASSERT_EQ(10,10);
}
