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
int a[maxn];
ll pr[maxn];

bool can(ll x, int n) {
    if (x == 0)
        return true;
    int r = upper_bound(a, a + n, x) - a;
    if (r == 0)
        return false;
    int l = lower_bound(pr, pr + n + 1, pr[r] - x) - pr;
    //cerr << "check " << x << ' ' << l << ' ' << r << '\n';
    x -= pr[r] - pr[l];
    assert(x >= 0);
    return can(x, l);
}

int main() {
    #ifdef LOCAL
    assert(freopen("e.in", "r", stdin));
    #else
    #endif
    int c, n;
    cin >> c >> n;
    forn (i, n)
        scanf("%d", a + i);
    sort(a, a + n);
    forn (i, n)
        pr[i + 1] = pr[i] + a[i];
    assert(can(c, n));
    //forn (i, n)
        //cerr << a[i] << ' ';
    //cerr << '\n';
    a[n] = c;
    int ans = inf;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = min(c, a[i + 1]); j >= a[i]; --j) {
            if (!can(c - j, i + 1))
                ans = min(ans, j);
        }
        if (c >= a[i])
            c -= a[i];
    }
    if (ans == inf)
        cout << "Greed is good\n";
    else
        cout << ans << '\n';
}