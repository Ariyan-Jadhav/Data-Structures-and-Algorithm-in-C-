// given a string s partition string s such that every substring of partition is palindrome. Return the minimum possible palindrome partition of string s.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool isPalindrome(int start, int end, string str)
{
    if (start == end)
        return true;

    while (start < end)
    {
        if (str[start] != str[end])
            return false;

        start++;
        end--;
    }

    return true;
}

int partition(int index, string &str)
{
    int n = str.length();
    int minCost = INT_MAX;
    if (index == n)
        return 0;

    for (int i = index; i < n; i++)
    {
        if (isPalindrome(index, i, str))
        {
            int cost = 1 + partition(i + 1, str);
            minCost = min(minCost, cost);
        }
    }

    return minCost;
}

int main()
{
    string str = "aabbcbbcabababbbaabbaba";
    cout << partition(0, str) - 1;
}