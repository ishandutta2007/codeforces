#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long long i64;
typedef long double ld;

const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 500500;
char s[maxn];
int n, a, b, T;

int cost(int i) {
    return s[i] == 'w' ? b + 1 : 1;
}

int solve() {
    int t = T - cost(0);
    if (t < 0)
        return 0;
    int r = 1;
    while (r < n && cost(r) + a <= t) {
        t -= cost(r) + a;
        ++r;
    }
    int res = r;
    for (int L = n - 1; L > 0; --L) {
        t -= cost(L) + 2 * a;
        while (r > 1 && t < 0) {
            --r;
            t += cost(r) + a;
        }
        if (t < 0)
            break;
        res = max(res, r + n - L);
    }
    return res;
}

int main() {
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    cin >> n >> a >> b >> T;
    scanf("%s", s);

    int res = solve();
    reverse(s + 1, s + n);
    res = max(res, solve());
    res = min(res, n);

    cout << res << '\n';
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}