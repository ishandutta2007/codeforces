#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

vector<string> names = {
    "monday",
    "tuesday",
    "wednesday",
    "thursday",
    "friday",
    "saturday",
    "sunday"
};

int main() {
    string a, b;
    cin >> a >> b;
    int x = find(names.begin(), names.end(), a) - names.begin();
    int y = find(names.begin(), names.end(), b) - names.begin();
    assert(x != 7 && y != 7);
    int poss[] = {31, 28, 30};
    for (int p : poss) {
        if ((x + p) % 7 == y) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}