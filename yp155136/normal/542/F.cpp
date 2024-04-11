#include <bits/stdc++.h>
using namespace std;

const int N = 2066;
const int M = 106;
const int magic = 100;
int t[N], q[N], qq[N];

vector<int> v[M];
int dp[M][N];

int main () {
    int n, T; scanf("%d%d", &n, &T);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &t[i], &q[i]);
        qq[i] = T - t[i];
        if (qq[i] > magic) qq[i] = magic;
        v[ qq[i] ].push_back(q[i]);
    }
    for (int i = magic; i >= 0; --i) {
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
        for (int j = 1; j < N; ++j) {
            int pre = 0;
            dp[i][j] = dp[i][j - 1];
            for (int k = 0; k <= (int)v[i].size(); ++k) {
                //select k items
                dp[i][j] = max(dp[i][j], pre + dp[i + 1][(j - k) * 2]);
                if (k == (int)v[i].size() || k == j) break;
                pre += v[i][k];
            }
        }
    }
    printf("%d\n", dp[0][1]);
}