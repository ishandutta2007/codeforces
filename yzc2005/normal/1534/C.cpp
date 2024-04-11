#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5, P = 1e9 + 7;
int n, p[N], q[N], to[N];
bool vis[N];
int main() {
  int t; for (scanf("%d", &t); t; --t) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i]), vis[i] = 0;
    for (int i = 1; i <= n; ++i) scanf("%d", &q[i]), to[p[i]] = q[i];
    int ans = 1;
    for (int i = 1; i <= n; ++i) if (!vis[i]) {
      int u = i; do {
        vis[u] = true;
        u = to[u];
      } while (u != i);
      ans = 1ll * ans * 2 % P;
    }
    printf("%d\n", ans);
  }
  return 0;
}