#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;



int main() {
    int n, m; cin >> n >> m;
    vector<vector<long long int>>edges(n);
    vector<long long int>touched(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        if (u > v) {
            swap(u, v);
        }
        edges[u].push_back(v);
        touched[u]++;
        touched[v]++;
    }

    vector<long long int>dp(n,1);
    dp[0] = 1;
    for (int i = 0; i < n - 1; ++i) {
        for (auto j : edges[i]) {
            dp[j] = max(dp[i] + 1, dp[j]);
        }
    }
    long long int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(dp[i] * touched[i], ans);
    }
    cout << ans << endl;
    return 0;
}