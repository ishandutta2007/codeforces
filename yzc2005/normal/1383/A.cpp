#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 20;
int T, n;
char a[N], b[N]; 
int fa[M];
int get(int x) {return x == fa[x] ? x : fa[x] = get(fa[x]);}
int main() {
  for (scanf("%d", &T); T; --T) {
    scanf("%d%s%s", &n, a + 1, b + 1);
    bool ok = 1; int ans = 20;
    for (int i = 0; i < 20; ++i)
      fa[i] = i;
    for (int i = 1; i <= n; ++i) {
      a[i] -= 'a', b[i] -= 'a';
      if (a[i] != b[i]) {
        if (a[i] > b[i]) { ok = 0; break; }
        fa[get(a[i])] = get(b[i]);
      }
    }
    if (!ok) { puts("-1"); continue; }
    for (int i = 0; i < 20; ++i) 
      ans -= (fa[i] == i);
    printf("%d\n", ans);
  }
  return 0;
}