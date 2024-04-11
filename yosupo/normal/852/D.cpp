#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

template<class C>
struct MaxFlow {
    C flow;
    V<char> dual;  // false: S-side true: T-side
};

template<class C, class E>
struct MF_EXEC {
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
    MF_EXEC(VV<E>& _g, int _s, int _t, C _eps)
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
    return MF_EXEC<C, E>(g, s, t, eps).info;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int v, e, n, k;
    cin >> v >> e >> n >> k;

    V<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i]; pos[i]--;
    }

    VV<int> dist(v, V<int>(v, TEN(9)));
    for (int i = 0; i < v; i++) dist[i][i] = 0;

    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c; a--; b--;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int lw = -1, up = 1731312;
    while (up - lw > 1) {
        int md = (lw + up) / 2;
        struct E {
            int to, rev, cap;
        };
        VV<E> g(n + v + 2);
        int sv = n + v, tv = sv + 1;
        auto add_edge = [&](int from, int to, int cap) {
            g[from].push_back(E{to, int(g[to].size()), cap});
            g[to].push_back(E{from, int(g[from].size())-1, 0});
        };
        for (int p = 0; p < n; p++) add_edge(sv, p, 1);
        for (int j = 0; j < v; j++) add_edge(n + j, tv, 1);
        for (int p = 0; p < n; p++) {
            int i = pos[p];
            for (int j = 0; j < v; j++) {
                if (dist[i][j] <= md) add_edge(p, n + j, 1);
            }
        }
        if (get_mf(g, sv, tv, 0).flow < k) lw = md;
        else up = md;
    }
    if (up == 1731312) cout << -1 << endl;
    else cout << up << endl;
    return 0;
}