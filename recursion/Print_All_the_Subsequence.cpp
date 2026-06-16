// print all subsequences

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void printS(int index, int size, int arr[], vector<int> ans)
{

    if (index == size)
    {
        for (auto val : ans)

            cout << val << " ";

        cout << endl;
        return;
    }

    ans.push_back(arr[index]);
    printS(index + 1, size, arr, ans);
    ans.pop_back();
    printS(index + 1, size, arr, ans);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    vector<int> ans;
    printS(0, size, arr, ans);
}