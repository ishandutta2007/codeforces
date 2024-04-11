#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, m, col[N];
bool OK;

vector<pii> gg[N], g[N];

vector<array<int, 3>> ans;


void add_edge (int v, int u, int x) {
    g[v].pb ({ u, x });
    g[u].pb ({ v, x });
}
void dfs1 (int v, int p) {
    for (auto it : gg[v]) {
        int to = it.f;
        int w  = it.s;
        if (to == p)
            continue;
        if (w != -1) {
            int x = 0;
            while (w)
                x = x ^ (w & 1), w >>= 1;
            add_edge (v, to, x);
        }
        dfs1 (to, v);
    }
}

void dfs2 (int v, int x) {
    if (col[v] != -1) {
        OK &= (col[v] == x);
        return;
    }
    col[v] = x;
    for (auto it : g[v]) {
        int to = it.f;
        int w  = it.s;
        dfs2 (to, x ^ w);
    }
}

void dfs3 (int v, int p) {
    for (auto it : gg[v]) {
        int to = it.f;
        int w  = it.s;
        if (to == p)
            continue;
        if (w == -1)
            w = col[v] ^ col[to];
        ans.pb ({ v, to, w });
        dfs3 (to, v);
    }
}

void solve () {

    scanf ("%d%d", &n, &m);

    for (int i = 1; i < n; i++) {
        int v, u, x;
        scanf ("%d%d%d", &v, &u, &x);
        // cerr << v << " " << u << " " << x << endl;
        gg[v].pb ({ u, x });
        gg[u].pb ({ v, x });
    }
    for (int i = 0; i < m; i++) {
        int v, u, x;
        scanf ("%d%d%d", &v, &u, &x);
        add_edge (v, u, x);
    }
    // cerr << "A" << endl;

    OK = 1;
    for (int i = 1; i <= n; i++)
        col[i] = -1;

    dfs1 (1, 1);

    // cerr << "B" << endl;
    for (int i = 1; i <= n; i++)
        if (col[i] == -1)
            dfs2 (i, 0);
    if (!OK) {
        printf ("NO\n");
    } else {
        dfs3 (1, 1);
        printf ("YES\n");
        for (auto it : ans)
            printf ("%d %d %d\n", it[0], it[1], it[2]);
    }

    ans.clear ();
    for (int i = 1; i <= n; i++) {
        g[i].clear ();
        gg[i].clear ();
    }
}
int main () {
    int t = 1;
    scanf ("%d", &t);
    while (t--)
        solve ();
}