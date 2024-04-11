#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

int n, m, T;

bool vis[N];

void chk_(int x, int y) {
    if (!vis[x] && !vis[y]) {
        vis[x] = vis[y] = 1;
        printf("%d %d\n", x, y);
    }
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        if (n == 4 && m == 3) {
            puts("-1");
            continue;
        }

        for (int i = 0; i < n; i++) {
            vis[i] = 0;
        }

        int S = n - 1;

        if (m < S) {
            chk_(S, m);
            chk_(0, S^m);
        } else {
            chk_(S, S - 1);
            chk_(1, 3);
            chk_(0, S - 3);
        }

        for (int i = 0; i < n; i++) {
            chk_(i, i^(n - 1));
        }
    }
}