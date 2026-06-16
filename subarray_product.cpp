#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
int main()
{
    vector<int> vcc = {1, 2, 3};
    for (int i = 0; i < vcc.size(); i++)
    {
        for (int j = i; j < vcc.size(); j++)
        {
            cout << " ";
            for (int k = i; k <= j; k++)
            {
                cout << vcc[k];
            }
        }
    }
}