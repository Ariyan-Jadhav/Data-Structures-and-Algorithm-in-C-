#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {10, 5, 2, 7, 1, 9};
    int k = 15;

    int left = 0, sum = 0, maxLen = 0;

    for (int right = 0; right < v.size(); right++)
    {
        sum += v[right];

        while (sum > k)
        {
            sum -= v[left];
            left++;
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
    }

    cout << maxLen;
}