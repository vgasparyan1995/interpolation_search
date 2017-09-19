#pragma once

#include <iterator>
#include <type_traits>

namespace Search {

template <typename RandomIt>
RandomIt interpolation_search(RandomIt from,
			                  RandomIt to,
			                  typename std::iterator_traits<RandomIt>::value_type const & value, 
                              typename std::enable_if<std::is_arithmetic<typename std::iterator_traits<RandomIt>::value_type>::value>::type* = nullptr)
{
    if (from == to) {
        return to;
    }
    const auto& first_value = *from;
    const auto& last_value = *(to - 1);
    if (value < first_value ||
        value > last_value) {
        return to;
    }
    if (first_value == last_value) {
        if (value == first_value) {
            return from;
        } else {
            return to;
        }
    }
    const auto length = std::distance(from, to);
    auto pivot_distance = length * (value - first_value) / (last_value - first_value);
    auto pivot_iter = from;
    std::advance(pivot_iter, pivot_distance);
    if (pivot_iter == from) {
        ++pivot_iter;
    }
    if (pivot_iter == to) {
        --pivot_iter;
    }
    const auto& pivot_value = *pivot_iter;
    RandomIt result;
    if (pivot_value == value) {
        result = pivot_iter;
    } else if (pivot_value < value) {
        result = interpolation_search(pivot_iter, to, value);
    } else /*if (tmpIterValue > value)*/ {
        result = interpolation_search(from, pivot_iter, value);
        if (result == pivot_iter) {
            result = to;
        }
    }
    return result;
}

} // namespace Search
