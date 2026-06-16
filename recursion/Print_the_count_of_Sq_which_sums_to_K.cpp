
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int printS(int index, int sum, int calculated_sum, int size, int arr[])
{

    if (index == size)
    {

        if (sum == calculated_sum)
        {
            return 1;
        }

        return 0;
    }

    calculated_sum += arr[index];
    int left = printS(index + 1, sum, calculated_sum, size, arr);

    calculated_sum -= arr[index];
    int right = printS(index + 1, sum, calculated_sum, size, arr);

    return left + right;
}

int main()
{
    int arr[] = {1, 2, 1};
    int size = 3;
    int sum = 2;
    cout << printS(0, sum, 0, size, arr);
}