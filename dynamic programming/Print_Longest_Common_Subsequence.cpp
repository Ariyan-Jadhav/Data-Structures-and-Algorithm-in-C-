/* Example 1:
Input:
 str1 = "bdefg", str2 = "bfg"
Output:
 bfg
Explanation:
 The longest common subsequence is "bfg", which has a length of 3. */

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    string lcs(string str1, string str2)
    {
        int s1 = str1.size();
        int s2 = str2.size();
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, -1));

        for (int i = 0; i <= s1; i++)
            dp[i][0] = 0;

        for (int i = 0; i <= s2; i++)
            dp[0][i] = 0;

        for (int id1 = 1; id1 <= s1; id1++)
        {
            for (int id2 = 1; id2 <= s2; id2++)
            {
                if (str1[id1 - 1] == str2[id2 - 1])
                    dp[id1][id2] = 1 + dp[id1 - 1][id2 - 1];
                else
                    dp[id1][id2] = max(dp[id1 - 1][id2], dp[id1][id2 - 1]);
            }
        }
        int len = dp[s1][s2];
        string s(len, '$');
        int ind = len - 1;
        int i = s1;
        int j = s2;

        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                s[ind] = str1[i - 1];
                i--;
                j--;
                ind--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }

        return s;
    }
};

int main()
{
    Solution sol;
    string str1 = "abs";
    string str2 = "abvd";
    cout << sol.lcs(str1, str2);
    return 0;
}