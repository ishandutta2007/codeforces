#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int T, n, a[N], id[N][4], tot, p[N];

namespace NF {
    struct Edge {
        int to, next, w; 
    } e[N*60];

    int h[N], d[N], cur[N], cnt, S, T;

    queue <int> q;

    void init_() {
        for (int i = 0; i <= tot; i++) {
            h[i] = 0;
        }

        cnt = 1;
    }

    void add_(int u, int v, int w) {
        e[++cnt] = (Edge) {v, h[u], w};
        h[u] = cnt;

        if (!(cnt&1)) {
            add_(v, u, 0);
        }
    }

    bool bfs_() {
        for (int i = 0; i <= tot; i++) {
            cur[i] = h[i];
            d[i] = 0;
        }

        d[S] = 1, q.push(S);
        
        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int v, i = h[u]; i; i = e[i].next) {
                v = e[i].to;

                if (!d[v] && e[i].w) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }

        return d[T];
    }

    int dfs_(int u, int lim) {
        if (u == T || !lim) {
            return lim;
        }

        int flow = 0, f;

        for (int v, &i = cur[u]; i; i = e[i].next) {
            v = e[i].to;

            if (d[u] + 1 == d[v] && (f = dfs_(v, min(lim, e[i].w)))) {
                lim -= f, flow += f;
                e[i].w -= f, e[i^1].w += f;

                if (!lim) {
                    break;
                }
            }
        }

        return flow;
    }

    int main_() {
        int ans = 0;
        S = 0, T = tot;

        while (bfs_()) {
            ans += dfs_(S, 1e9);
        }

        return ans;
    }
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n), tot = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            id[i][0] = ++tot;
            id[i][1] = ++tot;
            id[i][2] = ++tot;
            id[i][3] = ++tot;
        }

        sort(a + 1, a + n + 1);
        ++tot;
        NF :: init_();

        for (int i = 1; i <= n; i++) {
            p[a[i]] = i;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = a[i]*2; j <= a[n]; j += a[i]) {
                if (p[j]) {
                    int k = p[j];
                    NF :: add_(id[i][0], id[k][1], 1e9);
                    NF :: add_(id[i][0], id[k][3], 1e9);
                    NF :: add_(id[i][2], id[k][3], 1e9);
                }
            }

            NF :: add_(id[i][0], id[i][3], 1e9);
            NF :: add_(0, id[i][0], 1);
            NF :: add_(0, id[i][2], 1);
            NF :: add_(id[i][1], tot, 1);
            NF :: add_(id[i][3], tot, 1);
        }

        printf("%d\n", n - (2*n - NF :: main_()));

        for (int i = 1; i <= n; i++) {
            p[a[i]] = 0;
        }
    }
}