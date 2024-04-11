#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

#ifdef LOCAL
#define show(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
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

/*
struct E {
    int to, rev, cap;
};
VV<E> g;
auto add_edge = [&](int from, int to, int cap) {
    g[from].push_back(E{to, int(g[to].size()), cap});
    g[to].push_back(E{from, int(g[from].size())-1, 0});
};
*/

template<class C>
struct MaxFlow {
    C flow;
    V<char> dual;  // false: S-side true: T-side
};

template<class C, class E>
struct MFExec {
    static constexpr C INF = numeric_limits<C>::max();
    C eps;
    VV<E>& g;
    int s, t;
    V<int> level, iter;

    C dfs(int v, C f) {
        if (v == t) return f;
        C res = 0;
        for (int& i = iter[v]; i < int(g[v].size()); i++) {
            E& e = g[v][i];
            if (e.cap <= eps || level[v] >= level[e.to]) continue;
            C d = dfs(e.to, min(f, e.cap));
            e.cap -= d;
            g[e.to][e.rev].cap += d;
            res += d;
            f -= d;
            if (f == 0) break;
        }
        return res;
    }

    MaxFlow<C> info;
    MFExec(VV<E>& _g, int _s, int _t, C _eps)
            : eps(_eps), g(_g), s(_s), t(_t) {
        int N = int(g.size());

        C& flow = (info.flow = 0);
        while (true) {
            queue<int> que;
            level = V<int>(N, -1);
            level[s] = 0;
            que.push(s);
            while (!que.empty()) {
                int v = que.front(); que.pop();
                for (E e: g[v]) {
                    if (e.cap <= eps || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
            if (level[t] == -1) break;
            iter = V<int>(N, 0);
            while (true) {
                C f = dfs(s, INF);
                if (!f) break;
                flow += f;
            }
        }
        for (int i = 0; i < N; i++) info.dual.push_back(level[i] == -1);
    }
};

template<class C, class E>
MaxFlow<C> get_mf(VV<E>& g, int s, int t, C eps) {
    return MFExec<C, E>(g, s, t, eps).info;
}

const ll INF = TEN(18);

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, h, m;
    cin >> n >> h >> m;

    int v = n * (h + 2) + m + 2;
    int sv = v - 2, tv = v - 1;

    struct E {
        int to, rev;
        ll cap;
    };
    VV<E> g(v);
    auto add_edge = [&](int from, int to, ll cap) {
        g[from].push_back(E{to, int(g[to].size()), cap});
        g[to].push_back(E{from, int(g[from].size())-1, 0});
    };

    for (int i = 0; i < n; i++) {
        int o = i * (h + 2);
        add_edge(sv, o, INF);
        add_edge(o, sv, INF);

        add_edge(tv, o + h + 1, INF);
        add_edge(o + h + 1, tv, INF);

        for (int j = 0; j <= h; j++) {
            add_edge(o + j + 1, o + j, INF);
            add_edge(o + j, o + j + 1, 10000 - j * j);
        }
    }

    for (int ph = 0; ph < m; ph++) {
        int o = n * (h + 2) + ph;
        int l, r, x; ll c;
        cin >> l >> r >> x >> c; l--;

        if (x == h) continue;

        add_edge(o, tv, c);
        for (int i = l; i < r; i++) {
            add_edge(i * (h + 2) + x + 1, o, INF);
        }
    }

    ll ans = 10000 * n - get_mf(g, sv, tv, 0LL).flow;
    cout << ans << endl;

    return 0;
}