#include <bits/stdc++.h>

using namespace std;

vector<int> nums;

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

int main() {
    int target = 2020;

    ifstream input("report.in");

    while (true) {
        int i;
        input >> i;
        if (input.eof()) {break;}
        nums.push_back(i);
        
    }

    // Part 1
    pair<int, int> part1 = twosum(target, 0, nums.size());

    printf("Part 1 Answer: %d * %d = %d\n", part1.first, part1.second, part1.first * part1.second);
    // Part 2
    for (int i = 0; i < nums.size(); i++) {
        int x = nums[i];
        pair<int, int> remain = twosum(target - x, i, nums.size());
        if (remain.first != -1 && remain.second != -1) {
            printf("Part 2 Answer: %d * %d * %d = %d\n", x, remain.first, remain.second, x * remain.first * remain.second);
            break;
        }
    }
}