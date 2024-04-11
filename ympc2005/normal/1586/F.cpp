#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m, ans, a[N][N];

void solve_(int l, int r, int k) {
    if (l >= r) {
        return;
    }

    ans = max(ans, k);

    int sz = (r - l)/m + 1;

    for (int i = l, j; i <= r; i = j + 1) {
        j = min(r, i + sz - 1);
        solve_(i, j, k + 1);

        for (int x = i; x <= j; x++) {
            for (int y = j + 1; y <= r; y++) {
                a[x][y] = k;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);

    solve_(1, n, 1);

    printf("%d\n", ans);

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            printf("%d\n", a[i][j]);
        }
    }
}