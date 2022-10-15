#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 998244353;
int T, n, a[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        int pos = n;
        while (pos && a[pos] == a[n]) pos--;
        int ans = 1;
        for (int i = 1; i <= n; i++) ans = 1LL * i * ans % P;
        if (pos < n - 1) {
            printf("%d\n", ans);
        } else {
            int o = pos;
            while (pos && a[pos] == a[n] - 1) pos--;
            int num = o - pos;
            ans = 1LL * ans * num % P * qp(num + 1, P - 2) % P;
            printf("%d\n", ans);
        }
    }
    return 0;
}