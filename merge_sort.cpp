#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void Merge(vector<int> &vcc, int low, int mid, int high)
{
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
}

void DivideAndMerge(vector<int> &vcc, int low, int high)
{
    if (low == high)
        return;

    int mid = (low + high) / 2;

    DivideAndMerge(vcc, low, mid);
    DivideAndMerge(vcc, mid + 1, high);

    Merge(vcc, low, mid, high);
}

int main()
{
    vector<int> unsorted_array = {
        45, -12, 78, 0, 23, 99, -45, 67, 12, 5,
        88, -3, 54, 32, 11, 76, 29, -90, 44, 61,
        3, 27, -15, 81, 100, -1, 39, 56, 72, 18,
        91, -22, 64, 7, 2, 83, 50, -7, 36, 95,
        14, 48, -60, 21, 66, 30, 8, 73, -5, 52,
        19, 41, -33, 87, 6, 25, 79, -2, 34, 58,
        93, 10, -11, 68, 24, 47, 1, 82, -44, 37,
        55, 13, 97, -8, 28, 63, 75, 4, -19, 85,
        9, 70, 20, -6, 31, 60, 89, 16, 53, -25,
        38, 71, 26, 84, -10, 92, 57, 15, 43, 69};

    DivideAndMerge(unsorted_array, 0, unsorted_array.size() - 1);

    for (auto val : unsorted_array)
        cout << val << " ";
}