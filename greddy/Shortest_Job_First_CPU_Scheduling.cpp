// Problem Statement: Given a list of job durations representing the time it takes to complete each job. Implement the Shortest Job First algorithm to find the average waiting time for these jobs.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int SJF(vector<int> jobs)
    {

        sort(jobs.begin(), jobs.end());

        int time = 0;
        int wait = 0;

        for (int i = 0; i < jobs.size(); i++)
        {
            wait += time;
            time += jobs[i];
        }

        return wait / jobs.size();
    }
};

int main()
{
    Solution sol;

    vector<int> jobs;
    jobs = {4, 3, 7, 1, 2};

    cout << sol.SJF(jobs);

    return 0;
}