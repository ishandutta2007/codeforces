#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int n, k;
    ld l, v1, v2;
    cin >> n >> l >> v1 >> v2 >> k;
    int steps = (n + k - 1) / k;
    v2 -= v1;

    ld L = l / (v1 + v2), R = l / v1;
    forn (iter, 300) {
        ld T = (L + R) / 2;
        ld D = (l - v1 * T) / v2;
        bool FAIL = false;
        ld pos = 0;
        forn (i, steps) {
            pos += (v1 + v2) * D;
            if (pos > l) {
                FAIL = true;
                break;
            }
            pos -= (v2 * D) / (v1 + v2 + v1) * (v1 + v2);
        }
        if (FAIL)
            L = T;
        else
            R = T;
    }
    cout << fixed;
    cout.precision(20);
    cout << (L + R) / 2 << '\n';
}