// Problem Statement: Given a target node data and a root of binary tree. If the target is set on fire, determine the shortest amount of time needed to burn the entire binary tree. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int burn(TreeNode *root, TreeNode *target)
    {
        queue<TreeNode *> q;
        unordered_map<int, TreeNode *> parent;
        q.push(root);

        while (!q.empty())
        {
            int level = q.size();

            for (int i = 0; i < level; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left)
                {
                    q.push(curr->left);
                    parent[curr->left->val] = curr;
                }
                if (curr->right)
                {
                    q.push(curr->right);
                    parent[curr->right->val] = curr;
                }
            }
        }

        unordered_set<int> visited;
        q.push(target);
        int count = -1;
        while (!q.empty())
        {
            int level = q.size();
            for (int i = 0; i < level; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                visited.insert(target->val);
                if (curr->left && visited.find(curr->left->val) == visited.end())
                    q.push(curr->left);

                if (curr->right && visited.find(curr->right->val) == visited.end())
                    q.push(curr->right);

                if (parent[curr->val] && visited.find(parent[curr->val]->val) == visited.end())
                    q.push(parent[curr->val]);
            }

            count++;
        }

        return count;
    }
};

int main()
{
    // Create the binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->right = new TreeNode(7);

    // Create solution object
    Solution sol;

    // Set target node to burn from
    TreeNode *target = root;

    // Print the minimum time to burn the tree
    cout << sol.burn(root, target) << endl;

    return 0;
}