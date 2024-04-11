#include <bits/stdc++.h>
using namespace std;

const int maxn = 1510;
int n, a[maxn][maxn];
int u[maxn][maxn], d[maxn][maxn], l[maxn][maxn], r[maxn][maxn], c[maxn * maxn];
long long ans;

void add(int p, int v) {
    for (; p; p -= p & -p) c[p] += v;
}

int sum(int p) {
    int s = 0;
    for (; p <= n * n; p += p & -p) s += c[p];
    return s;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) l[i][j] = sum(a[i][j]), add(a[i][j], 1);
        for (int j = 1; j <= n; j++) add(a[i][j], -1);
        for (int j = n; j; j--) r[i][j] = sum(a[i][j]), add(a[i][j], 1);
        for (int j = n; j; j--) add(a[i][j], -1);
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) u[i][j] = sum(a[i][j]), add(a[i][j], 1);
        for (int i = 1; i <= n; i++) add(a[i][j], -1);
        for (int i = n; i; i--) d[i][j] = sum(a[i][j]), add(a[i][j], 1);
        for (int i = n; i; i--) add(a[i][j], -1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ans += (l[i][j] + r[i][j]) * (u[i][j] + d[i][j]);
        }
    }
    long long t = 1LL * n * (n - 1) / 2, all = t * t;
    printf("%lld\n", 2 * all - ans);
    return 0;
}