#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

struct rng {
    struct A {
        int n;
        const bool operator!=(A r) { return n != r.n; }
        A& operator++() { n++; return *this; }
        int operator*() { return n; }
    };
    int l, r;
    rng(int r) : l(0), r(r) {}
    rng(int l, int r) : l(l), r(r) {}
    A begin() { return A{l}; }
    A end() { return A{r}; }
};

template<class D, D INF>
struct Dijkstra {
    V<D> res; //res[i] = si
    
    template<class E>
    Dijkstra(const VV<E> &g, int s) {
        int n = (int)g.size();
        res = V<D>(n, INF);
        
        using P = pair<D, int>;
        priority_queue<P, vector<P>, greater<P>> q;
        q.push(P(0, s));
        res[s] = 0;
        while (!q.empty()) {
            P p = q.top(); q.pop();
            if (res[p.second] < p.first) continue;
            for (E e: g[p.second]) {
                if (p.first+e.dist < res[e.to]) {
                    res[e.to] = p.first+e.dist;
                    q.push(P(res[e.to], e.to));
                }
            }
        }
    }
};

struct E {
    int to;
    int dist;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n, m, q;
    cin >> n >> m >> q;
    VV<E> g(n);
    using P = pair<int, int>;
    V<P> ed(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c; a--; b--;
        ed[i] = P(a, int(g[a].size()));
        g[a].push_back(E{b, c});
    }
    
    V<ll> sm = Dijkstra<ll, TEN(18)>(g, 0).res;
    V<int> pos(n);
    V<bool> cant(n);
    for (int i = 0; i < n; i++) cant[i] = (sm[i] == TEN(18));

    for (int i = 0; i < n; i++) {
        if (cant[i]) continue;
        for (auto &e: g[i]) {
            int j = e.to;
            e.dist -= sm[j] - sm[i];
        }
    }

    auto ref = [&]() {
        for (int i = 0; i < n; i++) {
            if (cant[i]) continue;
            for (auto &e: g[i]) {
                int j = e.to;
                e.dist -= pos[j] - pos[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (cant[i]) continue;
            sm[i] += pos[i];
            pos[i] = 0;
        }
    };

    int c = 0;
    V<bool> vis(n);
    for (int ph = 0; ph < q; ph++) {
        int ty;
        cin >> ty;
        if (ty == 1) {
            if (c) {
                fill(begin(pos), end(pos), TEN(9));
                fill(begin(vis), end(vis), false);
    
                VV<int> que(c+1);
                que[0].push_back(0);
                pos[0] = 0;
                for (int di = 0; di <= c; di++) {
                    while (que[di].size()) {
                        int p = que[di].back(); que[di].pop_back();
                        if (vis[p]) continue;
                        vis[p] = true;
                        for (auto e: g[p]) {
                            if (c < di + e.dist) continue;
                            if (pos[e.to] <= di + e.dist) continue;
                            pos[e.to] = di + e.dist;
                            que[di + e.dist].push_back(e.to);
                        }
                    }
                }
                ref();
                c = 0;                    
            }
            int v;
            cin >> v; v--;
            cout << (cant[v] ? -1 : sm[v]) << endl;
        } else {
            int x;
            cin >> x;
            for (int i = 0; i < x; i++) {
                int l;
                cin >> l; l--;
                g[ed[l].first][ed[l].second].dist++;
            }
            c += x;            
        }
    }
    return 0;
}