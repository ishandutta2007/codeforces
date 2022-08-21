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
    rng(int r) : l(0), r(max(0, r)) {}
    rng(int l, int r) : l(l), r(max(l, r)) {}
    A begin() { return A{l}; }
    A end() { return A{r}; }
};

struct UnionFind {
    vector<int> p, r;
    int gn;
    UnionFind(int N) {
        p.resize(N); r.resize(N);
        fill(begin(p), end(p), -1);
        fill(begin(r), end(r), 1);
        gn = N;
    }
    void merge(int a, int b) {
        int x = group(a), y = group(b);
        if (x == y) return; //same
        gn--;
        if (r[x] < r[y]) p[x] = y;
        else if (r[x] > r[y]) p[y] = x;
        else {p[x] = y; r[x]++;}
    }
    int group(int a) {
        if (p[a] == -1) return a;
        return p[a] = group(p[a]);
    }
    bool same(int a, int b) {
        return group(a) == group(b);
    }
    void clear(int i) {
        p[i] = -1;
        r[i] = 1;
    }
};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> U(m), V(m), W(m);
    for (int i: rng(m)) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w); u--; v--;
        U[i] = u; V[i] = v; W[i] = w;
    }
    vector<int> idx(m);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int a, int b){ return W[a] < W[b]; });
    vector<bool> ok(m);

    vector<int> nxU(m), nxV(m);
    ll ans = 0;
    UnionFind uf(n);
    int l = 0;
    while (l < m) {
        int r = l;
        while (r < m && W[idx[l]] == W[idx[r]]) r++;
        for (int i: rng(l, r)) {
            int u = U[idx[i]], v = V[idx[i]];
            ok[idx[i]] = (uf.same(u, v) == false);
            nxU[idx[i]] = uf.group(u);
            nxV[idx[i]] = uf.group(v);
//            cout << "res " << idx[i] << " " << ok[idx[i]] << endl;
        }
        for (int i: rng(l, r)) {
            int u = U[idx[i]], v = V[idx[i]];
            uf.merge(u, v);
        }
        l = r;
    }

    for (int i: idx) {
        uf.clear(U[i]);
        uf.clear(V[i]);
    }

    int q;
    scanf("%d", &q);
    for (int ph: rng(q)) {
        int k;
        scanf("%d", &k);
        bool res = true;
        vector<int> idx(k);
        for (int i: rng(k)) {
            int x;
            scanf("%d", &x); x--;
            idx[i] = x;
            if (!ok[x]) res = false;
        }

        sort(begin(idx), end(idx), [&](int a, int b){ return W[a] < W[b]; });

        int l = 0;
        while (l < k) {
            int r = l;
            while (r < k && W[idx[r]] == W[idx[l]]) r++;
            for (int i: rng(l, r)) {
                int u = nxU[idx[i]], v = nxV[idx[i]];
                if (uf.same(u, v)) {
                    res = false;
                    break;
                }
                uf.merge(u, v);
            }
            for (int i: rng(l, r)) {
                uf.clear(nxU[idx[i]]);
                uf.clear(nxV[idx[i]]);
            }            
            l = r;
        }
        if (res) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}