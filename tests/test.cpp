#include <gtest/gtest.h>
// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    CaptureStdout();
    GetCapturedStdout();
    ASSERT_EQ(10,10);
}
