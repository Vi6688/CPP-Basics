#include <map>
#include <unordered_map>

template <typename A, typename B>

struct compareAsc
{
    bool operator()(A a, B b) const
    {
        return b > a;
    }
};
template <typename A, typename B>

struct compareDes
{
    bool operator()(A a, B b) const
    {
        return a > b;
    }
};
