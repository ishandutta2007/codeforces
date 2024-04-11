#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100100;
int a[maxn];
ll p[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n, k;
    cin >> n >> k;
    forn (i, n)
        scanf("%d", a + i);
    forn (i, n + 1)
        p[i + 1] = p[i] + a[i];
    set<ll> pw;
    ll x = 1;
    while (x < infl / 10) {
        if (pw.count(x))
            break;
        pw.insert(x);
        x *= k;
    }
    map<ll, int> cnt;
    ll res = 0;
    forn (i, n + 1) {
        for (auto x: pw)
            res += cnt[p[i] - x];
        cnt[p[i]]++;
    }
    cout << res << '\n';
}