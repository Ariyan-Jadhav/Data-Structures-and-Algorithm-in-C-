// Problem Statement: Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order. A binary string is a string consisting only of characters '0' and '1'.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool isValid(string s)
{
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == '1' && s[i + 1] == '1')
            return false;
    }

    return true;
}

void binary_string(vector<string> &vcc, string s, int n)
{
    if (s.length() == n)
    {
        if (isValid(s))
            vcc.push_back(s);
        return;
    }

    binary_string(vcc, s += '0', n);
    s.pop_back();
    binary_string(vcc, s += '1', n);
    s.pop_back();
}

int main()
{
    vector<string> vcc;
    int n = 1;
    binary_string(vcc, "", n);

    for (int i = 0; i < vcc.size(); i++)
        cout << vcc[i] << " ";
}