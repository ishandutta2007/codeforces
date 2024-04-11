#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

template<class T> ostream& operator<<(ostream& os, const V<T> &v) {
    cout << "[";
    for (auto p: v) cout << p << ", ";
    cout << "]";
    return os;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int n, q;
    cin >> n >> q;
    V<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    VV<int> g(q+1);
    for (int i = 0; i < n; i++) g[a[i]].push_back(i);

    using P = pair<int, int>;
    set<int> st; st.insert(-1); st.insert(n);
    set<int> rem;
    for (int i = 0; i < n; i++) rem.insert(i);

    V<P> rng(q+1);
    for (int he = 1; he <= q; he++) {
        if (!rem.size()) {
            cout << "NO" << endl;
            return 0;
        }
        int s = g[he].size() ? g[he][0] : *rem.begin();
        auto it = st.lower_bound(s);
        int t = *it - 1;
        s = *prev(it) + 1;
        rng[he] = P(s, t);
        for (int d: g[he]) {
            st.insert(d);
            rem.erase(d);
        }
    }

    set<int> trg;
    for (int i = 0; i <= n; i++) trg.insert(i);

    V<int> res(n);
    for (int he = q; he >= 1; he--) {
        int s, t;
        tie(s, t) = rng[he];
        auto it = trg.lower_bound(s);
        while (*it <= t) {
            res[*it] = he;
            it = trg.erase(it);
        }
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0 && a[i] != res[i]) ok = false;
    }

    if (!ok) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    for (int d: res) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}