//
// Created by Alexander Bzikadze on 30.09.2018.
//

#include "gtest/gtest.h"

#include "sorting/counting_sort.hpp"


using algolib::sorting::counting_sort;


TEST(TestCountingSort, EmptySort) {
    std::vector<int> v;

    counting_sort(v.cbegin(), v.cend(), v.begin(), 0, 1);
    ASSERT_TRUE(v.empty());

    counting_sort(v.cbegin(), v.cend(), v.begin());
    ASSERT_TRUE(v.empty());

    counting_sort(v.begin(), v.end(), 0, 1);
    ASSERT_TRUE(v.empty());

    counting_sort(v.begin(), v.end());
    ASSERT_TRUE(v.empty());
}
