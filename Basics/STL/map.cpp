#include <iostream>
#include "Map.h"

using namespace std;
template <typename A, typename B>
void print(map<A,B> map1)
{
    for (const auto &pair : map1)
    {
        cout << pair.first << " : " << pair.second << endl;
    }
}
template <typename A, typename B>
void print1(unordered_map<A,B> map1)
{
    for (const auto &pair : map1)
    {
        cout << pair.first << " : " << pair.second << endl;
    }
}
int main()
{

    unordered_map<string, int> map2;
    string text = "this is a test this is only a test";
    string word;
    for (size_t i = 0; i <= text.size(); i++)
    {
        if (i == text.size() || text[i] == ' ')
        {
            if (!word.empty())
            {
                map2[word]++;
                word.clear();
            }
        }
        else
        {
            word += text[i];
        }
    }
    print1(map2);
    map<int, string> map1;
    map1[0] = "zero";
    map1[1] = "one";
    map1[2] = "two";
    map1[3] = "three";

    map1.insert(make_pair(4, "four"));
    map1.insert({5, "five"});
    map1[6] = "six";
    map1[7] = "seven";

    if (map1.find(6) != map1.end())
    {
        cout << "Number four exists" << endl;
    }
    else
    {
        cout << "Number does doesnt exist" << endl;
    }
    // cout<<map1[4]<<endl;
    // cout<<map1.at(4)<<endl;
}
