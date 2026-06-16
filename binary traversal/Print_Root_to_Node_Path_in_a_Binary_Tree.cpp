// Problem Statement: Given a Binary Tree and a reference to a root belonging to it. Return the path from the root node to the given leaf node.
// Note: No two nodes in the tree have the same data value and it is assured that the given node is present and a path always exists.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // here we will use preOrder traversal

    bool preOrderTraversal(TreeNode *root, int N, vector<int> &vcc)
    {
        if (root == nullptr)
            return false;

        vcc.push_back(root->val);

        if (root->val == N)
            return true;

        if ((preOrderTraversal(root->left, N, vcc)) || (preOrderTraversal(root->right, N, vcc)))
            return true;

        vcc.pop_back();
        return false;
    }

    vector<int> findThePath(TreeNode *root, int N)
    {
        vector<int> vcc;
        preOrderTraversal(root, N, vcc);
        return vcc;
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    int targetLeafValue = 7;

    vector<int> path = sol.findThePath(root, targetLeafValue);

    for (int i = 0; i < path.size(); ++i)
    {
        cout << path[i];
        if (i < path.size() - 1)
        {
            cout << " -> ";
        }
    }

    return 0;
}