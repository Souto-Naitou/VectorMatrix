#pragma once

template <class T>
class Range
{
public:
    Range() : start(), end() {}
    explicit Range(T start, T end) : start(start), end(end) {}

    T start;
    T end;
};