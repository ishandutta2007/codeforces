#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, d[N], rt1, rt2, fa[N];

vector <int> e[N];

void dfs_(int u) {
    d[u] = d[fa[u]] + 1;

    if (!rt1 || d[u] > d[rt1]) {
        rt1 = u;
    }

    for (int v : e[u]) {
        if (v != fa[u]) {
            fa[v] = u;
            dfs_(v);
        }
    }
}

void work_(int u) {
    d[u] = 1;

    if (fa[u] && e[u].size() == 3) {
        cout<<"No"<<'\n';
        exit(0);
    }

    for (int v : e[u]) {
        if (v != fa[u]) {
            fa[v] = u;
            work_(v);
            d[u] = max(d[u], d[v] + 1);
        }
    }

    for (int v : e[u]) {
        if (v != fa[u] && d[v] + 1 != d[u]) {
            cout<<"No"<<'\n';
            exit(0);
        }
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    for (int u, v, i = 1; i < n; i++) {
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    rt1 = 0;
    fa[1] = 0;
    dfs_(1);
    rt2 = rt1;
    rt1 = 0;
    fa[rt2] = 0;
    dfs_(rt2);

    if (d[rt1]%2 == 0) {
        cout<<"No"<<'\n';
        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        if (e[i].size() == 2) {
            cout<<"No"<<'\n';
            exit(0);
        }
    }

    int x = rt1;

    if (m != d[rt1]/2) {
        cout<<"No"<<'\n';
        exit(0);
    }

    for (int i = 1; i <= m; i++) {
        x = fa[x];
    }

    fa[x] = 0;
    work_(x);
    cout<<"Yes"<<'\n';
}