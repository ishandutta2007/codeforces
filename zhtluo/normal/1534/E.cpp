#include <bits/stdc++.h>

int N, K;
int sol[510];
int res[510][510];
int ans = 0;

int main() {
    scanf("%d%d", &N, &K);
    if (N % 2 == 1 && K % 2 == 0) {
        printf("-1\n");
        fflush(stdout);
        return 0;
    }
    for (int i = 1; i <= N; ++i) sol[i] = 1;
    int tot = N;
    while (tot % K != 0) tot += 2;
    int overflow = tot - N, left = 1;
    while (overflow > 0) {
        for (; left <= N && overflow > 0; left = left % N + 1) {
            sol[left] += 2; overflow -= 2;
        }
        while (tot % K != 0 || tot / K < sol[1]) tot += 2, overflow += 2;
    }
    // for (int i = 1; i <= N; ++i) printf("%d%c", sol[i], " \n"[i == N]);
    std::priority_queue<std::pair<int, int>> pq;
    for (int i = 1; i <= N; ++i) pq.push(std::make_pair(sol[i], i));
    for (int i = 0; i < tot / K; ++i) {
        printf("?");
        std::vector <int> out;
        for (int j = 0; j < K; ++j) {
            int l = pq.top().second; pq.pop();
            printf(" %d", l);
            --sol[l];
            out.push_back(l);
        }
        for (int &l: out) {
            if (sol[l] > 0) pq.push(std::make_pair(sol[l], l));
        }
        printf("\n"); fflush(stdout);
        int u; scanf("%d", &u); ans ^= u;
    }
    printf("! %d\n", ans);    
    fflush(stdout);
}