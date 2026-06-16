// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words otherwise return false. Note : The same word in dictionary can be used multiple times in segmentation

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool isValid(vector<string> wordDict, string temp)
{
    auto it = find(wordDict.begin(), wordDict.end(), temp);
    return it != wordDict.end() ? true : false;
}

bool word_break(string &str, vector<string> &wordDict, int index)
{

    if (index == str.length())
        return true;

    string temp;
    for (int i = index; i < str.size(); i++)
    {
        temp.push_back(str[i]);
        if (isValid(wordDict, temp))
        {
            if ((word_break(str, wordDict, i + 1)) == true)
                return true;
        }
    }
    return false;
}

int main()
{
    string str = "catsanddogs";
    vector<string> wordDict = {"cat", "and", "dogs"};
    string temp(str.length(), '_');
    cout << word_break(str, wordDict, 0);
}