#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T, n, fa[25], e[25], cnt = 20;

char a[N], b[N];

bool f[1<<20];

int find_(int x) {
    return fa[x] == x ? x : fa[x] = find_(fa[x]);
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%s%s", &n, a + 1, b + 1);

        for (int i = 0; i < cnt; i++) {
            fa[i] = i;
            e[i] = 0;
        }

        int ans = cnt;

        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) {
                int u = a[i] - 'a', v = b[i] - 'a';

                if (find_(u) != find_(v)) {
                    fa[find_(u)] = find_(v);
                    ans++;
                }

                e[u] |= 1<<v;
            }
        }

        int mx = 0;
        f[0] = 1;

        for (int i = 1; i < (1<<cnt); i++) {
            int res = 0;
            f[i] = 0;

            for (int j = 0; j < cnt; j++) {
                if (i&(1<<j)) {
                    res++;

                    if (f[i^(1<<j)] && !(e[j]&(i^(1<<j)))) {
                        f[i] = 1;
                    }
                }
            }

            if (f[i]) {
                mx = max(mx, res);
            }
        }

        printf("%d\n", ans - mx);
    }
}