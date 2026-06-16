// Problem Description : Given a string, find all the possible subsequences of the string.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string convert_sub(string s, string og_str)
{
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            temp.push_back(og_str[i]);
    }

    return temp;
}

void binary_string(vector<string> &vcc, string s, string og_str)
{
    if (s.length() == og_str.length())
    {
        vcc.push_back(convert_sub(s, og_str));
        return;
    }

    binary_string(vcc, s += '1', og_str);
    s.pop_back();
    binary_string(vcc, s += '0', og_str);
    s.pop_back();
}

int main()
{
    vector<string> vcc;
    string s = "abcde";
    binary_string(vcc, "", s);
    for (int i = 0; i < vcc.size(); i++)
        cout << vcc[i] << " ";
}