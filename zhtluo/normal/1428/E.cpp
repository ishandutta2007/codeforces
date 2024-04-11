#include <bits/stdc++.h>

int N, K;
int A[110000];
std::priority_queue<std::tuple<long long, int, int>> pq;

long long comp(int size, int cut) {
    long long mul = size / cut;
    return 1ll * cut * (mul * mul) + 1ll * (size % cut) * ((mul + 1) * (mul + 1) - mul * mul);
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
    for (int i = 0; i < N; ++i)
        pq.push(std::make_tuple(comp(A[i], 1) - comp(A[i], 2), 1, i));
    for (int i = N; i < K; ++i) {
        long long det;
        int cut, ind;
        std::tie(det, cut, ind) = pq.top();
        pq.pop();
        ++cut;
        pq.push(std::make_tuple(comp(A[ind], cut) - comp(A[ind], cut + 1), cut, ind));
    }
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        long long det;
        int cut, ind;
        std::tie(det, cut, ind) = pq.top();
        pq.pop();
        ans += comp(A[ind], cut);
    }
    printf("%lld\n", ans);
}