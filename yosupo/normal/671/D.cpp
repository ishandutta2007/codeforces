#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}
const ll INF = 1LL<<55;
struct Node {
    using NP = Node*;

    ll mi, lz;

    /*
     init_node, update, push
    */
    void init_node(int v) {
        mi = v;
        lz = 0;
    }
    void update() {
        assert(!lz);
        mi = min(l->mi, r->mi);
    }
    void push() {
        if (lz) {
            l->lzdata(lz);
            r->lzdata(lz);
            lz = 0;
        }
    }
    void lzdata(ll x) {
        mi += x; mi = min(mi, INF);
        lz += x; lz = min(lz, INF);
    }

    void add(int a, int b, ll x) {
        if (b <= 0 or sz <= a) return;
        if (a <= 0 and sz <= b) {
            lzdata(x);
            return;
        }
        push();
        l->add(a, b, x);
        r->add(a - sz/2, b - sz/2, x);
        update();
    }
    ll get(int a, int b) {
        if (b <= 0 or sz <= a) return INF;
        if (a <= 0 and sz <= b) {
            return mi;
        }
        push();
        return min(l->get(a, b), r->get(a-sz/2, b-sz/2));
    }

    NP l, r;
    int sz;
    Node(int sz, int d[]) : sz(sz) {
        init_node(d[0]);
        if (sz == 1) return;
        l = new Node(sz/2, d);
        r = new Node(sz - sz/2, d+sz/2);
        update();
    }
};

const int MN = 600300;
int m;
vector<int> g[MN];
vector<int> qdv[MN], quv[MN]; // query down/up v
int dps[MN];

int x[MN], y[MN], c[MN]; // x -> y -> 0

void first_dfs(int p, int b, int dp = 0) {
    dps[p] = dp;
    for (auto d: g[p]) {
        if (d == b) continue;
        first_dfs(d, p, dp+1);
    }
}

int nv[MN], nq[MN];
int ql[MN], qr[MN];
int vc = 0, qc = 0;
void second_dfs(int p, int b) {
    nv[p] = vc++;
    ql[p] = qc;
    for (auto q: qdv[p]) {
        nq[q] = qc++;
    }
    for (auto d: g[p]) {
        if (d == b) continue;
        second_dfs(d, p);
    }
    qr[p] = qc;
}

Node* tr;
void init() {
    int d[MN];
    for (int i = 0; i < m; i++) {
        d[nq[i]] = c[i];
    }
    tr = new Node(m, d);
}
ll dp[MN];
void dfs(int p, int b) {
    ll dsm = 0;
    for (auto d: g[p]) {
        if (d == b) continue;
        dfs(d, p);
        dsm += dp[d];
        dsm = min(dsm, INF);
    }

    tr->add(ql[p], ql[p]+(int)qdv[p].size(), dsm);
    for (auto d: g[p]) {
        if (d == b) continue;
        tr->add(ql[d], qr[d], dsm - dp[d]);
    }

    dp[p] = tr->get(ql[p], qr[p]);
    for (auto q: quv[p]) {
        tr->add(nq[q], nq[q]+1, INF);
    }

}

int main() {
    int n;
    scanf("%d %d", &n, &m);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        g[a].push_back(n+i);
        g[b].push_back(n+i);
        g[n+i].push_back(a);
        g[n+i].push_back(b);
    }
    first_dfs(0, -1);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", x+i, y+i, c+i); x[i]--; y[i]--;
        if (dps[x[i]] < dps[y[i]]) swap(x[i], y[i]);
        qdv[x[i]].push_back(i);
        quv[y[i]].push_back(i);
    }
    second_dfs(0, -1);
    init();
    dfs(0, -1);
    ll u = dp[0];
    if (u >= INF) {
        u = -1;
    }
    printf("%lld\n", u);
    return 0;
}