# [Report Repair](https://adventofcode.com/2020/day/1)

## Part 1
Before you leave, the Elves in accounting just need you to fix your expense report (your puzzle input); apparently, something isn't quite adding up.

Specifically, they need you to **find the two entries that sum to `2020` and then multiply those two numbers together**.

For example, suppose your expense report contained the following:
```
1721
979
366
299
675
1456
```
In this list, the two entries that sum to `2020` are `1721` and `299`. Multiplying them together produces `1721 * 299 = 514579`, so the correct answer is `514579`.

Of course, your expense report is much larger. **Find the two entries that sum to `2020`; what do you get if you multiply them together?**

## Part 2
The Elves in accounting are thankful for your help; one of them even offers you a starfish coin they had left over from a past vacation. They offer you a second one if you can find three numbers in your expense report that meet the same criteria.

Using the above example again, the **three** entries that sum to `2020` are `979`, `366`, and `675`. Multiplying them together produces the answer, `241861950`.

In your expense report, **what is the product of the three entries that sum to `2020`**?

## Solution
### Part 1
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

### Part 2
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