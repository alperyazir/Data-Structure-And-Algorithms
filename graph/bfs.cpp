#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    // vector of vertex to vertices
    vector<vector<int>> adj;

public:
    Graph()
    {
    }
    void add_edge(int s, vector<int> d)
    {
        adj.push_back(d);
    }
    void BFS(int v)
    {
        vector<bool> *visited = new vector<bool>(adj.size());

        queue<int> que;
        que.push(v);
        visited->at(v) = true;

        while (!que.empty())
        {
            int temp = que.front();
            cout << temp << " ";
            que.pop();

            for (auto &i : adj.at(temp))
            {
                if (!visited->at(i))
                {
                    visited->at(i) = true;
                    que.push(i);
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.add_edge(0, {1});
    g.add_edge(1, {1, 2, 3});
    g.add_edge(2, {1, 4});
    g.add_edge(3, {1, 4, 5});
    g.add_edge(4, {2, 3, 5});
    g.add_edge(5, {3, 4, 5});

    g.BFS(2);
    return 0;
}