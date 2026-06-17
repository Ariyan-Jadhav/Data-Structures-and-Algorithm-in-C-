#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int f(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (nums[0] == 0 && target == 0)
                return 2;
            if (target == nums[0] || target == 0)
                return 1;

            return 0;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notTake = f(ind - 1, target, nums, dp);

        int take = 0;
        if (nums[ind] <= target)
            take = f(ind - 1, target - nums[ind], nums, dp);

        return dp[ind][target] = take + notTake;
    }

public:
    int partitions(vector<int> &nums, int diff)
    {
        int n = nums.size();
        int total = 0;

        for (int i = 0; i < n; i++)
            total += nums[i];

        // conditions
        if ((diff > total) || ((total - diff) % 2 == 1))
            return 0;

        int target = (total - diff) / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, target, nums, dp);
    }
};

int main()
{
    Solution sol;

    vector<int> vcc;
    int diff;

    vcc = {1, 1, 2, 3, 4, 5, 5, 3, 3, 2, 3};
    diff = 12;

    cout << sol.partitions(vcc, diff);

    return 0;
}