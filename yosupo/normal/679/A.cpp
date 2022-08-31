#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

bool que(int i) {
    cout << i << endl; fflush(stdout);
    string s;
    cin >> s;
    return (s == "yes");
}
void ans(bool f) {
    cout << (f ? "prime" : "composite") << endl; fflush(stdout);
}
int main() {
    int co = 0;
    for (int i = 2; i <= 50; i++) {
        bool f = true;
        for (int j = 2; j < i; j++) {
            if (i%j == 0) {
                f = false;
                break;
            }
        }
        if (!f) continue;
        bool r = que(i);
        if (r) co++;
        if (co == 2) {
            ans(false);
            return 0;
        }
        if (i*i <= 100) {
            if (que(i*i)) {
                ans(false);
                return 0;
            }
        }
    }
    ans(true);
    return 0;
}