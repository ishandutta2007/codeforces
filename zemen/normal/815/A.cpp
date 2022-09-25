#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 505;
int n, m;
int a[maxn][maxn];
int r[maxn];
int c[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    cin >> n >> m;
    forn (i, n)
        forn (j, m)
            cin >> a[i][j];
    int bx = -1;
    int bsx = inf;
    for (int x = 0; x <= a[0][0]; ++x) {
        forn (i, n)
            r[i] = a[i][0] - x;
        forn (i, m)
            c[i] = a[0][i] - r[0];
        bool fail = false;
        forn (i, n)
            if (r[i] < 0)
                fail = true;
        forn (i, m)
            if (c[i] < 0)
                fail = true;
        forn (i, n)
            forn (j, m)
                if (a[i][j] != r[i] + c[j])
                    fail = true;
        if (!fail) {
            int s = 0;
            forn (i, n)
                s += r[i];
            forn (i, m)
                s += c[i];
            if (bsx > s) {
                bsx = s;
                bx = x;
            }
        }
        continue;
    }
    if (bx != -1) {
        forn (i, n)
            r[i] = a[i][0] - bx;
        forn (i, m)
            c[i] = a[0][i] - r[0];

        cout << bsx << '\n';
        forn (i, n)
            forn (kk, r[i])
                cout << "row " << i + 1 << '\n';
        forn (i, m)
            forn (kk, c[i])
                cout << "col " << i + 1 << '\n';
        return 0;
    }

    cout << -1 << '\n';
}