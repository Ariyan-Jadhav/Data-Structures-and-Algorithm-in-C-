#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(V, INT_MAX);
        distance[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            auto [dis, node] = pq.top();
            pq.pop();

            for (auto val : adj[node])
            {
                int adjNode = val[0];
                int edgeW = val[1];

                if (edgeW + dis < distance[adjNode])
                {
                    distance[adjNode] = edgeW + dis;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }
        return distance;
    }
};

int main()
{
    Solution sol;

    int V = 5;
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({4, 1});

    int source = 0;

    vector<int> ans = sol.dijkstra(V, adj, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << "Node " << i << " -> " << ans[i] << '\n';
    }

    return 0;
}