// print the shortest path

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int n, int m, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[n + 1];

        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int dist = e[2];

            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});

        vector<int> distance(n + 1, INT_MAX);
        distance[1] = 0;

        vector<int> prv(n + 1);
        for (int i = 0; i < prv.size(); i++)
            prv[i] = i;

        while (!pq.empty())
        {
            auto [dis, node] = pq.top();
            pq.pop();

            if (dis > distance[node])
                continue;

            for (auto &val : adj[node])
            {
                int adjNode = val.first;
                int edgeW = val.second;

                if (edgeW + dis < distance[adjNode])
                {
                    distance[adjNode] = edgeW + dis;
                    prv[adjNode] = node;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }

        vector<int> ans;
        int node = n;
        while (prv[node] != node)
        {
            ans.push_back(node);
            node = prv[node];
        }

        ans.push_back(1);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    Solution sol;

    int n = 5;
    int m = 6;

    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 4, 1},
        {2, 3, 4},
        {2, 5, 5},
        {4, 3, 3},
        {3, 5, 1}};

    vector<int> path = sol.dijkstra(n, m, edges);

    cout << "Shortest Path: ";
    for (int node : path)
    {
        cout << node << " ";
    }
    cout << '\n';

    return 0;
}