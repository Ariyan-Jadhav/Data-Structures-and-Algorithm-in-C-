#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<int> visited(V, 0);
        pq.push({0, 0, -1});

        vector<vector<int>> ans;
        int sum = 0;
        while (!pq.empty())
        {
            auto [dist, node, prev] = pq.top();
            pq.pop();

            if (visited[node] == 1)
                continue;

            sum += dist;
            if (prev != -1)
                ans.push_back({prev, node});
            visited[node] = 1;

            for (auto val : adj[node])
            {
                int u = val[0];
                int d = val[1];

                if (visited[u] == 0)
                    pq.push({d, u, node});
            }
        }
        return ans;
    }
};

int main()
{

    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}};
    vector<vector<int>> adj[V];
    for (auto it : edges)
    {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    Solution obj;
    vector<vector<int>> ans = obj.spanningTree(V, adj);

    sort(ans.begin(), ans.end());
    for (auto &e : ans)
        cout << "(" << e[0] << ", " << e[1] << ") ";

    return 0;
}