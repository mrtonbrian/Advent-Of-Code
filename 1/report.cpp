#include <bits/stdc++.h>

using namespace std;

pair<int, int> twosum(vector<int>& nums, int target, int start, int end) {
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
    vector<int> inp;

    while (true) {
        int i;
        input >> i;
        if (input.eof()) {break;}
        inp.push_back(i);
        
    }

    // Part 1
    pair<int, int> part1 = twosum(inp, 2020, 0, inp.size());

    printf("Part 1 Answer: %d * %d = %d\n", part1.first, part1.second, part1.first * part1.second);
    // Part 2
    for (int i = 0; i < inp.size(); i++) {
        int x = inp[i];
        pair<int, int> remain = twosum(inp, 2020 - x, i, inp.size());
        if (remain.first != -1 && remain.second != -1) {
            printf("Part 2 Answer: %d * %d * %d = %d\n", x, remain.first, remain.second, x * remain.first * remain.second);
            break;
        }
    }
}