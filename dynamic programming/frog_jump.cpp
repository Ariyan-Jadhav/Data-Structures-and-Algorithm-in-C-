#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculateHeight(int ind, vector<int> &nums, vector<int> &dp)
    {
        if (ind == 0)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int left = calculateHeight(ind - 1, nums, dp) + abs(nums[ind] - nums[ind - 1]);
        int right = INT_MAX;

        if (ind > 1)
            right = calculateHeight(ind - 2, nums, dp) + abs(nums[ind] - nums[ind - 2]);

        return dp[ind] = min(left, right);
    }

    int frogJump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;

        // 0     - 1     - 2    - 3     - 4
        // prev1 - prev2 - curr
        int prev1 = 0;
        int prev2 = abs(nums[1] - nums[0]);

        for (int i = 2; i < n; i++)
        {
            int left = prev2 + abs(nums[i] - nums[i - 1]);
            int right = prev1 + abs(nums[i - 2] - nums[i]);

            int curr = min(left, right);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main()
{
    Solution sol;

    vector<int> nums;

    for (int i = 0; i < 3; i++)
    {
        nums.push_back(i * 100000);
    }

    cout << sol.frogJump(nums) << endl;

    return 0;
}