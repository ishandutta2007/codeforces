//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL
#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

#ifdef LOCAL
struct PrettyOS {
    ostream& os;
    bool first;
    template <class T> auto operator<<(T&& x) {
        if (!first) os << ", ";
        first = false;
        os << x;
        return *this;
    }
};
template <class... T> void dbg0(T&&... t) {
    (PrettyOS{cerr, true} << ... << t);
}
#define dbg(...)                                            \
    do {                                                    \
        cerr << __LINE__ << " : " << #__VA_ARGS__ << " = "; \
        dbg0(__VA_ARGS__);                                  \
        cerr << endl;                                       \
    } while (false);
#else
#define dbg(...)
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

struct E {
    int to, on, rev;
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n, m;
    cin >> n >> m;
    VV<E> g(n);
    VV<int> ing(n);

    V<ll> ind(n), oud(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        if (a > b) swap(a, b);
        g[a].push_back(E{b, 0, int(g[b].size())});
        g[b].push_back(E{a, 1, int(g[a].size()) - 1});
        ing[a].push_back(int(g[a].size()) - 1);        
        ind[a]++;
        oud[b]++;
    }
    dbg(ind, oud);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += ind[i] * oud[i];
    }

    cout << ans << "\n";

    int que;
    cin >> que;
    for (int ph = 0; ph < que; ph++) {
        int p;
        cin >> p;
        p--;

        ans -= ind[p] * oud[p];
        for (int idx: ing[p]) {
            if (g[p][idx].on) continue;            
            // reverse
            int q = g[p][idx].to;
            int ridx = g[p][idx].rev;
            g[p][idx].on = 1;
            g[q][ridx].on = 0;
            ing[q].push_back(ridx);

            ans -= ind[q] * oud[q];
            ind[q]++;
            oud[q]--;
            ans += ind[q] * oud[q];
        }
        oud[p] = int(g[p].size());
        ind[p] = 0;
        ing[p].clear();

        cout << ans << "\n";
    }
    
    return 0;
}