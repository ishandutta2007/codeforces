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
typedef double ld;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int MN = 101000;
ld dp[MN];
ld pow(ld x, ll n) {
    ld r = 1;
    while (n) {
        if (n & 1) r *= x;
        x *= x;
        n >>= 1;
    }
    return r;
}

int main() {
    int m, n;
    cin >> m >> n;
    ld res = 0;
    for (int i = 1; i < m; i++) {
        res += pow(1.0*i/m, n);
    }
    printf("%.20f\n", (ld)(m)-res);
    return 0;
}