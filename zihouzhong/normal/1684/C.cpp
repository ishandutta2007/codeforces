#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, m, a[maxn], b[maxn];

int id(int x, int y) {
    return (x - 1) * m + y;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        int p = 0, q = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &a[id(i, j)]), b[j] = a[id(i, j)];
            }
            sort(b + 1, b + m + 1);
            for (int j = 1; j <= m; j++) if (a[id(i, j)] ^ b[j]) {
                if (!p) p = j;
                else if (p != j && !q) q = j;
            }
        }
        if (!p && !q) {
            puts("1 1");
        } else {
            bool flag = 1;
            for (int i = 1; i <= n; i++) {
                swap(a[id(i, p)], a[id(i, q)]);
                for (int j = 1; j < m; j++) {
                    flag &= a[id(i, j)] <= a[id(i, j + 1)];
                }
            }
            if (flag) printf("%d %d\n", p, q);
            else puts("-1");
        }
    }
    return 0;
}