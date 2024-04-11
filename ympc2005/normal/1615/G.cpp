#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, m, a[N], id[N], tot, b[605][605], st[N], ed[N], cnt;

int pre[N], mat[N], col[N], tag[N], tim, fa[N];

bool vis[N];

vector <int> e[N], tmp;

queue <int> q;

int find_(int x) {
    return fa[x] == x ? x : fa[x] = find_(fa[x]);
}

int lca_(int u, int v) {
    ++tim, u = find_(u), v = find_(v);

    while (1) {
        if (!u) {
            swap(u, v);
        }

        if (tag[u] == tim) {
            return u;
        }

        tag[u] = tim;
        u = find_(pre[mat[u]]);
        swap(u, v);
    }
}

void shrink_(int u, int v, int rt) {
    while (find_(u) != rt) {
        pre[u] = v;
        v = mat[u];

        if (col[v] == 2) {
            col[v] = 1;
            q.push(v);
        }

        if (fa[u] == u) {
            fa[u] = rt;
        }

        if (fa[v] == v) {
            fa[v] = rt;
        }

        u = pre[v];
    }
}

void aug_(int u) {
    while (u) {
        mat[u] = pre[u];
        int v = mat[pre[u]];
        mat[pre[u]] = u;
        u = v;
    }
}

void bfs_(int s) {
    while (!q.empty()) {
        q.pop();
    }

    q.push(s), col[s] = 1, tmp.push_back(s);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v : e[u]) {
            if (!col[v]) {
                col[v] = 2, pre[v] = u;
                tmp.push_back(v);

                if (!mat[v]) {
                    aug_(v);
                    return;
                }

                col[mat[v]] = 1, tmp.push_back(mat[v]);
                q.push(mat[v]);
            } else if (col[v] == 1 && find_(u) != find_(v)) {
                int rt = lca_(u, v);
                shrink_(u, v, rt);
                shrink_(v, u, rt);
            }
        }
    }
}

void add_(int u, int v) {
    if (u && v) {
        e[u].push_back(v);
        e[v].push_back(u);
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        m = max(m, a[i]);
    }

    tot = m;

    for (int l = 1, r; l <= n; l = r + 1) {
        r = l;

        if (a[l]) {
            continue;
        }

        while (r < n && !a[r + 1]) {
            r++;
        }

        ++cnt;
        st[cnt] = l, ed[cnt] = r;

        if ((r - l + 1)&1) {
            id[cnt] = ++tot;
            add_(a[l - 1], tot);
            add_(a[r + 1], tot);
        } else {
            int u = min(a[l - 1], a[r + 1]), v = max(a[l - 1], a[r + 1]);

            if (u && !b[u][v]) {
                b[u][v] = cnt;
                add_(u, v);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i + 1] && a[i] && !vis[a[i]]) {
            add_(a[i], ++tot);
            vis[a[i]] = 1;
        }
    }

    for (int i = 1; i <= tot; i++) {
        fa[i] = i;
    }

    for (int i = 1; i <= tot; i++) {
        if (!mat[i]) {
            bfs_(i);

            for (int j : tmp) {
                fa[j] = j;
                col[j] = pre[j] = 0;
            }

            tmp.clear();
        }
    }
    

    queue <int> q;

    for (int i = 1; i <= m; i++) {
        if (!mat[i]) {
            q.push(i);
        }
    }

    for (int i = m + 1; i <= n; i++) {
        q.push(i);
    }

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    for (int i = 1; i <= cnt; i++) {
        int l = st[i], r = ed[i];

        if ((r - l + 1)&1) {
            if (mat[a[l - 1]] == id[i]) {
                for (int j = l + 1; j < r; j += 2) {
                    a[j] = a[j + 1] = q.front(); q.pop();
                }

                a[l] = max(1, a[l - 1]);
            } else {
                for (int j = l; j < r; j += 2) {
                    a[j] = a[j + 1] = q.front(); q.pop();
                }

                a[r] = max(1, a[r + 1]);
            }
        } else {
            int u = min(a[l - 1], a[r + 1]), v = max(a[l - 1], a[r + 1]);

            if (u && b[u][v] == i && mat[u] == v) {
                a[l] = a[l - 1];
                a[r] = a[r + 1];

                for (int j = l + 1; j < r; j += 2) {
                    a[j] = a[j + 1] = q.front(); q.pop();
                }
            } else {
                for (int j = l; j <= r; j += 2) {
                    a[j] = a[j + 1] = q.front(); q.pop();
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
}