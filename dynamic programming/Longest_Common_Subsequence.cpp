/* Example 1:
Input:
 str1 = "bdefg", str2 = "bfg"
Output:
 3
Explanation:
 The longest common subsequence is "bfg", which has a length of 3. */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
protected:
    int f(int id1, int id2, string str1, string str2, vector<vector<int>> &dp)
    {
        if (dp[id1][id2] != -1)
            return dp[id1][id2];

        if (id1 == 0 || id2 == 0)
            return dp[id1][id2] = 0;

        if (str1[id1 - 1] == str2[id2 - 1])
            return dp[id1][id2] = 1 + f(id1 - 1, id2 - 1, str1, str2, dp);

        return dp[id1][id2] = max(f(id1 - 1, id2, str1, str2, dp), f(id1, id2 - 1, str1, str2, dp));
    }

public:
    int lcs(string str1, string str2)
    {
        int s1 = str1.size();
        int s2 = str2.size();
        vector<int> prev(s2 + 1, 0), curr(s2 + 1, 0);

        for (int id1 = 1; id1 <= s1; id1++)
        {

            curr[0] = 0;

            for (int id2 = 1; id2 <= s2; id2++)
            {
                if (str1[id1 - 1] == str2[id2 - 1])
                    curr[id2] = 1 + prev[id2 - 1];
                else
                    curr[id2] = max(prev[id2], curr[id2 - 1]);
            }
            prev = curr;
        }
        return prev[s2];
    }
};

int main()
{
    Solution sol;
    string str1 = "abcdefgqwertyuiopasdfghjklqwertyuiop";
    string str2 = "abcfgmnbvcxzasdfghjklqwertyuiopasdfghjklqwertyuiop";
    cout << sol.lcs(str1, str2);
    return 0;
}