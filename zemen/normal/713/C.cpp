#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 3005;
int a[maxn];
ll d[2][maxn];
int o[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i];
        a[i] -= i;
        o[i] = a[i];
    }
    sort(o, o + n);
    int q = 0;
    forn (i, n) {
        forn (j, n)
            d[q ^ 1][j] = infl;

        ll vmin = infl;
        forn (j, n) {
            vmin = min(vmin, d[q][j]);
            int val = o[j];
            int add = abs(a[i] - val);
            d[q ^ 1][j] = min(d[q ^ 1][j], vmin + add);
        }
        q ^= 1;
    }
    ll best = infl;
    forn (j, n)
        best = min(best, d[q][j]);
    cout << best << '\n';
}