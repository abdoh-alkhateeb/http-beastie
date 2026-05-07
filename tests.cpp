#include <gtest/gtest.h>
#include "utils.hpp"

TEST(FileContentsFunction, HandlesCorrectPaths) {
    EXPECT_EQ(fileContents("../test.txt"), "hello\nworld");
}

TEST(FileContentsFunction, HandlesIncorrectPaths) {
    EXPECT_EQ(fileContents("../te.txt"), "");
}