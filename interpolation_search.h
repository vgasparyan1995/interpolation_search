#pragma once

template <typename RandomIt, typename T>
RandomIt interpolation_lower_bound(RandomIt from, RandomIt to, const T value)
{
    const auto distance = to - from;
    if (distance == 0) {
        return from;
    }
    const auto left_value = *from;
    if (value <= left_value) {
        return from;
    }
    const auto right_value = *(to - 1);
    if (value > right_value) {
        return to;
    }
    const auto pivot_iter = from + (distance - 1) * (value - left_value) / (right_value - left_value);
    const auto pivot_value = *pivot_iter;
    if (pivot_value < value) {
        return interpolation_lower_bound(pivot_iter + 1, to, value);
    }
    return interpolation_lower_bound(from, pivot_iter, value);
}

template <typename RandomIt, typename T>
RandomIt interpolation_upper_bound(RandomIt from, RandomIt to, const T value)
{
    const auto distance = to - from;
    if (distance == 0) {
        return from;
    }
    const auto left_value = *from;
    if (value < left_value) {
        return from;
    }
    const auto right_value = *(to - 1);
    if (value >= right_value) {
        return to;
    }
    const auto pivot_iter = from + (distance - 1) * (value - left_value) / (right_value - left_value);
    const auto pivot_value = *pivot_iter;
    if (pivot_value <= value) {
        return interpolation_upper_bound(pivot_iter + 1, to, value);
    }
    return interpolation_upper_bound(from, pivot_iter, value);
}
