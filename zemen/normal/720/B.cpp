#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
typedef pair<int, int> pii;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 200050;
vector<pii> g[maxn];
vector<vector<int>> M;
vector<int> goods;
int in[maxn];
bool used[maxn];
int timer = 0;
int h[maxn];

vector<pii> st;
void dfs(int u, int prev = -1) {
    in[u] = timer++;
    used[u] = true;
    for (auto p: g[u]) {
        int v = p.first;
        if (v == prev)
            continue;
        if (used[v]) {
            if (in[v] > in[u])
                continue;
            vector<int> cm;
            cm.push_back(p.second);
            while (st.back().first > h[v]) {
                cm.push_back(st.back().second);
                st.pop_back();
            }
            M.push_back(cm);
            continue;
        }
        h[v] = h[u] + 1;
        st.emplace_back(h[v], p.second);
        dfs(v, u);
        if (st.back().first == h[v]) {
            M.push_back({st.back().second});
            st.pop_back();
        }
    }
}

struct Edge {
    int to, c, f;

    Edge(int to, int c): to(to), c(c), f(0) {}
};

namespace Flow {
    int N, S, T;
    vector<Edge> edges;
    vector<int> g[maxn];

    void addEdge(int u, int v, int c) {
        g[u].push_back(sz(edges));
        edges.emplace_back(v, c);
        g[v].push_back(sz(edges));
        edges.emplace_back(u, 0);
    }

    int level[maxn];
    bool bfs() {
        forn (i, N)
            level[i] = inf;
        level[S] = 0;
        queue<int> o;
        o.push(S);
        while (!o.empty()) {
            int u = o.front();
            o.pop();
            for (int id: g[u]) {
                if (edges[id].c == edges[id].f)
                    continue;
                int v = edges[id].to;
                if (level[v] != inf)
                    continue;
                level[v] = level[u] + 1;
                o.push(v);
            }
        }
        return level[T] != inf;
    }

    int ptr[maxn];
    int dfs(int u, int f) {
        if (u == T)
            return f;
        int res = 0;
        for (int &i = ptr[u]; i < sz(g[u]); ++i) {
            int id = g[u][i];
            if (edges[id].c == edges[id].f)
                continue;
            int v = edges[id].to;
            if (level[v] != level[u] + 1)
                continue;
            int delta = min(edges[id].c - edges[id].f, f);
            delta = dfs(v, delta);
            edges[id].f += delta;
            edges[id ^ 1].f -= delta;
            f -= delta;
            res += delta;
            if (f == 0)
                break;
        }
        return res;
    }

    int run() {
        int res = 0;
        while (bfs()) {
            forn (i, N)
                ptr[i] = 0;
            int cres = dfs(S, inf);
            res += cres;
        }
        return res;
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n, m;
    cin >> n >> m;
    set<pii> edges;
    forn (i, m) {
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v, --c;
        assert(u != v);
        if (u > v)
            swap(u, v);
        edges.emplace(u, v);
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }
    assert(sz(edges) == m);
    int root = 0;
    st.emplace_back(0, -1);
    dfs(root);
    forn (i, n)
        assert(used[i]);
    //for (auto m: M) {
        //for (int x: m)
            //cerr << x << ' ';
        //cerr << '\n';
    //}
    Flow::N = m + sz(M) + 10;
    int S = Flow::N - 2;
    int T = Flow::N - 1;
    Flow::S = S;
    Flow::T = T;
    forn (i, sz(M)) {
        for (int x: M[i]) {
            assert(x < m);
            Flow::addEdge(x, m + 5 + i, 1);
        }
        Flow::addEdge(m + 5 + i, T, max(1, sz(M[i]) - 1));
    }
    forn (i, m + 5)
        Flow::addEdge(S, i, 1);
    int res = Flow::run();
    cout << res << '\n';
}