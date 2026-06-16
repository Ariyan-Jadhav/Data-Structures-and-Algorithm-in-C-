#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
int main()
{
    vector<int> vcc = {1, 1, 5, 89, 5, 6, 6};
    int x = vcc[0];
    for (int i = 1; i < vcc.size(); i++)
        x ^= vcc[i];

    cout << x;
}