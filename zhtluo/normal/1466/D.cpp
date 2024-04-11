#include <bits/stdc++.h>

int T, N;
int deg[110000];
int val[110000];
long long ans[110000];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &val[i]);
        }
        for (int i = 1; i <= N; ++i) deg[i] = 0;
        for (int i = 1, u, v; i <= N - 1; ++i) {
            scanf("%d%d", &u, &v);
            ++deg[u]; ++deg[v];
        }
        long long sum = 0;
        std::priority_queue<int> pq;
        for (int i = 1; i <= N; ++i) {
            sum += 1ll * val[i] * deg[i];
            for (int j = 0; j < deg[i] - 1; ++j) pq.push(-val[i]);
        }
        ans[0] = sum;
        for (int i = 1; i < N - 1; ++i) {
            sum += pq.top();
            pq.pop();
            ans[i] = sum;
        }
        for (int i = N - 2; i >= 0; --i) {
            printf("%lld%c", ans[i], " \n"[i == 0]);
        }
    }
}