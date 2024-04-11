#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)
#define sz(x) ((int) (x).size())

int get(ll a, int x) {
    return (a >> x) & 1;
}

int main() {
#ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
#endif
    ll s, x;
    cin >> s >> x;
    ll d[2] = {1, 0};
    forn (i, 43) {
        ll to[2] = {0, 0};
        forn (p, 2)
            forn (c1, 2)
                forn (c2, 2) {
                    int cs = (c1 ^ c2 ^ p);
                    int cx = (c1 ^ c2);
                    int np = c1 + c2 + p >= 2;
                    if (get(s, i) != cs || get(x, i) != cx)
                        continue;
                    to[np] += d[p];
                }
        d[0] = to[0], d[1] = to[1];
    }
    if (s == x)
        d[0] -= 2;
    cout << d[0] << '\n';
}