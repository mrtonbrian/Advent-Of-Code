# Solution
## Part 1
This problem is fairly simple to solve. I overengineered the problem, creating the `Position` class.

The way the solution works is by creating a `frequency` hash map that maps a character `c` to the number of times it occurs in the password. The password is then deemed valid in the `satisfiesCondition1` function, which checks if `lowerAmount ≤ targetChar ≤ higherAmount`.

Puzzle Answer: `542`

## Part 2
The solution to this problem involves checking if `password[lowerAmount] == targetChar ^ password[higherAmount] == targetChar`. Note that the xor operator "`^`" is used in order to make sure that exactly 1 bound is matched.

Puzzle Answer: `360`