#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);
typedef pair<int, int> pii;

const int maxn = 105;
int a[maxn];
int b[maxn];
pii d[maxn * maxn];

void uin(pii &a, const pii &b) {
    a = min(a, b);
}

int main() {
    #ifdef LOCAL
    assert(freopen("j.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n)
        cin >> a[i];
    forn (i, n)
        cin >> b[i];
    int sum = accumulate(a, a + n, 0);
    //cerr << sum << '\n';
    forn (i, maxn * maxn)
        d[i] = pii{inf, inf};
    d[0] = pii{0, sum};
    forn (i, n) {
        for (int j = maxn * maxn - b[i] - 1; j >= 0; --j) {
            uin(d[j + b[i]], pii(d[j].first + 1, d[j].second - a[i]));
        }
    }
    pii res{inf, inf};
    for (int i = sum; i < maxn * maxn; ++i) {
        uin(res, d[i]);
    }
    cout << res.first << ' ' << res.second << '\n';
}