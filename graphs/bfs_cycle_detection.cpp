// Problem Statement: Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool cycleDetection(int V, vector<int> adj[], vector<int> &visited)
    {
        queue<pair<int, int>> q;
        visited[V] = 1;
        q.push({V, -1});

        while (!q.empty())
        {
            auto [node, prevNode] = q.front();
            q.pop();

            for (auto &val : adj[node])
            {
                if (visited[val] != 1)
                {
                    visited[val] = 1;
                    q.push({val, node});
                }
                else if (prevNode != val)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                if (cycleDetection(i, adj, visited))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> adj[4] = {
        {1, 2},    // 0
        {0, 2},    // 1
        {0, 1, 3}, // 2
        {2}        // 3
    };
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    cout << ans;
    return 0;
}