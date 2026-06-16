// Problem Statement: There is one meeting room in a firm. You are given two arrays, start and end each of size N. For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i] will denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a particular time. Print the order in which these meetings will be performed.

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int start;
    int end;
};

class Solution
{
public:
    vector<int> n_meeting(vector<int> &start, vector<int> &end, int N)
    {
        vector<Item> vcc(N);
        for (int i = 0; i < N; i++)
        {
            vcc[i].start = start[i];
            vcc[i].end = end[i];
        }

        sort(vcc.begin(), vcc.end(), [](Item a, Item b)
             { return a.end < b.end; });

        vector<int> ans;
        ans.push_back(vcc[0].start);
        int last_end = vcc[0].end;

        for (auto val : vcc)
        {
            if (val.start > last_end)
            {
                ans.push_back(val.start);
                last_end = val.end;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> start;
    vector<int> end;

    start = {1, 2, 3, 4, 5, 6, 7};
    end = {100, 3, 4, 5, 6, 7, 8};

    vector<int> ans = sol.n_meeting(start, end, start.size());

    for (auto val : ans)
        cout << val << " ";

    return 0;
}