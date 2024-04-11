#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int T, n, m, K, x[maxn], y[maxn], a[maxn], b[maxn], p[maxn], q[maxn];
int cx[maxn], cy[maxn];
map<int, int> mp1[maxn], mp2[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &K);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x[i]), cx[i] = 0;
            mp1[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &y[i]), cy[i] = 0;
            mp2[i].clear();
        }
        long long ans = 0;
        for (int i = 1; i <= K; i++) {
            scanf("%d %d", &p[i], &q[i]);
            a[i] = upper_bound(x + 1, x + n + 1, p[i]) - x - 1;
            b[i] = upper_bound(y + 1, y + m + 1, q[i]) - y - 1;
            if (x[a[i]] == p[i] && y[b[i]] == q[i]) continue;
            if (x[a[i]] == p[i]) {
                ans += cy[b[i]]++ - mp1[a[i]][b[i]]++;
            } else {
                ans += cx[a[i]]++ - mp2[b[i]][a[i]]++;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}