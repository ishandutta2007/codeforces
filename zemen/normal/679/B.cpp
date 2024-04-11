#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);
typedef pair<ll, ll> pll;

const int maxn = 10000;
ll d[maxn];
pll dbest[maxn];

ll cube(ll x) {
    return x * x * x;
}

ll sqrt3(ll x) {
    ll a = pow(x, 1. / 3);
    while (cube(a) > x)
        --a;
    while (cube(a + 1) <= x)
        ++a;
    return a;
}

pll solve(ll n) {
    if (n < maxn)
        return dbest[n];
    ll g = sqrt3(n);
    pll res1 = {0, 0}, res2 = {0, 0};
    if (g > 1) {
        res1 = solve(cube(g) - cube(g - 1) - 1);
        res1.first++;
        res1.second += cube(g - 1);
    }
    res2 = solve(n - cube(g));
    res2.first++;
    res2.second += cube(g);
    return max(res1, res2);
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    d[0] = 0;
    dbest[0] = {0, 0};
    for (int i = 1; i < maxn; ++i) {
        ll g = sqrt3(i);
        d[i] = d[i - cube(g)] + 1;
        dbest[i] = max(dbest[i - 1], {d[i], i});
    }
    ll N;
    cin >> N;
    auto res = solve(N);
    cout << res.first << ' ' << res.second << '\n';
}