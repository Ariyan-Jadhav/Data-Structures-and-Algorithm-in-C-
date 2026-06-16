
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool printS(int index, int sum, int calculated_sum, int size, int arr[], vector<int> ans)
{

    if (index == size)
    {

        if (sum == calculated_sum)
        {
            for (auto val : ans)
                cout << val << " ";

            cout << endl;

            return true;
        }

        return false;
    }

    calculated_sum += arr[index];
    ans.push_back(arr[index]);

    if (printS(index + 1, sum, calculated_sum, size, arr, ans) == true)
        return true;

    calculated_sum -= arr[index];
    ans.pop_back();

    if (printS(index + 1, sum, calculated_sum, size, arr, ans) == true)
        return true;

    return false;
}

int main()
{
    int arr[] = {1, 2, 1};
    int size = 3;
    int sum = 2;
    vector<int> ans;
    printS(0, sum, 0, size, arr, ans);
}