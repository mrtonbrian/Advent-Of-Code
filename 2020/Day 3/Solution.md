# Solution
## Part 1
The key to this problem is the function
```c++
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
```
The most important observation is that using modular arithmetic, we find that the column of the original grid that a given column `col` is `col % gridWidth`.

Puzzle Answer: `225`

## Part 2
To solve Part 2, simply solve Part 1 for every given slope.

Puzzle Answer: `1115775000`