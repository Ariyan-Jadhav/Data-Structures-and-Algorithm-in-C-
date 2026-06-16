/* Example 1:
Input: matrix = [[10, 40, 70], [20, 50, 80], [30, 60, 90]]
Output: 210
Explanation:
Day 1: fighting practice = 70
Day 2: stealth training = 50
Day 3: fighting practice = 90
Total = 70 + 50 + 90 = 210
This gives the optimal points. */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
    {
        if (dp[day][last] != -1)
            return dp[day][last];

        if (day == 0)
        {
            int max_num = 0;
            for (int i = 0; i <= 2; i++)
            {
                if (i != last)
                    max_num = max(max_num, points[day][i]);
            }
            return dp[day][last] = max_num;
        }

        int max_num = 0;

        for (int i = 0; i <= 2; i++)
        {
            if (i != last)
            {
                int activity = points[day][i] + f(day - 1, i, points, dp);
                max_num = max(max_num, activity);
            }
        }
        return dp[day][last] = max_num;
    }

    int ninjaTraining(int n, vector<vector<int>> &points)
    {
        vector<vector<int>> dp(n, vector<int>(4, -1));

        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][1], points[0][0]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < n; day++)
        {
            for (int last = 0; last <= 3; last++)
            {
                dp[day][last] = 0;
                for (int i = 0; i <= 2; i++)
                {
                    if (i != last)
                    {
                        int activity = points[day][i] + dp[day - 1][i];
                        dp[day][last] = max(dp[day][last], activity);
                    }
                }
            }
        }
        return dp[n - 1][3];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points = {{10, 40, 70},
                                  {20, 50, 80},
                                  {30, 60, 90}};

    int n = points.size(); // Get the number of days
    // Call the ninjaTraining function to find the maximum points and print the result
    cout << sol.ninjaTraining(n, points);
    return 0;
}