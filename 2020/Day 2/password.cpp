#include <bits/stdc++.h>

using namespace std;

class Password {
    string password;
    int lowerAmount;
    int higherAmount;
    char targetChar;

    unordered_map<char, int> frequency;


    public:
    Password(string pass, int lower, int higher, char target) {
        password = pass;
        lowerAmount = lower;
        higherAmount = higher;
        targetChar = target;

        for (char c : password) {
            auto it = frequency.find(c);
            if (it != frequency.end()) {
                it->second += 1;
            } else {
                frequency.insert(make_pair(c, 1));
            }
        }
    }
    
    bool satisfiesCondition1() {
        return lowerAmount <= frequency[targetChar] && frequency[targetChar] <= higherAmount;
    }

    bool satisfiesCondition2() {
        return password.at(lowerAmount - 1) == targetChar ^ password.at(higherAmount - 1) == targetChar;
    }
};

int main() {
    ifstream inp("password.in");
    
    std::vector<Password> passwords;
    int numValid1 = 0;
    int numValid2 = 0;
    while (true) {
        char dash;
        char colon;
        
        int lower;
        int upper;
        char target;
        string pass;

        inp >> lower >> dash >> upper >> target >> colon >> pass;

        Password p(pass, lower, upper, target);

        if (p.satisfiesCondition1()) {
            numValid1++;
        }
        if (p.satisfiesCondition2()) {
            numValid2++;
        }
        if (inp.eof()) {break;}
    }
    cout << "Part 1 Answer: " << numValid1 << endl;
    cout << "Part 2 Answer: " << numValid2 << endl;
}