/*
Input:
 str1 = "abcde", str2 = "abfce"
Output:
 2
Explanation:
 The longest common substring is "ab", which has a length of 2.*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lcs(string str1, string str2)
    {
        int s1 = str1.size();
        int s2 = str2.size();
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
        for (int i = 0; i <= s1; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= s2; i++)
            dp[0][i] = 0;

        int ans = -1;
        for (int i = 1; i <= s1; i++)
        {
            for (int j = 1; j <= s2; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string str1 = "abc";
    string str2 = "abcd";
    cout << sol.lcs(str1, str2);
    return 0;
}