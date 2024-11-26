#include <iostream>
#include <list>

using namespace std;

void printList(const list<int> &value)
{
    for(auto n=value.begin();n!=value.end();n++)
    {
        cout<<*n<<",";
    }
    cout<<endl;
}
void insertIntoOrderedLisT(int &rating, list<int> &players)
{
    for(list<int>::iterator it=players.begin();it!=players.end();it++)
    {
        if(*it>rating)
        {
            players.insert(it,rating);
            return;
        }
    }
    players.push_back(rating);
}
int main()
{
    list<int> allPlayers = {2, 4, 5, 6, 8, 9, 3, 7, 1, 3}, pros, begginers;

    for (auto it = allPlayers.begin(); it != allPlayers.end(); it++)
    {
        if (*it >= 1 && *it <= 5)
        {
            insertIntoOrderedLisT(*it,begginers);
        }
        else
        {
            insertIntoOrderedLisT(*it, pros);
        }
    }
    list<int> name(5,15);
    auto it = name.begin();
    advance(it,2);
    name.insert(it ,15);    
    printList(name);
    printList(begginers);
    printList(pros);

    return 0;
}