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

using B = bitset<120>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, k;
    cin >> n >> k;
    VV<int> ps;
    map<V<int>, int> p2idx;
    {
        V<int> idx(k);
        iota(idx.begin(), idx.end(), 0);
        do {
            p2idx[idx] = int(ps.size());
            ps.push_back(idx);
        } while (next_permutation(idx.begin(), idx.end()));
    }
    int m = int(ps.size());

    V<int> a(n);
    for (int i = 0; i < n; i++) {
        V<int> p(k);
        for (int j = 0; j < k; j++) {
            cin >> p[j]; p[j]--;
        }
        a[i] = p2idx[p];
    }

    VV<int> mov(m, V<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            V<int> res(k);
            for (int l = 0; l < k; l++) {
                res[l] = ps[i][ps[j][l]];
            }
            mov[i][j] = p2idx[res];
        }
    }

    ll ans = 0;
    V<int> nx(m, n);
    for (int l = n - 1; l >= 0; l--) {
        nx[a[l]] = l;
        B st = B();
        st.set(0);

        V<int> bases;
        int bk = l;
        while (true) {
            int nw = n;
            for (int i = 0; i < m; i++) {
                if (st[i]) continue;
                nw = min(nw, nx[i]);
            }
            ans += (nw - bk) * st.count();
            bk = nw;
            if (nw == n) break;                

            bases.push_back(a[nw]);
            B q = st;
            while (q.any()) {
                int p = int(q._Find_first());
                if (p >= m) break;
                q.reset(p);
                for (int d: bases) {
                    int np = mov[p][d];
                    if (st[np]) continue;
                    st.set(np);
                    q.set(np);
                }
            }
        }
    }

    cout << ans << endl;

    dbg(a);
    return 0;
}