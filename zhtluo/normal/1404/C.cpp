#include <bits/stdc++.h>

int N, Q;
int A[310000];
int X[310000], Y[310000];
int tr[310000 * 4];
int pa[310000];
std::vector <int> q[310000];
std::vector <int> p[310000];
int res[310000];

void add(int n) {
    while (n <= N) {
        ++tr[n];
        n += (n & (-n));
    }
}

int query(int n) {
    int res = 0;
    while (n) {
        res += tr[n];
        n -= (n & (-n));
    }
    return res;
}

int main() {
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        A[i] = (i + 1) - A[i];
        if (A[i] < 0) A[i] = N + 1;
    }
    for (int i = 0; i < Q; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        X[i] = a; Y[i] = N - 1 - b;
        q[X[i]].push_back(i);
    }
    for (int i = 0; i < N; ++i) {
        int l = 0, r = i, ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (query(N - m) >= A[i]) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (ans >= 0) {
            pa[i] = ans;
            add(N - ans);
            p[pa[i]].push_back(i);
        } else {
            pa[i] = N;
        }
//        printf(": %d %d\n", i, pa[i]);
    }
    std::fill(tr, tr + N + 1, 0);
    for (int i = N - 1; i >= 0; --i) {
        for (int j : p[i]) add(j + 1);
        for (int j : q[i]) res[j] = query(Y[j] + 1);
    }
    for (int i = 0; i < Q; ++i) printf("%d\n", res[i]);
}