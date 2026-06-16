// Problem Statement: We are given two arrays that represent the arrival and departure times of trains that stop at the platform. We need to find the minimum number of platforms needed at the railway station so that no train has to wait.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int railway(vector<int> &start, vector<int> &end)
    {
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int up = 0;
        int down = 0;

        int min_platform = 0;
        int count = 0;
        int n = end.size();
        while (up < n)
        {
            if (start[up] < end[down])
            {
                up++;
                count++;
                min_platform = max(min_platform, count);
            }
            else
            {
                down++;
                count--;
            }
        }

        return min_platform;
    }
};

int main()
{
    Solution sol;
    vector<int> start;
    vector<int> end;

    start = {900, 940, 950, 1100, 1500, 1800};
    end = {910, 1200, 1120, 1130, 1900, 2000};

    cout << sol.railway(start, end);

    return 0;
}