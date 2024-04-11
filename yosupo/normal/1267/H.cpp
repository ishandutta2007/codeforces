#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define rep1(i, N) for (int i = 1; i <= (int)(N); i++)
#define fs first
#define sc second
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(), x.end()
template <class T, class U> void chmin(T& t, const U& u) { if (u < t) t = u; }
template <class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

#ifdef LOCAL
#define show(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x)
#endif

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

V<int> solve(V<int> a, int dps = 0) {
    int n = int(a.size());
    V<int> ans(n, -1);
    if (n == 0) return ans;
    if (n == 1) {
        ans[0] = dps;
        return ans;
    }
    V<int> ra(n);
    for (int i = 0; i < n; i++) {
        ra[a[i]] = i;
    }

    V<int> col;

    {
        set<int> st;
        st.insert(-1); st.insert(n);
        V<int> cu(n);
        VV<int> cv(3);
        for (int ai = 0; ai < n; ai++) {
            int i = ra[ai];
            auto it = st.lower_bound(i);

            int nxt = *it;
            int prv = *prev(it);
            set<int> used;
            if (nxt != n) {
                used.insert(cu[nxt]);
            }
            if (prv != -1) {
                used.insert(cu[prv]);
            }
            cu[i] = 0;
            while (used.count(cu[i])) cu[i]++;
            cv[cu[i]].push_back(i);
            st.insert(i);
        }
        for (int i = 0; i < 3; i++) {
            if (col.size() < cv[i].size()) col = cv[i];
        }
    }

    V<int> vis(n), visa(n);
    for (int x: col) {
        ans[x] = dps;
        vis[x] = true;
        visa[a[x]] = true;
    }
    V<int> nval(n);
    int vc = 0;
    for (int i = 0; i < n; i++) {
        if (visa[i]) continue;
        nval[i] = vc++;
    }

    V<int> na_idx;
    V<int> na;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        na_idx.push_back(i);
        na.push_back(nval[a[i]]);
    }

    auto nans = solve(na, dps + 1);
    int n2 = int(nans.size());
    for (int i = 0; i < n2; i++) {
        ans[na_idx[i]] = nans[i];
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    V<int> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x; x--;
        a[x] = i;
    }
    auto ans = solve(a);
    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1;
        if (i != n - 1) cout << " ";
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}

/*
### Start  tests/H0.in
2 3 1
1 2 1
1
1 2 1 3 1 4 1 3 2 5
1 3 1 2 1 4 1 2 3 2

 */