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

struct LCA {
    int lg;
    VV<int> anc;
    V<int> dps;
    /// lrLCA
    int query(int l, int r) {
        if (dps[l] < dps[r]) swap(l, r);
        int dd = dps[l]-dps[r];
        for (int i = lg-1; i >= 0; i--) {
            if (dd < (1<<i)) continue;
            dd -= 1<<i;
            l = anc[i][l];
        }
        if (l == r) return l;
        for (int i = lg-1; i >= 0; i--) {
            if (anc[i][l] == anc[i][r]) continue;
            l = anc[i][l]; r = anc[i][r];
        }
        return anc[0][l];
    }
};

template<class E>
struct LCA_EXEC : LCA {
    const VV<E>& g;

    ///  rrootid
    LCA_EXEC(const VV<E>& _g, int r) : g(_g) {
        int N = int(g.size());
        lg = 1;
        while ((1<<lg) < N) lg++;
        anc = VV<int>(lg, V<int>(N, -1));
        dps = V<int>(N);
        dfs(r, -1, 0);
        for (int i = 1; i < lg; i++) {
            for (int j = 0; j < N; j++) {
                anc[i][j] = (anc[i-1][j] == -1) ? -1 : anc[i-1][anc[i-1][j]];
            }
        }
    }

    void dfs(int p, int b, int now) {
        anc[0][p] = b;
        dps[p] = now;
        for (E e: g[p]) {
            if (e.to == b) continue;
            dfs(e.to, p, now+1);
        }
    }
};

template <class E>
LCA get_lca(const VV<E> &g, int r) { return LCA_EXEC<E>(g, r); }

struct UnionFind {
    V<int> ig;
    VV<int> gi;
    int gc;  // group count
    UnionFind(int n) {
        ig = V<int>(n);
        gi = VV<int>(n);
        for (int i = 0; i < n; i++) {
            ig[i] = i;
            gi[i] = {i};
        }
        gc = n;
    }

    void merge(int a, int b) {
        if (same(a, b)) return;
        gc--;
        int x = ig[a], y = ig[b];
        if (gi[x].size() < gi[y].size()) swap(x, y);
        for (int j: gi[y]) {
            ig[j] = x;
        }
        gi[x].insert(gi[x].end(), gi[y].begin(), gi[y].end());
        gi[y].clear();
    }

    bool same(int a, int b) { return ig[a] == ig[b]; }
};

struct E {
    int from, to, wei, ty;
};
const int INF = TEN(9) + TEN(6);

using P = pair<int, int>;
VV<E> g;
VV<P> que;

using Q = priority_queue<P, V<P>, greater<P>>;

bool inf = false;
ll ans = 0;

Q* dfs(int p, int b, int ty, int ndp = 0) {
    Q* now = new Q();
    for (auto q: que[p]) now->push(q);

    for (E e: g[p]) {
        if (e.to == b) continue;
        Q* nex = dfs(e.to, p, e.ty, ndp+1);
        if (now->size() < nex->size()) swap(now, nex);
        while (nex->size()) {
            now->push(nex->top()); nex->pop();
        }
        delete nex;
    }
    while (now->size()) {
        if (now->top().second < ndp) break;
        now->pop();
    }
    if (!ty) {
        if (now->size()) ans += now->top().first;
        else inf = true;
    }
    return now;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int n, k, m;
    cin >> n >> k >> m;
    g = VV<E>(n);
    auto uf = UnionFind(n);
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(E{a, b, 0, 0});
        g[b].push_back(E{b, a, 0, 0});
        uf.merge(a, b);
    }

    V<E> edges;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w; a--; b--;
        edges.push_back(E{a, b, w, 1});
    }
    sort(edges.begin(), edges.end(), [&](const E &l, const E &r) {
        return l.wei < r.wei;
    });

    for (auto e: edges) {
        if (uf.same(e.from, e.to)) continue;
        uf.merge(e.from, e.to);
        g[e.from].push_back(E{e.from, e.to, 0, 1});
        g[e.to].push_back(E{e.to, e.from, 0, 1});
    }
    que = VV<P>(n);
    auto lca = get_lca(g, 0);
    for (auto e: edges) {
        int a = e.from, b = e.to, c = lca.query(a, b);
        que[a].push_back(P(e.wei, lca.dps[c]));
        que[b].push_back(P(e.wei, lca.dps[c]));
    }

    dfs(0, -1, 1);

    cout << (inf ? -1 : ans) << endl;
    return 0;
}