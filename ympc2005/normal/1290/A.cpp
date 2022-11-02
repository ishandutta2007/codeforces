#include <bits/stdc++.h>
using namespace std;

const int N = 3505;

int n, m, k, a[N], f[N][N], ans;

void work_() {
    cin>>n>>m>>k;
    k = min(k, m - 1);
    ans = 0;

    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    for (int i = 1; i <= m; i++) {
        f[i][i + n - m] = max(a[i], a[i + n - m]);
    }

    for (int i = n - m + 2; i <= n; i++) {
        for (int l = 1; l + i - 1 <= n; l++) {
            int r = l + i - 1;
            f[l][r] = min(f[l][r - 1], f[l + 1][r]);
        }
    }

    for (int i = 0; i <= k; i++) {
        ans = max(ans, f[i + 1][n - (k - i)]);
    }

    cout<<ans<<'\n';
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;

    while (T--) {
        work_();
    }
}