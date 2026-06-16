// 1.123.2 (3c631b164c239e7aeaaae7c626b46c527b361af2)
#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        vector<int> adj[N];
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> distance(N, INT_MAX);

        distance[src] = 0;
        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (auto &val : adj[curr])
            {
                if (distance[curr] + 1 < distance[val])
                {
                    distance[val] = distance[curr] + 1;
                    q.push(val);
                }
            }
        }

        vector<int> ans;
        for (int val : distance)
        {
            if (val != INT_MAX)
                ans.push_back(val);
        }

        return ans;
    }
};

int main()
{
    int N = 9, M = 10;

    vector<vector<int>> edges = {
        {0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};

    Solution obj;

    vector<int> ans = obj.shortestPath(edges, N, M, 0);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}