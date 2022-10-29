#include <bits/stdc++.h>
using namespace std;

const int N = 303;

int a[N][N];

void go() {
    int n, m; scanf("%d%d", &n, &m);
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int tar = 4;
            if (i == 1 || i == n) --tar;
            if (j == 1 || j == m) --tar;
            scanf("%d", &a[i][j]);
            if (a[i][j] > tar) {
                flag = false;
            }
        }
    }
    if (!flag) {
        puts("NO");
        return;
    }
    puts("YES");
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int tar = 4;
            if (i == 1 || i == n) --tar;
            if (j == 1 || j == m) --tar;
            printf("%d%c", tar, " \n"[j == m]);
        }
    }
}

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        go();
    }
}