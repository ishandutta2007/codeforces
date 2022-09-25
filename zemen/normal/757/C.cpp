#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int mod = 1e9 + 7;

const int maxn = 1000100;
vector<pair<int, int>> a[maxn];
ll fact[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    fact[0] = 1;
    for (int i = 1; i < maxn; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
    int n, m;
    cin >> n >> m;
    forn (i, n) {
        int cnt;
        scanf("%d", &cnt);
        vector<int> v;
        forn (j, cnt) {
            int x;
            scanf("%d", &x);
            --x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        forn (l, sz(v)) {
            int r = l;
            while (r < sz(v) && v[r] == v[l])
                ++r;
            a[v[l]].emplace_back(i, r - l);
            l = r - 1;
        }
    }
    ll res = 1;
    sort(a, a + m);
    forn (l, m) {
        int r = l;
        while (r < m && a[l] == a[r])
            ++r;
        res = (res * fact[r - l]) % mod;
        l = r - 1;
    }
    cout << res << '\n';
}