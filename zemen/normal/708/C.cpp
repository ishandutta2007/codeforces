#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 400400;
const int ROOT = 0;
vector<int> g[maxn];
bool can[maxn];
int half;

int best1[maxn];
int best2[maxn];
int best3[maxn];
int bp1[maxn];
int bp2[maxn];
int cnt[maxn];
int mx1[maxn];
int mx2[maxn];
int where1[maxn];

void uax(int &a, int b) {
    a = max(a, b);
}

void dfs(int u, int prev = -1) {
    cnt[u] = 1;
    bp1[u] = bp2[u] = -1;
    for (int v: g[u]) {
        if (v == prev)
            continue;
        dfs(v, u);
        cnt[u] += cnt[v];
        if (best1[v] > best1[u]) {
            best3[u] = best2[u];
            best2[u] = best1[u];
            bp2[u] = bp1[u];
            best1[u] = best1[v];
            bp1[u] = v;
        } else if (best1[v] > best2[u]) {
            best3[u] = best2[u];
            best2[u] = best1[v];
            bp2[u] = v;
        } else if (best1[v] > best3[u])
            best3[u] = best1[v];

        if (cnt[v] > mx1[u]) {
            mx2[u] = mx1[u];
            mx1[u] = cnt[v];
            where1[u] = v;
        } else if (cnt[v] > mx2[u])
            mx2[u] = cnt[v];
    }
    if (cnt[u] <= half) {
        best3[u] = best2[u];
        best2[u] = best1[u];
        bp2[u] = bp1[u];
        best1[u] = cnt[u];
        bp1[u] = u;
    }
}

void dfs2(int u, int prev = -1, int cup = 0, int bup = 0) {
    //cerr << u << ' ' << mx1[u] << ' ' << best1[where1[u]] << '\n';
    if (cup - bup <= half && mx1[u] - best1[where1[u]] <= half)
        can[u] = true;
    for (int v: g[u]) {
        if (v == prev)
            continue;
        int bb = bup;
        int cc = cup + cnt[u] - cnt[v];
        if (bp1[u] == u || bp1[u] == v) {
            if (bp2[u] == u || bp2[u] == v)
                uax(bb, best3[u]);
            else
                uax(bb, best2[u]);
        } else
            uax(bb, best1[u]);
        if (cc <= half)
            bb = cc;
        dfs2(v, u, cc, bb);
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    half = n / 2;
    forn (i, n - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(ROOT);
    dfs2(ROOT);

    forn (i, n)
        cout << can[i] << ' ';
    cout << '\n';
}