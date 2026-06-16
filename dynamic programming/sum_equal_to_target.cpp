#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findSum(vector<int> &arr, int target, int ind, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (ind == 0)
            return (arr[0] == target);

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool notTake = findSum(arr, target, ind - 1, dp);

        bool take = false;
        if (arr[ind] <= target)
            take = findSum(arr, target - arr[ind], ind - 1, dp);

        return dp[ind][target] = notTake | take;
    }

    bool subsetSumToK(int k, vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<bool>> dp(arr.size(), vector<bool>(k + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        dp[0][arr[0]] = true;

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= k; target++)
            {
                bool notTake = dp[ind - 1][target];

                bool take = false;
                if (arr[ind] <= target)
                    take = dp[ind - 1][target - arr[ind]];

                dp[ind][target] = notTake || take;
            }
        }
        return dp[n - 1][k];
    }
};

int main()
{
    Solution sol;

    vector<int> vcc = {1, 2, 3, 4, 5, 6, 2};
    int target = 111;

    cout << sol.subsetSumToK(target, vcc);

    return 0;
}