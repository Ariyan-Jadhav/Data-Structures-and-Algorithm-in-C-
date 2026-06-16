// // Problem Statement: There is only one row of fruit trees on the farm, oriented left to right. An integer array called fruits represents the trees, where fruits[i] denotes the kind of fruit produced by the ith tree.
// The goal is to gather as much fruit as possible, adhering to the owner's stringent rules :
// There are two baskets available, and each basket can only contain one kind of fruit. The quantity of fruit each basket can contain is unlimited.
// Start at any tree, but as you proceed to the right, select exactly one fruit from each tree, including the starting tree. One of the baskets must hold the harvested fruits.
// Once reaching a tree with fruit that cannot fit into any basket, stop.
// Return the maximum number of fruits that can be picked.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        unordered_map<int, int> mpp;
        int left = 0;
        int right = 0;
        int ans = 0;

        for (int i = 0; i < fruits.size(); i++)
        {
            mpp[fruits[i]]++;

            if (mpp.size() <= 2)
            {
                ans = max(right - left + 1, ans);
            }
            else
            {
                mpp[fruits[left]]--;
                if (mpp[fruits[left]] <= 0)
                    mpp.erase(fruits[left]);
                left++;
            }
            right++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> fruits = {1, 2, 3, 2, 2};
    cout << sol.totalFruit(fruits);

    return 0;
}