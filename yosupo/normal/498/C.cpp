#include <iostream>
#include <cstdio>
#include <complex>
#include <set>
#include <vector>
#include <stack>
#include <tuple>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
template<int V>
struct MaxFlow {
    using T = int;
    const T INF = 1<<28;
    struct Edge {
        int to, rev;
        T cap;
    };
    vector<Edge> g[V];
    int level[V];
    int iter[V];

    void add(int from, int to, T cap) {
        if (!cap) return;
        g[from].push_back(Edge{to, (int)g[to].size(), cap});
        g[to].push_back(Edge{from, (int)g[from].size()-1, 0});
    }

    void add_multi(int from, int to, T cap) {
        g[from].push_back(Edge{to, (int)g[to].size(), cap});
        g[to].push_back(Edge{from, (int)g[from].size()-1, cap});
    }

    void bfs(int s) {
        fill_n(level, V, -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for (Edge e: g[v]) {
                if (e.cap <= 0) continue;
                if (level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    T dfs(int v, int t, T f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < g[v].size(); i++) {
            Edge &e = g[v][i];
            if (e.cap <= 0) continue;
            if (level[v] < level[e.to]) {
                T d = dfs(e.to, t, min(f, e.cap));
                if (d <= 0) continue;
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }

    T exec(int s, int t) {
        T flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill_n(iter, V, 0);
            T f;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
    }
};

const int MN = 210;
int main() {
    int n, m;
    cin >> n >> m;
    int a[MN];
    vector<P> mv;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int b = a[i];
        for (int j = 2; j*j <= a[i]; j++) {
            if (b % j == 0) s.insert(j); 
            while (b % j == 0) {
                b /= j;
            }
        }
        if (b > 1) s.insert(b);
    }
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b; a--; b--;
        if (a % 2 == 1) swap(a, b);
        mv.push_back(P(a, b));
    }
    vector<int> v(s.begin(), s.end());
    int vs = n, vt = vs+1;
    int res = 0;
    for (int d: v) {
        MaxFlow<MN> mf;
        for (P p: mv) {
            mf.add(p.first, p.second, 100000);
        }
        for (int i = 0; i < n; i += 2) {
            int u = 0;
            while (a[i] % d == 0) {
                u++;
                a[i] /= d;
            }
            mf.add(vs, i, u);
        }
        for (int i = 1; i < n; i += 2) {
            int u = 0;
            while (a[i] % d == 0) {
                u++;
                a[i] /= d;
            }
            mf.add(i, vt, u);
        }
        res += mf.exec(vs, vt);
    }
    cout << res << endl;
    return 0;
}