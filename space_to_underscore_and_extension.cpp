#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
int main()
{
    string s;
    cout << "Enter the title : ";
    getline(cin, s);
    cout << endl;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            s[i] = '_';
    }

    s = s + ".cpp";

    cout << s;
}
