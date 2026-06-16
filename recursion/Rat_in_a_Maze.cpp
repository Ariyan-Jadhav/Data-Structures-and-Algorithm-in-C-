// Problem Statement: Given a grid of dimensions n x n. A rat is placed at coordinates (0, 0) and wants to reach at coordinates (n-1, n-1). Find all possible paths that rat can take to travel from (0, 0) to (n-1, n-1). The directions in which rat can move are 'U' (up) , 'D' (down) , 'L' (left) , 'R' (right). The value 0 in grid denotes that the cell is blocked and rat cannot use that cell for travelling, whereas value 1 represents that rat can travel through the cell. If the cell (0, 0) has 0 value, then mouse cannot move to any other cell.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void maze(vector<vector<int>> &grid, vector<string> &temp, string &str, int row, int col, int n)
{
    if (row == n - 1 && col == n - 1)
    {
        temp.push_back(str);
        return;
    }

    if ((row < 0 || col < 0 || row >= n || col >= n) || (grid[row][col] == 0 || grid[row][col] == 2))
        return;

    grid[row][col] = 2;

    str.push_back('D');
    maze(grid, temp, str, row + 1, col, n);
    str.pop_back();

    str.push_back('U');
    maze(grid, temp, str, row - 1, col, n);
    str.pop_back();

    str.push_back('R');
    maze(grid, temp, str, row, col + 1, n);
    str.pop_back();

    str.push_back('L');
    maze(grid, temp, str, row, col - 1, n);
    str.pop_back();

    grid[row][col] = 1;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 1, 0, 1, 1, 1, 1, 1},
        {0, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 0, 1, 1, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1}};

    int n = 9;
    vector<string> temp;
    string str;
    maze(grid, temp, str, 0, 0, n);

    for (auto it : temp)
    {
        cout << it << endl;
    }
}