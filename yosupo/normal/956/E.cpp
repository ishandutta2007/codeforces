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
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

const int MA = 10010;
using B = bitset<MA>;

B dp0, dp1;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    int n, l, r;
    cin >> n >> l >> r;

    V<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    V<int> c; int csm = 0;
    dp0[0] = true;
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            dp0 |= dp0 << a[i];
        } else {
            c.push_back(a[i]);
            csm += a[i];
        }
    }
    sort(begin(c), end(c));
    n = int(c.size());

/*    for (int d: c) cout << d << ", "; cout << endl;

    for (int i = 0; i < 100; i++) {
        if (dp0[i]) cout << i << ", ";
    }
    cout << endl;*/

    auto addI = [&](int x) {
        dp1 |= dp1 << x;
        dp1 |= dp0;
        dp0 |= dp0 << x;
    };


    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        int lx = l, rx = r - csm;
        bool ok0 = false, ok1 = false;
        for (int k = lx; k <= rx; k++) {
            ok0 |= dp0[k]; ok1 |= dp1[k];
        }
        if (ok0) ans = max(ans, i+1);
        if (ok1) ans = max(ans, i+2);
        addI(c[i]); csm -= c[i];
    }
    for (int k = l; k <= r; k++) {
        if (dp1[k]) ans = max(ans, 1);
    }

    cout << ans << endl;
    return 0;
}