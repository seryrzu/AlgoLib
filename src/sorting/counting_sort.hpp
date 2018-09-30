//
// Created by Andrew Bzikadze on 2018-09-30.
//

#pragma once

#include <algorithm>
#include <vector>
#include <type_traits>


// TODO: clear counting_sort with internal construction
namespace algolib::sorting {

template <typename InputIt,
          typename OutputIt,
          typename T>
void counting_sort(InputIt begin,
                   InputIt end,
                   OutputIt obegin,
                   T minimum,
                   T maximum) {
    auto range = maximum - minimum + 1;
    auto container = std::vector<unsigned long long>(range);

    for (auto it = begin; it < end; it++) {
        auto element = *it - minimum;
        container[element]++;
    }

    for (size_t i = 0; i < container.size(); ++i) {
        auto quantity = container[i];
        for (size_t j = 0; j < quantity; ++j) {
            *obegin = i + minimum;
            obegin++;
        }
    }
}

template <typename MutableIt,
    typename T>
void counting_sort(MutableIt begin,
                   MutableIt end,
                   T minimum,
                   T maximum) {
    counting_sort(begin, end,
                  begin,
                  minimum, maximum);
}

template <typename InputIt,
    typename OutputIt>
void counting_sort(InputIt begin,
                   InputIt end,
                   OutputIt obegin) {
    if (begin == end) { return; }

    auto minimum = *std::min_element(begin, end);
    auto maximum = *std::max_element(begin, end);

    counting_sort(begin, end,
                  obegin,
                  minimum, maximum);
}

template <typename MutableIt>
void counting_sort(MutableIt begin,
                   MutableIt end) {
    counting_sort(begin, end, begin);
}

} // End namespace algolib::sorting
