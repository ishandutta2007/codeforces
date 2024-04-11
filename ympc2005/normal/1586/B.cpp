#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, T;

bool vis[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
        }

        int rt = 1;

        for (int a, b, c, i = 1; i <= m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            vis[b] = 1;
        }

        while (vis[rt]) {
            rt++;
        }

        for (int i = 1; i <= n; i++) {
            if (i != rt) {
                printf("%d %d\n", i, rt);
            }
        }
    }
}