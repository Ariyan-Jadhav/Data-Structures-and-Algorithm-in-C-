#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topo(int V, vector<int> adj[])
    {
        int indegree[V] = {0};

        for (int i = 0; i < V; i++)
        {
            for (auto val : adj[i])
            {
                indegree[val]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for (auto node : adj[curr])
            {
                indegree[node]--;
                if (indegree[node] == 0)
                    q.push(node);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    int V = 6;
    vector<int> adj[V];

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topoOrder = sol.topo(V, adj);

    cout << "Topological Order: ";
    for (int node : topoOrder)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}