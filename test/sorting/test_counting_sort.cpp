//
// Created by Andrew Bzikadze on 2018-10-02.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <fstream>
#include <vector>
#include <string>
#include <chrono>

#include "tests_filenames.hpp"
#include "sorting/counting_sort.hpp"

using algolib::sorting::tests_filenames;
using algolib::sorting::counting_sort;

TEST(TestCountingSort, GeneratedTests) {
    for (const auto &test_filename : tests_filenames) {
        std::ifstream in((std::string(test_filename)));
        std::vector<int> v;
        int val {0};
        while (in >> val) {
            v.emplace_back(val);
        }

        auto sv(v);
        std::sort(sv.begin(), sv.end());
        counting_sort(v.begin(), v.end());

        ASSERT_THAT(v, testing::ElementsAreArray(sv));
    }
}
