#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 1010;
ld p[maxn];
ld w[maxn];
int n;

ld d[maxn];
bool fb() {
    int N = 2 * n + 1;
    forn (i, N)
        d[i] = 1e18;
    d[n] = 0;

    forn (iter, N)
        forn (u, N)
            forn (delta, n + 1) {
                int v = u + n - 2 * delta;
                if (v < 0 || v >= N)
                    continue;
                d[v] = min(d[v], d[u] + w[delta]);
            }
    return d[n] < 0;
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    cout << fixed;
    cout.precision(10);

    cin >> n;
    forn (i, n + 1)
        cin >> p[i];

    ld L = 0, R = 1;
    forn (iter, 60) {
        ld C = (L + R) / 2;
        forn (i, n + 1)
            w[i] = C - p[i];
        if (fb())
            L = C;
        else
            R = C;
    }
    cout << L << '\n';
}