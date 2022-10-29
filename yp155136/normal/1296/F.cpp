#include <bits/stdc++.h>
using namespace std;

const int N = 5006;
vector<int> G[N];
int xx[N], yy[N], ee[N];

int par[N];
int par_eid[N];
int depth[N];

void dfs(int now, int p, int dep) {
    par[now] = p;
    depth[now] = dep;
    for (int eid: G[now]) {
        int to = (ee[eid] ^ now);
        if (to == p) continue;
        par_eid[to] = eid;
        dfs(to, now, dep + 1);
    }
}

int a[N], b[N], c[N];
int val[N];

bool gao(int pos, int v) {
    if (val[pos] == v) return true;
    if (val[pos] == -1) {
        val[pos] = v;
        return true;
    }
    return false;
}

int main () {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        xx[i] = x;
        yy[i] = y;
        ee[i] = (x ^ y);
        G[x].push_back(i);
        G[y].push_back(i);
    }
    dfs(1, 1, 1);
    int m; cin >> m;
    vector<int> idx;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        idx.push_back(i);
    }
    sort(idx.begin(), idx.end(), [](const int &x, const int &y) {
        return c[x] > c[y];
    });
    memset(val, -1, sizeof(val));
    for (int i: idx) {
        bool ok = false;
        int x = a[i], y = b[i];
        //ok = gao(x, c[i]) | gao(y, c[i]);
        while (x != y) {
            if (depth[x] > depth[y]) swap(x, y);
            ok |= gao(par_eid[y], c[i]);
            y = par[y];
        }
        if (!ok) {
            puts("-1");
            return 0;
        }
    }
    for (int i = 1; i <= n - 1; ++i) {
        printf("%d%c", (val[i] < 0 ? -val[i] : val[i]), " \n"[i == n - 1]);
    }
}