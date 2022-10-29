#include <bits/stdc++.h>
using namespace std;

const int N = 3006;
int a[N];
int pre[N][N];

void go() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            pre[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[j] == i) {
                pre[i][j] = pre[i][j - 1] + 1;
            }
            else {
                pre[i][j] = pre[i][j - 1];
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            ans += pre[ a[j] ][i - 1] * (pre[ a[i] ][n] - pre[ a[i] ][j]);
        }
    }
    printf("%lld\n", ans);
}

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        go();
    }
}