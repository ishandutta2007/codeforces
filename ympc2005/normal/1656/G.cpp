#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int T, n, a[N], p[N], fa[N];

vector <int> b[N];

int find_(int x) {
    return fa[x] == x ? x : fa[x] = find_(fa[x]);
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            b[i].clear();
            fa[i] = i;
        }

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[a[i]].push_back(i);
        }

        int cnt = 0, id = 0;

        for (int i = 1; i <= n; i++) {
            if (b[i].size()&1) {
                cnt++;
                id = i;
            }
        }

        if (cnt > 1 || (cnt == 1 && b[id].size() == 1 && b[id][0] == n/2 + 1)) {
            puts("NO");
            continue;
        }

        int cur = 0;

        for (int i = 1; i <= n; i++) {
            if (b[i].size()&1) {
                continue;
            }

            for (int j = 0; j < (int) b[i].size(); j += 2) {
                ++cur;
                p[cur] = b[i][j];
                p[n - cur + 1] = b[i][j + 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            if (b[i].size()&1) {
                for (int j = 1; j < (int) b[i].size(); j += 2) {
                    ++cur;
                    p[cur] = b[i][j];
                    p[n - cur + 1] = b[i][j + 1];
                }

                p[++cur] = b[i][0];

                if (p[cur] == cur) {
                    swap(p[cur], p[cur - 1]);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            fa[find_(i)] = find_(p[i]);
        }

        for (int i = 1; i <= n; i++) {
            if (find_(i) != find_(n - i + 1)) {
                swap(p[i], p[n - i + 1]);
                fa[find_(i)] = find_(n - i + 1);
            }
        }

        for (int i = 2; i <= n; i++) {
            if (find_(i) != find_(1)) {
                int p1 = p[1], pn = p[n], pi = p[i], qi = p[n - i + 1];
                p[1] = pi;
                p[i] = pn;
                p[n - i + 1] = p1;
                p[n] = qi;
                fa[find_(i)] = find_(1);
            }
        }

        puts("YES");

        for (int i = 1; i <= n; i++) {
            printf("%d ", p[i]);
        }

        puts("");
    }
}