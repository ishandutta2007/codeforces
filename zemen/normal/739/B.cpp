#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

struct Set {
    priority_queue<ll> s;
    ll x;

    Set(): x(0) {
    }

    void clr() {
        while (!s.empty() && s.top() + x > 0) {
            s.pop();
        }
    }

    void ins(ll y) {
        s.push(y - x);
    }

    void add(ll delta) {
        x += delta;
    }

    int size() {
        clr();
        return sz(s);
    }
};

const int maxn = 200200;
Set d[maxn];
int a[maxn];
vector<pair<int, int>> g[maxn];
int ans[maxn];

int dfs(int u) {
    //cerr << "dfs " << u + 1 << '\n';
    int i = u;
    d[i].ins(-a[u]);
    for (auto p: g[u]) {
        int v = p.first;
        int w = p.second;
        int j = dfs(v);
        d[j].add(w);
        int s1 = d[i].size();
        int s2 = d[j].size();
        if (s2 > s1)
            swap(i, j);
        while (!d[j].s.empty()) {
            ll cur = d[j].s.top() + d[j].x;
            d[j].s.pop();
            d[i].ins(cur);
        }
    }
    ans[u] = d[i].size() - 1;
    return i;
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n;
    scanf("%d", &n);
    forn (i, n)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; ++i) {
        int p, w;
        scanf("%d%d", &p, &w);
        --p;
        g[p].emplace_back(i, w);
    }
    dfs(0);
    forn (i, n)
        cout << ans[i] << ' ';
    cout << '\n';
}