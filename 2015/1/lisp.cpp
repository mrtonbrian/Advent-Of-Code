#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream inp("lisp.in");

    vector<char> chars;
    int part1 = 0;
    int part2 = -1;
    int i = 0;
    char c;
    while (inp >> c) {
        i++;
        chars.push_back(c);
        if (c == '(') {
            part1++;
        } else {
            part1--;
        }

        if (part2 == -1 && part1 == -1) {
            part2 = i;
        }
    }

    cout << "Part 1 Answer: " << part1 << endl;
    cout << "Part 2 Answer: " << part2 << endl;
}