// Problem Statement: You are given a set of N jobs where each job comes with a deadline and profit. The profit can only be earned upon completing the job within its deadline. Find the number of jobs done and the maximum profit that can be obtained. Each job takes a single unit of time and only one job can be performed at a time.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> Sequencing(vector<vector<int>> jobs, int N)
    {
        sort(jobs.begin(), jobs.end(), [](vector<int> &a, vector<int> &b)
             { return a[2] > b[2]; });

        vector<int> ans = {0, 0};
        for (int i = 0; i < jobs.size(); i++)
        {
            if (ans[0] < jobs[i][1])
            {
                ans[0]++;
                ans[1] += jobs[i][2];
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> jobs;
    int N;
    jobs = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};
    N = 5;

    vector<int> ans = sol.Sequencing(jobs, N);

    for (int val : ans)
        cout << val << " ";

    return 0;
}