#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 105;
int a[maxn];
int d[maxn][3];

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n)
        cin >> a[i];
    forn (i, n + 1)
        if (i != 0)
            forn (j, 3)
                d[i][j] = inf;
    forn (i, n) {
        forn (j, 3) {
            forn (k, 3) {
                if (j == k && j != 2)
                    continue;
                if (k != 2 && !(a[i] & (1 << k)))
                    continue;
                d[i + 1][k] = min(d[i + 1][k], d[i][j] + (k == 2));
            }
        }
    }
    int res = inf;
    forn (j, 3)
        res = min(res, d[n][j]);
    cout << res << '\n';
}