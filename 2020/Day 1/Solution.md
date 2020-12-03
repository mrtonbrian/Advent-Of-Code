# Solution
## Part 1
The first part of the problem is known as the "Two Sum problem". It is relatively simple to brute force in `O(N^2)`. That's pretty much good enough for this problem. My solution is `O(N)`.
```c++
pair<int, int> twosum(int target, int start, int end) {
    unordered_set<int> complements;
    for (int i = 0; i < end; i++) {
        int x = nums[i];
        if (complements.count(x)) {
            return make_pair(x, target-x);
        }
        complements.insert(target - x);
    }
    return make_pair(-1,-1);
}
```
This solution works by for each number `x`, storing its complement `target - x` in the set of `complements`. If `x` is found in the complements list, return `x` and `target - x` since they are both in the original list and sum to `target`.

For the first part, `target = 2020`.

Puzzle Answer: `898299`

## Part 2
This problem can be considered the "Three Sum" problem. The naive solution is `O(N^3)`. My solution is `O(N^2)` 
```c++
for (int i = 0; i < nums.size(); i++) {
        int x = nums[i];
        pair<int, int> remain = twosum(target - x, i, nums.size());
        if (remain.first != -1 && remain.second != -1) {
            printf("Part 2 Answer: %d * %d * %d = %d\n", x, remain.first, remain.second, x * remain.first * remain.second);
            break;
        }
}
```
The key to the solution is that finding a solution to the "Three Sum" problem is equivalent to finding a solution to a reduced "Two Sum" problem given a number `x` with `target = originalTarget - x` and ignoring `x` itself.

Puzzle Answer: `143933922`