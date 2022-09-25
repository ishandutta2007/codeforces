#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 200200;
int h[maxn];
int onH[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n, s;
    cin >> n >> s;
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    --s;
    int extra = 0;
    int bad = 0;
    forn (i, n) {
        cin >> h[i];
        if (h[i] != 0 && i == s)
            h[i] = 0, ++extra;
        if (h[i] == 0 && i != s) {
            ++bad;
        } else
            onH[h[i]]++;
    }
    int slots = 0;
    forn (i, n)
        slots += onH[i] == 0;
    int res = inf;
    for (int i = n - 1; i >= 1; --i) {
        //cerr << bad << ' ' << slots << '\n';
        int cres = max(bad, slots);
        res = min(res, cres);
        slots -= onH[i] == 0;
        bad += onH[i];
    }
    cout << res + extra << '\n';
}