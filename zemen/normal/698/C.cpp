#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 20;
const int bound = 2000;
ld p[maxn];
int n, k;

ld e[1 << maxn];
ld res[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    cin >> n >> k;
    int realN = 0;
    forn (i, n) {
        cin >> p[i];
        realN += (p[i] != 0);
    }
    if (realN <= k) {
        forn (i, n)
            res[i] = (p[i] != 0);
    } else {
        e[0] = 1;
        forn (mask, 1 << n) {
            ld p1 = 1;
            int bits = 0;
            forn (bit, n)
                if (mask & (1 << bit))
                    p1 -= p[bit], ++bits;
            if (bits >= k)
                continue;
            forn (bit, n) {
                if (mask & (1 << bit))
                    continue;
                ld delta = (e[mask] * p[bit] / p1);
                e[mask | (1 << bit)] += delta;
                res[bit] += delta;
            }
        }
    }
    cout << fixed;
    cout.precision(10);
    forn (i, n)
        cout << res[i] << ' ';
    cout << '\n';
}