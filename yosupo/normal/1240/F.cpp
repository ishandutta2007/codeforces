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
    int to, id;
};

int k; // # of col
V<int> col;
VV<E> g;

V<int> freq(int p) {
    V<int> buf(k);
    for (auto e: g[p]) {
        buf[col[e.id]]++;
    }
    int mi = 10000;
    for (int d: buf) mi = min(mi, d);
    for (int& d: buf) {
        d -= mi;
        assert(d <= 2);
    }
    return buf;
}

V<int> used;
V<int> path;
void dfs(int p, int a, int b) {
    for (auto e: g[p]) {
        if (col[e.id] != a || used[e.id]) continue;
        path.push_back(e.id);
        used[e.id] = true;
        dfs(e.to, b, a);
        break;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m;
    cin >> n >> m >> k;
    g = VV<E>(n);
    col = V<int>(m, -1);

    for (int i = 0; i < n; i++) {
        int unko;
        cin >> unko;
    }

    for (int ph = 0; ph < m; ph++) {
        int u, v;
        cin >> u >> v; u--; v--;
        auto fu = freq(u), fv = freq(v);
        int ac = -1, bc = -1, cc = -1;
        for (int i = 0; i < k; i++) {
            if (fu[i] != 2 && fv[i] != 2) {
                cc = i;
                break;
            }
            if (fv[i] == 0) {
                ac = i;
            }
            if (fu[i] == 0) {
                bc = i;
            }
        }
        if (cc == -1) {
            assert(ac != -1 && bc != -1);
            used = V<int>(ph);
            path.clear();
            dfs(u, ac, bc);
            dbg(path);
            for (int id: path) {
                if (col[id] == ac) col[id] = bc;
                else col[id] = ac;
            }
            cc = ac;            
        }
        g[u].push_back({v, ph});
        g[v].push_back({u, ph});
        col[ph] = cc;
    }
//    for (int i = 0; i < n; i++) {
//        dbg(freq(i));
//    }
    for (int d: col) {
        cout << d + 1 << "\n";
    }
    return 0;
}