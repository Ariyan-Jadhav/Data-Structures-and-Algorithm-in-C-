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
    void findTopView(TreeNode *root, map<int, int> &mpp, int row, int col)
    {
        if (root == nullptr)
            return;

        if (mpp.find(col) == mpp.end())
            mpp[col] = root->val;

        findTopView(root->left, mpp, row + 1, col - 1);
        findTopView(root->right, mpp, row + 1, col + 1);
    }

    vector<int> topView(TreeNode *root)
    {
        map<int, int> mpp;

        findTopView(root, mpp, 0, 0);

        vector<int> vcc;
        for (auto &[col, val] : mpp)
            vcc.push_back(val);

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