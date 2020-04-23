#include <iostream>
using namespace std;

#ifndef C___LABS_4__5__6__GENERALIZED_ALGORITHMS_H
#define C___LABS_4__5__6__GENERALIZED_ALGORITHMS_H

bool predicate_all_of(int x)
{
    return x > -228;
}


bool sorting_criteria(int x, int y)
{
    return x < y - 1;
}

template <typename iterator, typename object>
bool all_of(iterator begin, iterator end, bool (&predict)(object))
{
    for (auto i = begin; i != end; i++)
    {
        if (predict(*i))
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

template <typename iterator, typename object>
bool is_sorted(iterator begin, iterator end, bool (&criterion)(object, object))
{
    for (auto i = begin; i != end - 1; i = next(i))
    {
        auto y = next(i);
        if (criterion(*i, *y))
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

template <typename iterator>
int find_backward(iterator begin, iterator end, int find)
{
    for (auto i = end; i != begin - 1; --i)
    {
        if (*i == find)
        {
            return i - begin;
        }
        else
        {
            continue;
        }
    }

    return -1;
}
#endif //C___LABS_4__5__6__GENERALIZED_ALGORITHMS_H