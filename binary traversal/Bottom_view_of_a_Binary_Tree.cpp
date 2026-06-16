// Problem Statement: Given a Binary Tree, return its Bottom View. The Bottom View of a Binary Tree is the set of nodes visible when we see the tree from the bottom.

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
        queue<tuple<TreeNode *, int, int>> q;
        map<int, pair<int, int>> mpp;

        q.push({root, 0, 0});

        while (!q.empty())
        {
            auto [curr, row, col] = q.front();
            q.pop();

            if (mpp.find(col) == mpp.end())
                mpp[col] = {row, curr->val};
            else if (mpp.find(col) != mpp.end() && mpp[col].first < row)
                mpp[col] = {row, curr->val};

            if (curr->left != nullptr)
                q.push({curr->left, row + 1, col - 1});

            if (curr->right != nullptr)
                q.push({curr->right, row + 1, col + 1});
        }

        vector<int> vcc;

        for (auto &[col, val] : mpp)
        {
            vcc.push_back(val.second);
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
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(10);
    root->right->left = new TreeNode(9);

    vector<int> ans = sol.topView(root);

    for (auto val : ans)
        cout << val << " ";

    return 0;
}