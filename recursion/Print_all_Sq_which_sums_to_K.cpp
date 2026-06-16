
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void printS(int index, int sum, int calculated_sum, int size, int arr[], vector<int> ans)
{

    if (index == size)
    {

        if (sum == calculated_sum)
        {
            for (auto val : ans)
                cout << val << " ";

            cout << endl;
        }

        return;
    }

    calculated_sum += arr[index];
    ans.push_back(arr[index]);
    printS(index + 1, sum, calculated_sum, size, arr, ans);

    calculated_sum -= arr[index];
    ans.pop_back();
    printS(index + 1, sum, calculated_sum, size, arr, ans);
}

int main()
{
    int arr[] = {2, 3, 6, 7};
    int size = 4;
    int sum = 7;
    vector<int> ans;
    printS(0, sum, 0, size, arr, ans);
}