#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adj[], stack<int> &stt, int vis[])
    {
        for (auto &val : adj[node])
        {
            if (!vis[val])
            {
                vis[val] = 1;
                dfs(val, adj, stt, vis);
            }
        }
        stt.push(node);
        return;
    }

public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        stack<int> stt;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                dfs(i, adj, stt, vis);
            }
        }

        vector<int> ans;

        while (!stt.empty())
        {
            ans.push_back(stt.top());
            stt.pop();
        }
        return ans;
    }
};

int main()
{
    int V = 6, E = 6;

    vector<int> adj[V];
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;

    vector<int> res = obj.topoSort(V, adj);

    cout << "Topological Sort: ";
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}