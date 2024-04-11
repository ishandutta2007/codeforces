#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
const string s[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int main() {
    int n;
    cin >> n;
    string ss;
    cin >> ss;
    for (string s1: s) {
        if (ss.size() != s1.size()) continue;
        bool f = true;
        for (int i = 0; i < s1.size(); i++) {
            if (ss[i] == s1[i] || ss[i] == '.') {

            } else {
                f = false;
                break;
            }
        }
        if (f) {
            cout << s1 << endl;
            return 0;
        }
    }
    return 0;
}