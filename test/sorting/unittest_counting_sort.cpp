//
// Created by Alexander Bzikadze on 30.09.2018.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <array>
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


TEST(TestCountingSort, SmallVectorSorted) {
    std::vector<int> v {1, 2, 3, 4, 5};
    counting_sort(v.cbegin(), v.cend(), v.begin(), 1, 5);
    ASSERT_THAT(v, testing::ElementsAre(1, 2, 3, 4, 5));

    counting_sort(v.cbegin(), v.cend(), v.begin());
    ASSERT_THAT(v, testing::ElementsAre(1, 2, 3, 4, 5));

    counting_sort(v.begin(), v.end(), 1, 5);
    ASSERT_THAT(v, testing::ElementsAre(1, 2, 3, 4, 5));

    counting_sort(v.begin(), v.end());
    ASSERT_THAT(v, testing::ElementsAre(1, 2, 3, 4, 5));
}


TEST(TestCountingSort, SmallVectorUnsorted) {
    std::vector<int> sorted{1, 2, 3, 4, 5};
    std::vector<int> unsorted{5, 4, 3, 2, 1};
    {
        std::vector<int> v(unsorted);
        counting_sort(v.cbegin(), v.cend(), v.begin(), 1, 5);
        ASSERT_THAT(v, testing::ElementsAreArray(sorted));
    }

    {
        std::vector<int> v(unsorted);
        counting_sort(v.cbegin(), v.cend(), v.begin());
        ASSERT_THAT(v, testing::ElementsAreArray(sorted));
    }

    {
        std::vector<int> v(unsorted);
        counting_sort(v.begin(), v.end(), 1, 5);
        ASSERT_THAT(v, testing::ElementsAreArray(sorted));
    }

    {
        std::vector<int> v(unsorted);
        counting_sort(v.begin(), v.end());
        ASSERT_THAT(v, testing::ElementsAreArray(sorted));
    }
}


TEST(TestCountingSort, SmallArrayUnsorted) {
    std::array<int, 5> sorted{1, 2, 3, 4, 5};
    std::array<int, 5> unsorted{5, 4, 3, 2, 1};
    {
        std::array<int, 5> v(unsorted);
        counting_sort(v.cbegin(), v.cend(), v.begin(), 1, 5);
        ASSERT_THAT(v, testing::ElementsAreArray(sorted));
    }

    {
        std::array<int, 5> v(unsorted);
        counting_sort(v.cbegin(), v.cend(), v.begin());
        ASSERT_THAT(v, testing::ElementsAreArray(sorted));
    }

    {
        std::array<int, 5> v(unsorted);
        counting_sort(v.begin(), v.end(), 1, 5);
        ASSERT_THAT(v, testing::ElementsAreArray(sorted));
    }

    {
        std::array<int, 5> v(unsorted);
        counting_sort(v.begin(), v.end());
        ASSERT_THAT(v, testing::ElementsAreArray(sorted));
    }
}


TEST(TestCountingSort, SmallCArrayUnsorted) {
    int sorted[] {1, 2, 3, 4, 5};
    int unsorted[] {5, 4, 3, 2, 1};
    {
        int v[] {5, 4, 3, 2, 1};
        counting_sort(v, v + 5, v, 1, 5);
        ASSERT_THAT(v, testing::ElementsAreArray(sorted));
    }

    {
        int v[] {5, 4, 3, 2, 1};
        counting_sort(v, v + 5, v, 1, 5);
        ASSERT_THAT(v, testing::ElementsAreArray(sorted));
    }

    {
        int v[] {5, 4, 3, 2, 1};
        counting_sort(v, v + 5, v, 1, 5);
        ASSERT_THAT(v, testing::ElementsAreArray(sorted));
    }

    {
        int v[] {5, 4, 3, 2, 1};
        counting_sort(v, v + 5, v, 1, 5);
        ASSERT_THAT(v, testing::ElementsAreArray(sorted));
    }
}


TEST(TestCountingSort, SmallString) {
    std::string unsorted { "sssstring" };
    std::string sorted   { "ginrsssst" };
    {
        std::string v(unsorted);
        counting_sort(v.cbegin(), v.cend(), v.begin());
        ASSERT_THAT(v, testing::ElementsAreArray(sorted));
    }

    {
        std::string v(unsorted);
        counting_sort(v.begin(), v.end());
        ASSERT_THAT(v, testing::ElementsAreArray(sorted));
    }
}


TEST(TestCountingSort, SmallCString) {
    char sorted[]   { "ginrsssst" };
    {
        char v[] { "sssstring" };
        counting_sort(v, v + strlen(v), v);
        ASSERT_THAT(v, testing::ElementsAreArray(sorted));
    }

    {
        char v[] { "sssstring" };
        counting_sort(v, v + strlen(v), v);
        ASSERT_THAT(v, testing::ElementsAreArray(sorted));
    }
}