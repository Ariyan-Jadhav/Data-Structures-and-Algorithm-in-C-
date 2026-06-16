// Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
int main()
{
    long long num;
    cin >> num;

    long long low = 0;
    long long high = num;
    long long mid;
    while ((high - low) >= 0)
    {
        mid = low + (high - low) / 2;
        if (mid <= num / mid)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << high;
}