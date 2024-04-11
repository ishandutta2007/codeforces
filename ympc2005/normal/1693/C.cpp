#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 4e5 + 10;

int n, m, d[N], f[N];

vector <int> e[N], id[N];

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    for (int u, v, i = 1; i <= m; i++) {
        cin>>u>>v;
        e[v].push_back(u);
        d[u]++;
    }

    for (int i = 1; i <= n; i++) {
        f[i] = 1e9;
    }

    f[n] = 0, id[0].push_back(n);

    for (int i = 0; i <= m; i++) {
        for (int u : id[i]) {
            if (f[u] != i) {
                continue;
            }

            for (int v : e[u]) {
                if (f[u] + d[v] < f[v]) {
                    f[v] = f[u] + d[v];
                    id[f[v]].push_back(v);
                }

                d[v]--;
            }
        }
    }

    cout<<f[1]<<'\n';
}