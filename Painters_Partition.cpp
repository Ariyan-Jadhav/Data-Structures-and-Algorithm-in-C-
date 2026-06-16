#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int painterPart(vector<int> &nums, int maxTime)
{
    int painters = 1;
    int current = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (current + nums[i] <= maxTime)
        {
            current += nums[i];
        }
        else
        {
            painters++;
            current = nums[i];
        }
    }

    return painters;
}

int binarySearch(vector<int> &nums, int m)
{
    int low = *max_element(nums.begin(), nums.end());
    int high = 0;
    int ans = -1;

    for (int i = 0; i < nums.size(); i++)
        high += nums[i];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int target = painterPart(nums, mid);

        if (target <= m)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {10, 20, 30, 40};
    int m = 2;

    cout << binarySearch(nums, m);
}