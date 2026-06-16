#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, int parent, vector<int> adj[], vector<int> &visited)
    {
        visited[node] = 1;
        for (auto &prevNode : adj[node])
        {
            if (visited[prevNode] == 0)
            {
                if (dfs(prevNode, node, adj, visited))
                    return true;
            }
            else if (prevNode != parent)
            {
                return true;
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
                visited[i] = 1;
                if (dfs(i, -1, adj, visited))
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