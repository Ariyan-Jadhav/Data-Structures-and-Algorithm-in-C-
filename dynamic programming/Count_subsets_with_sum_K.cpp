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
    int countK(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, target, nums, dp);
    }
};

int main()
{
    Solution sol;

    vector<int> vcc = {0, 0, 0, 0, 0, 0, 2};
    int target = 2;

    cout << sol.countK(vcc, target);

    return 0;
}