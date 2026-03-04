#pragma once

template <class T>
struct Range
{
public:
    constexpr Range() : start(), end() {}
    constexpr Range(T start, T end) : start(start), end(end) {}
    constexpr inline bool Contains(const T& value) const
    {
        return value >= start && value <= end;
    }

    T start;
    T end;
};