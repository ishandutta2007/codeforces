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
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    const int B = 1900;

    int n;
    cin >> n;
    int l = -inf, r = inf;
    int bal = 0;
    forn (i, n) {
        int c, d;
        cin >> c >> d;
        if (d == 1)
            l = max(l, B - bal);
        else if (d == 2)
            r = min(r, B - bal);
        bal += c;
    }
    if (l >= r) {
        cout << "Impossible\n";
    } else if (r == inf) {
        cout << "Infinity\n";
    } else
        cout << r - 1 + bal << '\n';
}