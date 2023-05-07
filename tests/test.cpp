#include <gtest/gtest.h>
#include <histoguzzy/histoguzzy.hpp>
#include <string>
// Demonstrate some basic assertions.
TEST(HelloTest, Histogram) {
    cout << "\n\n";
    vector<string> headers = {"header", "values", "asdf", "Asdf", "Hey"};
    vector<float> values = {1, 20, 32, 32, 10};
    testing::internal::CaptureStdout();
    displayVerticalHistogram(headers, values);
    string graph = testing::internal::GetCapturedStdout();
    std::cerr << graph << endl;
    ASSERT_EQ(10,10);
}
