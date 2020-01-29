#include <bits/stdc++.h>

using namespace std;

class Disjoint_Set
{
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;

public:
    Disjoint_Set(vector<int> vec)
    {
        for (const auto &c : vec)
        {
            parent[c] = c;
            rank[c] = 0;
        }
    }
    char Find(int s)
    {
        if (parent[s] == s)
            return s;
        return Find(parent[s]);
    }
    void Union(int s1, int s2)
    {
        int xset = Find(s1);
        int yset = Find(s2);
        if (rank[xset] > rank[yset])
        {
            parent[yset] = xset;
        }
        else if (rank[xset] < rank[yset])
        {
            parent[xset] = yset;
        }
        else
        {
            parent[yset] = xset;
            rank[xset]++;
        }
    }

    void print()
    {
        for (auto i : parent)
            cout << i.first << ": " << i.second << "\n";
    }
};

int main()
{
    Disjoint_Set js({0, 1, 2, 3, 4});
    js.Union(0,2);
    js.Union(4,2);
    js.Union(3,1);
    js.print();
    return 0;
}