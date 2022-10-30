#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10;

int n, q, fa[N], col[N], sz[N], ch[N][2], tot, rev[N];

vector <int> e[N];

struct DS {
    int mx, t[N];

    void upd_(int x, int k) {
        for (; x <= mx; x += x&-x) {
            t[x] += k;
        }
    }

    int ask_(int x, int res = 0) {
        for (; x; x -= x&-x) {
            res += t[x];
        }

        return res;
    }
} B;

void dfs_(int u) {
    col[u] = u;

    for (int v : e[u]) {
        if (v != fa[u]) {
            fa[v] = u;
            dfs_(v);

            if (col[v] > col[u]) {
                col[u] = col[v];
                sz[u] = sz[v];
                ch[u][1] = v;
            }
        }
    }

    sz[u]++;
}

bool isr_(int x) {
    return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
}

int chk_(int x) {
    return ch[fa[x]][1] == x;
}

void rev_(int x) {
    if (x) {
        rev[x] ^= 1;
        swap(ch[x][0], ch[x][1]);
    }
}

void down_(int x) {
    if (rev[x]) {
        rev_(ch[x][0]);
        rev_(ch[x][1]);
        rev[x] = 0;
    }

    col[ch[x][0]] = col[ch[x][1]] = col[x];
}

void up_(int x) {
    sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
}

void rotate_(int x) {
    int y = fa[x], z = fa[y], k = chk_(x), w = ch[x][k^1];

    if (!isr_(y)) {
        ch[z][chk_(y)] = x;
    }

    fa[x] = z, fa[y] = x, fa[w] = y;
    ch[x][k^1] = y, ch[y][k] = w;
    up_(y);
    up_(x); 
}

void pull_(int x) {
    if (!isr_(x)) {
        pull_(fa[x]);
    }

    down_(x);
}

void splay_(int x) {
    pull_(x);

    for (int p; p = fa[x], !isr_(x); rotate_(x)) {
        if (!isr_(p)) {
            rotate_(chk_(x) == chk_(p) ? p : x);
        }
    }
}

void access_(int x) {
    for (int p = 0; x; p = x, x = fa[x]) {
        splay_(x);
        ch[x][1] = 0;
        up_(x);
        B.upd_(col[x], -sz[x]);
        B.upd_(tot, sz[x]);
        ch[x][1] = p;
    }
}

void set_(int x) {
    ++tot;
    access_(x);
    splay_(x);
    rev_(x);
    col[x] = tot; 
}

int calc_(int x) {
    splay_(x);
    return B.ask_(col[x] - 1) + sz[ch[x][1]] + 1;
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;

    for (int u, v, i = 1; i < n; i++) {
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    B.mx = n + q;
    dfs_(n);
    tot = n;

    for (int i = 1; i <= n; i++) {
        if (isr_(i)) {
            B.upd_(col[i], sz[i]);
        }
    }

    for (int x, y, i = 1; i <= q; i++) {
        string op;
        cin>>op;

        if (op[0] == 'u') {
            cin>>x;
            set_(x);
        }

        if (op[0] == 'w') {
            cin>>x;
            cout<<calc_(x)<<'\n';
        }

        if (op[0] == 'c') {
            cin>>x>>y;
            cout<<(calc_(x) < calc_(y) ? x : y)<<'\n';
        }
    }
}