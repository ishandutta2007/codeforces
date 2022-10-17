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

int n, q, k;
int a[N], b[N], p[N];
int mn[N], mx[N];

int m;
pii c[N];

pii t[N << 2];
vector<int> g[N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = {p[tl], tl};
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build(v << 1 | 1, tm + 1, tr);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

pii get(int v, int tl, int tr, int l, int r) {
    if (r < tl || tr < l || l > r)
        return {-inf, -1};
    if (l <= tl && tr <= r)
        return t[v];
    int tm = (tl + tr) >> 1;
    return max(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
}

int get(int l, int r) {
    if (l == r)
        return l;
    int v = get(1, 1, n, l, r).s;
    if (v > l)
        g[v].pb(get(l, v - 1));
    if (v < r)
        g[v].pb(get(v + 1, r));
    return v;
}

void dfs(int v) {
    if (a[v])
        mx[v] = mn[v] = a[v];

    for (auto to: g[v]) {
        mx[to] = mx[v] - 1;
        dfs(to);
        mn[v] = max(mn[to] + 1, mn[v]);
    }

}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    k = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == 0)
            k++;
    k--;
    for (int i = 1; i <= k; i++)
        cin >> b[i];
    sort(b + 1, b + 1 + k);

    build(1, 1, n);
    int root = get(1, n);

    for (int i = 1; i <= n; i++)
        mn[i] = -inf, mx[i] = inf;
    dfs(root);

    int L, R;
    bool ok = 1;
    m = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            ok &= (mn[i] <= a[i] && a[i] <= mx[i]);
            continue;
        }
        c[m++] = {mn[i], mx[i]};
        if (mn[i] > mx[i])
            ok = 0;
    }
    assert(m == k + 1);

    {
        sort(c, c + m, [](pii a, pii b) { return a.f < b.f; });
        set<pii> st;
        for (int i = 1, j = 0, q = 0; i <= k; i++) {
            int x = b[i];
            while (j < m && c[j].f <= x) {
                st.insert({c[j].s, j});
                j++;
            }
            if (st.empty()) {
                ok = 0;
                break;
            }
            if ((st.begin()->f) < x && q == 0) {
                R = (st.begin()->f);
                st.erase(st.begin());
                q = 1;
            }
            if (st.empty()) {
                ok = 0;
                break;
            }
            if ((st.begin()->f) < x && q == 1) {
                ok = 0;
                break;
            }

            st.erase(st.begin());

            if(i == k && q == 0){
                while (j < m) {
                    st.insert({c[j].s, j});
                    j++;
                }
                R = (st.begin()->f);
            }
        }

    }

    {
        sort(c, c + m, [](pii a, pii b) { return a.s > b.s; });
        set<pii> st;
        for (int i = k, j = 0, q = 0; i >= 1; i--) {
            int x = b[i];
            while (j < m && c[j].s >= x) {
                st.insert({-c[j].f, j});
                j++;
            }
            if (st.empty()) {
                ok = 0;
                break;
            }
            if (-(st.begin()->f) > x && q == 0) {
                L = -(st.begin()->f);
                st.erase(st.begin());
                q = 1;
            }
            if (st.empty()) {
                ok = 0;
                break;
            }
            if (-(st.begin()->f) > x && q == 1) {
                ok = 0;
                break;
            }
            st.erase(st.begin());
            if(i == 1 && q == 0){
                while (j < m) {
                    st.insert({-c[j].f, j});
                    j++;
                }
                L = -(st.begin()->f);
            }
        }
    }

//    cerr << L << " " << R << " " << ok << endl;


    while (q--) {
        int x;
        cin >> x;
        if (L <= x && x <= R && ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    for (int i = 1; i <= n; i++)
        g[i].clear();

}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}