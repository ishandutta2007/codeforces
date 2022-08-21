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
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

template <class E>
using Graph = vector<vector<E>>;

struct Centroid {
    int r;
    Graph<int> cg;
    vector<int> par;
    vector<bool> used;

    using P = pair<int, int>;
    vector<P> info; //(child max, child)
    template<class E>
    int dfs(const Graph<E> &g, int p, int b) {
        int sz = 1;
        info[p] = P(0, -1);
        for (E e: g[p]) {
            int d = e.to;
            if (d == b || used[d]) continue;
            int csz = dfs(g, d, p);
            sz += csz;
            info[p] = max(info[p], P(csz, d));
        }
        return sz;
    }
    template<class E>
    int init(const Graph<E> &g, int p, int b) {
        int sz = dfs(g, p, -1);
        while (info[p].first > sz/2) p = info[p].second;
        par[p] = b;
        used[p] = true;
        for (E e: g[p]) {
            int d = e.to;
            if (used[d]) continue;
            cg[p].push_back(init(g, d, p));
        }
        return p;
    }
    Centroid() {}
    template<class E>
    Centroid(const Graph<E> &g) {
        int n = (int)g.size();
        cg = Graph<int>(n);
        par = vector<int>(n);
        used = vector<bool>(n, false);
        info = vector<P>(n);
        r = init(g, 0, -1);
    }
};

struct Edge {
	int to;
};

Graph<Edge> g;
Centroid cent;

V<int> res;
void dfs(int p, int dps = 0) {
    res[p] = dps;
    for (int d: cent.cg[p]) {
        dfs(d, dps+1);
    }
}

int n;
using P = pair<int, int>;
VV<int> lis;
map<P, int> idx;
map<P, int> used;
V<int> buf;
void dfs(int a, int b, int id) {
    if (used.count(P(a, b))) return;
    buf.push_back(a);
    used[P(a, b)] = id;
    int pos = idx[P(b, a)];
    pos = (pos+1) % lis[b].size();
    dfs(b, lis[b][pos], id);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int m;
    cin >> n >> m;
    if (m == 0) {
        cout << 1 << endl;
        return 0;
    }
    lis = VV<int>(n);
    for (int i = 0; i < n; i++) {
        lis[i].push_back((i+1)%n);
        lis[i].push_back((i+n-1)%n);
    }
    V<P> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        edges.push_back(P(a, b));
        lis[a].push_back(b);
        lis[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        sort(begin(lis[i]), end(lis[i]), [&](int l, int r){
            return ((l+n-i)%n < (r+n-i)%n);
        });
        for (int j = 0; j < int(lis[i].size()); j++) {
            idx[P(i, lis[i][j])] = j;
        }
    }
/*    cout << "EDGE" << endl;
    for (int i = 0; i < n; i++) {
        for (int d: lis[i]) {
            cout << d << ", ";
        }cout << endl;
    }
    cout << "END" << endl;*/
    int idc = 0;
    VV<int> vs;
    for (int i = 0; i < n; i++) {
        for (int j: lis[i]) {
            if (used.count(P(i, j))) continue;
            buf.clear();
            dfs(i, j, idc);
/*            for (int d: buf) {
                cout << d << ", ";
            }
            cout << endl;*/
            if (buf.size() == n) continue;
            sort(begin(buf), end(buf), greater<int>());
            vs.push_back(buf);
            idc++;
        }
    }
    int N = idc;
    V<int> v(N), rv(N);
    iota(begin(v), end(v), 0);
    sort(begin(v), end(v), [&](int l, int r){
        return vs[l] < vs[r];
    });
    for (int i = 0; i < N; i++) {
        rv[v[i]] = i;
    }
    g = Graph<Edge>(N);
    for (auto p: edges) {
        int x, y; tie(x, y) = p;
        int a = rv[used[P(x, y)]];
        int b = rv[used[P(y, x)]];
        g[a].push_back(Edge{b});
        g[b].push_back(Edge{a});
    }
    cent = Centroid(g);
    res = V<int>(N);
    dfs(cent.r);
    for (int i = 0; i < N; i++) {
        cout << res[i]+1 << " ";
    } cout << endl;
    return 0;
}