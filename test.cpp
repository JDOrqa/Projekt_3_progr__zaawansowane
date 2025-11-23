#include "pch.h"
#include "gtest/gtest.h"
#include "../MergeSortProject/MergeSort.h"
#include <vector>

TEST(MergeSortTests, AlreadySorted) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 3, 4, 5}));
}
