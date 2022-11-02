#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair <int, int> pii;

const int N = 1e5 + 10;

int n, rt, sz[N], mx[N], tot, d[N], p[N], fa[N], c[N], id[N], len;

struct Node {
    int p, q, d;

    bool operator < (const Node tmp) const {
        return d < tmp.d;
    }
};

ll L, R;

priority_queue <pii> q;

vector <int> e[N];

vector <Node> g[N];

bool vis[N];

ll K;

void find_(int u, int fa) {
    sz[u] = 1;

    for (int v : e[u]) {
        if (v == fa) {
            continue;
        }

        find_(v, u);
        mx[u] = max(mx[u], sz[v]);
        sz[u] += sz[v];

        if (sz[v]&1) {
            L++;
        }

        R += min(sz[v], n - sz[v]);
    }

    mx[u] = max(mx[u], n - sz[u]);

    if (!rt || mx[u] < mx[rt]) {
        rt = u;
    }
}

int dfs_(int u, int id) {
    d[u] = d[fa[u]] + 1, c[id]++;

    int p = u;

    for (int v : e[u]) {
        if (v == fa[u]) {
            continue;
        }

        fa[v] = u;

        int x = dfs_(v, id);

        if (p == -1) {
            p = x;
        } else if (~x) {
            g[id].push_back((Node) {p, x, d[u]});
            p = -1;
        }
    }

    return p;
}

void dfs1_(int u) {
    if (!vis[u]) {
        id[len++] = u;
    }

    for (int v : e[u]) {
        if (v != fa[u]) {
            dfs1_(v);
        }
    }

    //cout<<u<<' '<<vis[u]<<'\n';
}

int main() {
    scanf("%d%lld", &n, &K);

    for (int u, v, i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    find_(1, 0);

    if (K > R || K < L || (K&1) != (L&1)) {
        puts("NO");
        exit(0);
    }

    for (int x : e[rt]) {
        fa[x] = rt;
        dfs_(x, x);
        sort(g[x].begin(), g[x].end());
        q.push(pii(c[x], x));
    }

    while (R > K) {
        pii tmp = q.top(); q.pop();
        int u = tmp.second, x = g[u].back().p, y = g[u].back().q;;
        c[u] -= 2, q.push(pii(c[u], u));

        if (R - g[u].back().d*2 >= K) {
            vis[x] = vis[y] = 1;
            R -= g[u].back().d*2;
            g[u].pop_back();
            p[x] = y, p[y] = x;
        } else {
            int k = (R - K)/2;

            while (d[y] > k) {
                y = fa[y];
            }

            vis[x] = vis[y] = 1;
            p[x] = y, p[y] = x;
            break;
        }
    }

    dfs1_(rt);

    for (int i = 0; i < len/2; i++) {
        p[id[i]] = id[i + len/2];
        p[id[i + len/2]] = id[i];
    }

    puts("YES");

    for (int i = 1; i <= n; i++) {
        if (p[i] > i) {
            printf("%d %d\n", i, p[i]);
        }
    }
}