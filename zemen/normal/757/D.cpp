#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 77;
const int B = 20;

const int mod = 1e9 + 7;

void udd(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

char s[maxn];
int d[maxn][1 << B];

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n >> s;
    forn (i, n)
        s[i] -= '0';

    forn (l, n) {
        int x = 0;
        for (int r = l + 1; r <= n; ++r) {
            x <<= 1;
            x += s[r - 1];
            if (x > B)
                break;
            if (x)
                udd(d[r][1 << (x - 1)], 1);
        }
    }
    forn (l, n) {
        forn (mask, 1 << B) {
            if (!d[l][mask])
                continue;
            int x = 0;
            for (int r = l + 1; r <= n; ++r) {
                x <<= 1;
                x += s[r - 1];
                if (x > B)
                    break;
                if (x)
                    udd(d[r][(1 << (x - 1)) | mask], d[l][mask]);
            }
        }
    }
    int res = 0;
    for (int r = 1; r <= n; ++r) {
        for (int mx = 1; mx <= B; ++mx) {
            int mask = (1 << mx) - 1;
            //cerr << mx << ' ' << r << ' ' << d[r][mask] << '\n';
            udd(res, d[r][mask]);
        }
    }
    cout << res << '\n';
}