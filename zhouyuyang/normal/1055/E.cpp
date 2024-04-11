#include <bits/stdc++.h>
using namespace std;

const int N = 1500;

int n, m, k, s;
int dp[N + 5][N + 5];
int a[N + 5], b[N + 5], l[N + 5], r[N + 5], x[N + 5];

bool chk(int mid) {
    memset(dp, 0, sizeof dp);

    dp[1][0] = 0;
    for(int i = 1; i <= n; ++i) { b[i] = b[i-1] + (a[i] <= mid); }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if(x[i] > 0) dp[x[i] + 1][j + 1] = max(dp[x[i] + 1][j + 1], dp[i][j] + b[x[i]] - b[i-1]);
        }
    }
    return dp[n + 1][m] >= k;
}

int main() {
#ifdef Wearry
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    scanf("%d%d%d%d", &n, &s, &m, &k);
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);
    for(int i = 1; i <= s; ++i) {
        scanf("%d%d", l + i, r + i);
        for(int j = l[i]; j <= r[i]; ++j) x[j] = max(x[j], r[i]);
    }

    int L = 1, R = (int) 1e9;
    while(L < R) {
        int mid = (L + R) >> 1;
        if(chk(mid)) R = mid; else L = mid + 1;
    }
    printf("%d\n", chk(L) ? L : -1);

    return 0;
}