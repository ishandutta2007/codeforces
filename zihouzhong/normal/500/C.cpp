#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, m, ans, w[maxn], b[maxn], used[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        memset(used, 0, sizeof(used));
        for (int j = i - 1; j; j--) {
            if (b[i] == b[j]) break;
            if (!used[b[j]]) used[b[j]] = 1, ans += w[b[j]];
        }
    }
    printf("%d\n", ans);
    return 0;
}