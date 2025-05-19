#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "common.h"

using namespace v;
template <typename T>

auto _unique(vector<T> &vec)
{
    auto it = partition(vec.begin(), vec.end(), [](int x)
                        { return x % 2 == 0; });
    return it;
}
template <typename T>

void print(const vector<T> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ",";
    }
    cout << endl;
}
template <typename T>

void Sort(vector<T> &vec)
{
    sort(vec.begin(), vec.end());
}
template <typename T>

void reverseSort(vector<T> &vec)
{
    sort(vec.rbegin(), vec.rend());
}
template <typename T>

void binarySearch(vector<T> &vec, const T &value)
{
    binary_search(vec.begin(), vec.end(), value) ? cout << "value " << value << " found" : cout << value << " not found";
    cout << endl;
}
template <typename T>

void Unique(vector<T> &vec)
{
    auto it1 = unique(vec.begin(), vec.end());
    vec.erase(it1, vec.end());
}
template <typename T>

vector<T> even(const vector<T> &vec)
{
    vector<int> even;

    for (auto i = vec.begin(); i != _unique(vec); i++)
    {
        even.push_back(*i);
    }
    return even;
}
template <typename T>

vector<T> odd(const vector<T> &vec)
{
    vector<int> odd;

    for (auto i = _unique(vec); i != vec.end(); i++)
    {
        odd.push_back(*i);
    }
    return odd;
}
template <typename T>

void emplaceBack( vector<T> &vec, const int &value)
{
    vec.emplace_back(value);
}
template <typename T>

void emplacePos( vector<T> &vec, int &pos, const int &value)
{
    vec.emplace(pos, value);
}
template <typename T>

bool isEmpty(const vector<T> &vec)
{
    return vec.empty();
}
template <typename T>

bool Size(const vector<T> &vec)
{
    return vec.size();
}
