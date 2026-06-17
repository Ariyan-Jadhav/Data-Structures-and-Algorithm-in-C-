#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int f(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (target == 0 && nums[0] == 0)
                return 2;

            if (target == 0 || target == nums[0])
                return 1;

            return 0;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notTake = f(ind - 1, target, nums, dp);

        int take = 0;
        if (nums[ind] <= target)
            take = f(ind - 1, target - nums[ind], nums, dp);

        return dp[ind][target] = notTake + take;
    }

public:
    int countK(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        if (nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (nums[0] != 0 && nums[0] <= k)
            dp[0][nums[0]] = 1;

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= k; target++)
            {
                int notTake = dp[ind - 1][target];

                int take = false;
                if (nums[ind] <= target)
                    take = dp[ind - 1][target - nums[ind]];

                dp[ind][target] = notTake + take;
            }
        }
        return dp[n - 1][k];
    }
};

int main()
{
    Solution sol;

    vector<int> vcc = {0, 0, 2};
    int target = 2;

    cout << sol.countK(vcc, target);

    return 0;
}