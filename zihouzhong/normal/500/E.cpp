#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, q, pos[maxn], len[maxn], mx[maxn], nxt[maxn][20], cost[maxn][20];
vector<pair<int, int>> Q[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &pos[i], &len[i]);
    }
    for (int i = n - 1; i; i--) {
        int cur = i + 1;
        mx[i] = pos[i] + len[i];
        while (cur && pos[cur] <= pos[i] + len[i]) {
            mx[i] = max(mx[i], mx[cur]), cur = nxt[cur][0];
        }
        nxt[i][0] = cur, cost[i][0] = pos[cur] - mx[i];
    }
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= n; i++) {
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
            cost[i][j] = cost[i][j - 1] + cost[nxt[i][j - 1]][j - 1];
        }
    }
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int ans = 0;
        for (int i = 19; ~i; i--) if (nxt[l][i] && nxt[l][i] <= r) {
            ans += cost[l][i], l = nxt[l][i];
        }
        printf("%d\n", ans);
    }
    return 0;
}