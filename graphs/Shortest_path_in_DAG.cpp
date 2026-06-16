#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void dfs(vector<pair<int, int>> adj[], int node, stack<int> &stt, vector<int> &visit)
    {
        visit[node] = 1;
        for (auto &val : adj[node])
        {
            if (visit[val.first] == 0)
                dfs(adj, val.first, stt, visit);
        }

        stt.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];

        for (int i = 0; i < M; i++)
        {

            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];

            adj[u].push_back({v, d});
        }

        vector<int> visit(N, 0);
        stack<int> stt;

        // topo
        for (int i = 0; i < N; i++)
        {
            if (visit[i] != 1)
                dfs(adj, i, stt, visit);
        }

        vector<int> distance(N, INT_MAX);
        distance[0] = 0;

        while (!stt.empty())
        {
            int curr = stt.top();
            stt.pop();

            for (auto &val : adj[curr])
            {
                auto [u, dis] = val;

                if (distance[curr] + dis < distance[u])
                    distance[u] = distance[curr] + dis;
            }
        }

        return distance;
    }
};

int main()
{
    int N = 6, M = 7;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {4, 5, 4},
        {4, 2, 2},
        {1, 2, 3},
        {2, 3, 6},
        {5, 3, 1}};

    Solution obj;

    // Call shortestPath function
    vector<int> ans = obj.shortestPath(N, M, edges);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}