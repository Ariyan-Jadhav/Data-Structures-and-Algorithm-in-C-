#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, vector<int> &path_visit, vector<int> adj[], vector<int> &visited)
    {
        visited[node] = 1;
        path_visit[node] = 1;

        for (auto &prevNode : adj[node])
        {
            if (visited[prevNode] == 0)
            {
                if (dfs(prevNode, path_visit, adj, visited))
                    return true;
            }
            else if (path_visit[prevNode] == 1)
            {
                return true;
            }
        }

        path_visit[node] = 0;
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        vector<int> path_visit(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                visited[i] = 1;
                if (dfs(i, path_visit, adj, visited))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
    Solution obj;
    bool ans = obj.isCycle(11, adj);
    cout << ans;
    return 0;
}