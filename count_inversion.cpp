#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int Merge(vector<int> &vcc, int low, int mid, int high)
{
    int cnt = 0;
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (vcc[left] <= vcc[right])
        {
            temp.push_back(vcc[left]);
            left++;
        }
        else
        {
            temp.push_back(vcc[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(vcc[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(vcc[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
        vcc[i] = temp[i - low];

    return cnt;
}

int DivideAndMerge(vector<int> &vcc, int low, int high)
{
    int cnt = 0;
    if (low == high)
        return cnt;
    int mid = (low + high) / 2;

    cnt += DivideAndMerge(vcc, low, mid);
    cnt += DivideAndMerge(vcc, mid + 1, high);
    cnt += Merge(vcc, low, mid, high);

    return cnt;
}

int main()
{
    vector<int> unsorted_array = {2, 1};

    int x = DivideAndMerge(unsorted_array, 0, unsorted_array.size() - 1);

    cout << x;
}