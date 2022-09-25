#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int N = 1010;
const int M = 8010;

ld d[M + 5][N];
const ld eps = 1e-7;

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int k, q;
    cin >> k >> q;
    d[0][0] = 1;
    forn (i, M) {
        forn (j, k + 1) {
            d[i + 1][j] += d[i][j] * ld(j) / ld(k);
            d[i + 1][j + 1] += d[i][j] * ld(k - j) / ld(k);
        }
    }

    forn (i, q) {
        ld p;
        cin >> p;
        p -= eps;
        p /= 2000;
        int res = 0;
        while (d[res][k] < p)
            ++res;
        cout << res << '\n';
    }
}