// Problem Statement: Given a Binary Tree, return its Top View. The Top View of a Binary Tree is the set of nodes visible when we see the tree from the top.

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
    vector<int> topView(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        map<int, int> mpp;

        q.push({root, 0});

        while (!q.empty())
        {
            TreeNode *curr = q.front().first;
            int col = q.front().second;
            q.pop();

            if (mpp.find(col) == mpp.end())
                mpp[col] = curr->val;

            if (curr->left != nullptr)
                q.push({curr->left, col - 1});

            if (curr->right != nullptr)
                q.push({curr->right, col + 1});
        }

        vector<int> vcc;

        for (auto &[col, val] : mpp)
        {
            vcc.push_back(val);
        }

        return vcc;
    }
};

int main()
{
    Solution sol;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);

    vector<int> ans = sol.topView(root);

    for (auto val : ans)
        cout << val << " ";

    return 0;
}