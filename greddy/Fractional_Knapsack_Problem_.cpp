// Problem Statement: The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained is maximized.
// Note: We can either take the item as a whole or break it into smaller units.

#include <bits/stdc++.h>
using namespace std;

struct item
{
    int first;
    int second;
};

class Solution
{
public:
    double Knapsack(vector<int> val, vector<int> wt, int cap)
    {
        vector<item> vcc(val.size());

        for (int i = 0; i < vcc.size(); i++)
        {
            vcc[i].first = val[i];
            vcc[i].second = wt[i];
        }

        sort(vcc.begin(), vcc.end(), [](item a, item b)
             {
                 double r1 = (double)a.first / a.second;
                 double r2 = (double)b.first / b.second;
                 
                 return r1 > r2; });

        int index = 0;
        double count = 0;
        while (index < vcc.size() && cap != 0)
        {
            if (vcc[index].second <= cap)
            {
                count += vcc[index].first;
                cap -= vcc[index].second;
            }
            else if (index < vcc.size() && cap > 0)
            {
                double r1 = (double)vcc[index].first / vcc[index].second;
                count += r1 * cap;

                cap = 0;
            }
            index++;
        }

        return count;
    }
};

int main()
{
    Solution sol;

    vector<int> val;
    vector<int> wt;
    int cap;

    val = {10, 5};
    wt = {3, 2};
    cap = 4;

    Solution sp;

    cout << sp.Knapsack(val, wt, cap);

    return 0;
}