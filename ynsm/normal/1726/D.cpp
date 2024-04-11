#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, inf = 1e9, mod = 998244353;

int sum(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod;
}

int bp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return bp(x, mod - 2);
}

vector<int> g[N];
int n, m;
int a[N], b[N], d[N];
bool was[N], ans[N];
int pr[N];

vector<int> kek;

void dfs(int v, int p) {
    was[v] = 1;
    for (auto e: g[v]) {
        int to = a[e] ^ b[e] ^ v;
        if (to == p)
            continue;
        if (was[to]) {
            kek.pb(e);
        } else {
            d[to] = d[v] + 1;
            pr[to] = e;
            dfs(to, v);
        }
    }
}

void solve() {
    cin >> n >> m;
    kek.clear();
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        was[i] = 0;
        d[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        g[a[i]].pb(i);
        g[b[i]].pb(i);
        ans[i] = 0;
    }
    dfs(1, -1);
    sort(kek.begin(), kek.end());
    kek.erase(unique(kek.begin(), kek.end()), kek.end());
    set<int> st;
    for (auto e: kek) {
        st.insert(a[e]);
        st.insert(b[e]);
    }
//    cerr << kek.size() << " " << st.size() << endl;
    if (m != n + 2 || st.size() != 3) {
        for (auto e: kek)
            ans[e] = 1;
    } else {
        vector<pii> dv;
        for (auto x: st)
            dv.push_back({d[x], x});
        sort(dv.begin(), dv.end());
        reverse(dv.begin(), dv.end());
        for (int i = 0; i < m; i++) {
            if (a[i] == dv[0].s && b[i] == dv[1].s)
                ans[i] = 1;
            if (a[i] == dv[1].s && b[i] == dv[0].s)
                ans[i] = 1;
        }
        for (int i = 0; i < m; i++) {
            if (a[i] == dv[1].s && b[i] == dv[2].s)
                ans[i] = 1;
            if (a[i] == dv[2].s && b[i] == dv[1].s)
                ans[i] = 1;
        }
        int v = dv[1].s;
        int p = dv[2].s;
        while (v != p) {
            int e = pr[v];
            ans[e] = 1;
            v = a[e] ^ b[e] ^ v;
            break;
        }
    }
    for (int i = 0; i < m; i++)
        cout << ans[i];
    cout << endl;
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}