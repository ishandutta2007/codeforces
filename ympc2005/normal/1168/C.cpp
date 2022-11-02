#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

int n, q, a[N], f[N][25], las[25];

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>q;

    for (int i = 1; i <= n; i++) {
        cin>>a[i];

        for (int j = 0; j <= 20; j++) {
            f[i][j] = n + 1;
        }
    }

    for (int j = 0; j <= 20; j++) {
        las[j] = n + 1;
        f[n + 1][j] = n + 1;
    }

    for (int i = n; i; i--) {
        for (int j = 0; j <= 20; j++) {
            if (a[i]&(1<<j)) {
                for (int k = 0; k <= 20; k++) {
                    f[i][k] = min(f[i][k], f[las[j]][k]);
                }

                las[j] = i;
                f[i][j] = i;
            }
        }
    }

    for (int u, v, i = 1; i <= q; i++) {
        cin>>u>>v;
        bool ok = 0;

        for (int j = 0; j <= 20; j++) {
            if (a[v]&(1<<j)) {
                ok |= f[u][j] <= v;
            }
        }

        cout<<(ok ? "Shi" : "Fou")<<'\n';
    }
}