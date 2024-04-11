#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
int bsr(int x) { return 31 - __builtin_clz(x); }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    ll mi = -TEN(12), ma = TEN(18);
    int n;
    cin >> n;
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        int c, d;
        cin >> c >> d;
        // rating = x + sm
        if (d == 1) {
            //x + sm >= 1900
            //x >= 1900 - sm
            mi = max(mi, 1900-sm);
        } else {
            //x + sm <= 1899
            //x <= 1899 - sm
            ma = min(ma, 1899-sm);
        }
        sm += c;
    }
    if (ma > TEN(17)) {
        cout << "Infinity" << endl;
        return 0;
    }
    if (ma < mi) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << ma + sm << endl;
    return 0;
}