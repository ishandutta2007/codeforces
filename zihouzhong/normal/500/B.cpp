#include <bits/stdc++.h>
using namespace std;

const int maxn = 310;
int n, p[maxn], fa[maxn];
char s[maxn][maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    iota(fa + 1, fa + n + 1, 1);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for (int j = i + 1; j <= n; j++) {
            if (s[i][j] == '1') fa[find(i)] = find(j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (find(i) == find(j) && p[i] > p[j]) swap(p[i], p[j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", p[i]);
    }
    return 0;
}