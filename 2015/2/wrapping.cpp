#include <bits/stdc++.h>

using namespace std;

class Box {
    int l, w, h;
    public:
    Box(int l, int w, int h) {
        this->l = l;
        this->w = w;
        this->h = h;
    }

    int wrappingAmount() {
        int firstFace = l * w;
        int secondFace = l * h;
        int thirdFace = w * h;

        return 2 * firstFace + 2 * secondFace + 2 * thirdFace +
               min(firstFace, min(secondFace, thirdFace));
    }

    int ribbonAmount() {
        int firstPerimeter = 2 * (l + w);
        int secondPerimeter = 2 * (l + h);
        int thirdPerimeter = 2 * (w + h);

        return min(firstPerimeter, min(secondPerimeter, thirdPerimeter)) + l * w * h;
    }
};

int main() {
    ifstream inp("wrapping.in");

    string line;

    int part1Answer = 0;
    int part2Answer = 0;
    while (getline(inp, line)) {
        int l, w, h;

        sscanf(line.c_str(), "%dx%dx%d", &l, &w, &h);
        Box b(l, w, h);
        part1Answer += b.wrappingAmount();
        part2Answer += b.ribbonAmount();
    }
    cout << "Part 1 Answer: " << part1Answer << endl;
    cout << "Part 2 Answer: " << part2Answer << endl;
}