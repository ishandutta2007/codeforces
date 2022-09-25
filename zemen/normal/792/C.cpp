#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100100;
string s;
int n;
int d[maxn][3];

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    cin >> s;
    n = sz(s);
    forn (i, n)
        s[i] -= '0';
    forn (i, n + 1)
        forn (q, 3)
            d[i][q] = inf;
    d[n][0] = 0;

    int st = -1, bst = 2 * inf;
    for (int i = n - 1; i >= 0; --i) {
        forn (r, 3) {
            int r2 = (r + 12 - s[i]) % 3;
            d[i][r] = min(d[i + 1][r] + 1, d[i + 1][r2]);
        }
        if (s[i] != 0) {
            int r2 = (12 - s[i]) % 3;
            int cur = d[i + 1][r2] + i;
            if (cur < bst) {
                bst = cur;
                st = i;
            }
        }
    }
    assert(st != -1);
    if (bst >= inf) {
        forn (i, n)
            if (s[i] == 0) {
                cout << 0 << '\n';
                return 0;
            }
        cout << -1 << '\n';
        return 0;
    }

    cout << int(s[st]);
    int r = (12 - s[st]) % 3;
    for (int i = st + 1; i < n; ++i) {
        int r2 = (r + 12 - s[i]) % 3;
        if (d[i + 1][r2] < d[i + 1][r] + 1) {
            cout << int(s[i]);
            r = r2;
        }
    }
    cout << '\n';
}