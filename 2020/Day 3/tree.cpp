#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> grid;


int solveGivenSlope(int right, int down) {
    int counter = 0;
    int col = 0;
    int line;
    for (line = 0; line < grid.size(); line += down) {
        if (grid[line][col % grid[0].size()] == '#') {
            counter++;
        }
        col += right;
    }
    return counter;
}

int main() {
    ifstream inp("tree.in");
    string str;

    while (getline(inp, str)) {
        vector<char> v(str.begin(), str.end());

        grid.push_back(v);
    }

    cout << "Part 1 Answer: " << solveGivenSlope(3, 1) << endl;

    int total = solveGivenSlope(1, 1) * solveGivenSlope(3, 1) * solveGivenSlope(5, 1) *
                solveGivenSlope(7, 1) * solveGivenSlope(1, 2);
    cout << "Part 2 Answer: " << total << endl;
}