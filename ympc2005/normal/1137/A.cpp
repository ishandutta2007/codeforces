#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, a[N][N], b[N][N], c[N][N], d[N], e[N], val[N];

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin>>a[i][j];
            val[j] = a[i][j];
        }

        sort(val + 1, val + m + 1);
        d[i] = unique(val + 1, val + m + 1) - val - 1;

        for (int j = 1; j <= m; j++) {
            b[i][j] = lower_bound(val + 1, val + d[i] + 1, a[i][j]) - val;
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            val[i] = a[i][j];
        }

        sort(val + 1, val + n + 1);
        e[j] = unique(val + 1, val + n + 1) - val - 1;

        for (int i = 1; i <= n; i++) {
            c[i][j] = lower_bound(val + 1, val + e[j] + 1, a[i][j]) - val;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout<<max(b[i][j], c[i][j]) + max(d[i] - b[i][j], e[j] - c[i][j])<<' ';
        }

        cout<<'\n';
    }
}