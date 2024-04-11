#include <cstdio>
#include <memory.h>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

const int N = 1 << 18;

typedef long long llong;

const llong inf = 1e18;

llong W[N];

struct segtree {
    llong Tmn[2 * N], Tadd[2 * N];
    int Tind[2 * N];
    segtree() {
        for (int i = 1; i < 2 * N; i++) {
            Tmn[i] = inf, Tadd[i] = 0, Tind[i] = -1;
        }
    }
    void push(int v) {
        Tmn[v] += Tadd[v];
        if (v < N) {
            Tadd[2 * v] += Tadd[v];
            Tadd[2 * v + 1] += Tadd[v];
        }
        Tadd[v] = 0;
    }
    void recalc(int v) {
        assert(Tadd[v] == 0);
        if (make_pair(Tmn[2 * v] + Tadd[2 * v], Tind[2 * v]) < make_pair(Tmn[2 * v + 1] + Tadd[2 * v + 1], Tind[2 * v + 1])) {
            Tmn[v] = Tmn[2 * v] + Tadd[2 * v];
            Tind[v] = Tind[2 * v];
        } else {
            Tmn[v] = Tmn[2 * v + 1] + Tadd[2 * v + 1];
            Tind[v] = Tind[2 * v + 1];
        }
    }

    void set(int p, llong x, int ind, int L = 0, int R = N - 1, int v = 1) {
        if (L == R) {
            Tmn[v] = x;
            Tadd[v] = 0;
            Tind[v] = ind;
        } else {
            if (p <= (L + R) / 2) {
                set(p, x, ind, L, (L + R) / 2, 2 * v);
            } else {
                set(p, x, ind, (L + R) / 2 + 1, R, 2 * v + 1);
            }
            recalc(v);
        }
    }

    void add(int l, int r, llong x, int L = 0, int R = N - 1, int v = 1) {
        if (R < l || L > r)
            return;
        else if (l <= L && R <= r) {
            Tadd[v] += x;
        } else {
            push(v);
            add(l, r, x, L, (L + R) / 2, 2 * v);
            add(l, r, x, (L + R) / 2 + 1, R, 2 * v + 1);
            recalc(v);
        }
    }

    pair<llong, int> get(int l, int r, int L = 0, int R = N - 1, int v = 1) {
        if (r < L || l > R)
            return make_pair(inf, -1);
        if (l <= L && R <= r)
            return make_pair(Tmn[v] + Tadd[v], Tind[v]);
        push(v);
        auto resl = get(l, r, L, (L + R) / 2, 2 * v);
        auto resr = get(l, r, (L + R) / 2 + 1, R, 2 * v + 1);
        return min(resl, resr);
    }
} eul, hl;

vector<int> E[N];
vector<llong> gW[N];
int sz[N];

int tin[N], tout[N];
int curt = 0;
int par[N];
int D[N];

int segpt = 0;

int hlc[N], hlpos[N];
int cL[N], cR[N];
int ctop[N];
int ver[N];

const int lgN = 17;

int gpos[N];
int up[lgN][N];

void DFS1(int x, int p = -1) {
    if (p != -1) {
        E[x].erase(find(E[x].begin(), E[x].end(), p));
        D[x] = D[p] + 1;
        par[x] = p;
        up[0][x] = p;
    } else {
        par[x] = -1;
        up[0][x] = x;
    }
    for (int d = 1; d < lgN; d++)
        up[d][x] = up[d - 1][up[d - 1][x]];
    sz[x] = 1;
    tin[x] = curt++;
    for (int y : E[x]) {
        DFS1(y, x);
        sz[x] += sz[y];
    }
    tout[x] = curt;
}

int curc = 0;

void buildPath(int x, int y, int c) {
    cL[c] = segpt;
    cR[c] = segpt + D[x] - D[y];
    ctop[c] = y;
    segpt += D[x] - D[y] + 1;
    for (int v = x; v != par[y]; v = par[v]) {
        hlpos[v] = D[v] - D[y];

    }
}

void DFS2(int x, int c, int from) {
    int ind = -1;
    hlc[x] = c;
    for (int y : E[x]) {
        if (2 * sz[y] > sz[x]) {
            ind = y;
            DFS2(y, c, from);
        } else {
            DFS2(y, curc++, y);
        }
    }
    if (ind == -1) {
        buildPath(x, from, c);
    }
}

llong getWeight(int v) {
    return eul.get(tin[v], tin[v]).first;
}

int lca(int u, int v) {
    if (D[u] < D[v])
        swap(u, v);
    for (int d = lgN - 1; d >= 0; d--) {
        if (D[u] - (1 << d) >= D[v])
            u = up[d][u];
    }
    if (u == v)
        return u;
    for (int d = lgN - 1; d >= 0; d--) {
        if (up[d][u] != up[d][v])
            u = up[d][u], v = up[d][v];
    }
    return up[0][u];
}

pair<llong, int> extractGirlPath(int u, int v) {
    pair<llong, int> bst(inf, -1);
    while (true) {
        int c = hlc[u];
        int l = (hlc[u] == hlc[v]) ? hlpos[v] : 0;
        int r = hlpos[u];
        auto cur = hl.get(cL[c] + l, cL[c] + r);
        if (cur.second == -1)
            cur.first = inf;
        else
            cur.first = getWeight(cur.second);
        bst = min(bst, cur);
        if (hlc[u] == hlc[v])
            break;
        u = par[ctop[c]];
    }
    return bst;
}

pair<llong, int> extractGirl(int u, int v) {
    int l = lca(u, v);
    auto ul = extractGirlPath(u, l);
    auto vl = extractGirlPath(v, l);
    auto mn = min(ul, vl);
    return mn;
}

void pushGirl(int v) {
    assert(gpos[v] + 1 != gW[v].size());
    eul.add(tin[v], tin[v], gW[v][gpos[v] + 1] - gW[v][gpos[v]]);
    hl.add(cL[hlc[v]] + hlpos[v], cL[hlc[v]] + hlpos[v], gW[v][gpos[v] + 1] - gW[v][gpos[v]]);
    gpos[v]++;
}

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    DFS1(1, -1);
    DFS2(1, curc++, 1);
    memset(ver, -1, sizeof(ver));
    for (int i = 1; i <= m; i++) {
        int w = i;
        int v;
        scanf("%d", &v);
        gW[v].push_back(w);
    }
    for (int i = 1; i <= n; i++)
        gW[i].push_back(inf), gpos[i] = 0;

    for (int v = 1; v <= n; v++) {
        eul.set(tin[v], gW[v][0], v);
        hl.set(cL[hlc[v]] + hlpos[v], gW[v][0], v);
    }

    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int u, v, k;
            scanf("%d %d %d", &u, &v, &k);
            vector<int> output;
            for (int j = 0; j < k; j++) {
                auto g = extractGirl(u, v);
                if (g.first >= inf)
                    break;
                int v = g.second;
                assert(1 <= v && v <= n);
                output.push_back(gW[v][gpos[v]]);
                pushGirl(v);
            }
            printf("%d", (int)output.size());
            for (int i : output)
                printf(" %d", i);
            printf("\n");
        } else {
            int v, k;
            scanf("%d %d", &v, &k);
            eul.add(tin[v], tout[v] - 1, k);
            hl.add(cL[hlc[v]] + hlpos[v], cR[hlc[v]], k);
        }
    }
}