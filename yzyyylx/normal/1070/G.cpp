#pragma GCC optimize(2)
#pragma GCC optimize("inline")
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
int n, m, a[maxn], ans[maxn];
struct hero {
  int loc, h;
} b[maxn];
int vis[maxn], emp[maxn];

bool Solve(int aim) {
  // printf("solve aim = %d:\n", aim);
  memset(vis, 0, sizeof vis);
  memset(emp, 0, sizeof emp);
  for (int rd = 1; rd <= m; ++rd) {

    int now = -1;
    for (int i = 1; i <= m; ++i) {
      if (vis[i]) continue;
      // printf("calc... %d\n", i);
      bool flag = 1;
      int dir = (b[i].loc <= aim) ? 1 : -1;
      int H = b[i].h;
      for (int j = b[i].loc; !emp[j]; j += dir) {
        H += a[j];
        if (H < 0) {
          flag = 0;
          // printf("end point = %d\n", j);
          break;
        }
        if (j == aim) break;
      }
      if (flag) {
        now = i;
        break;
      }
    }
    if (now == -1) return 0;
    // printf("%d\n", now);

    vis[now] = 1;
    ans[rd] = now;
    int dir = (b[now].loc <= aim) ? 1 : -1;
    for (int j = b[now].loc; !emp[j]; j += dir) {
      emp[j] = 1;
      if (j == aim) break;
    }
  }
  return 1;
}

int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i)
    scanf("%d%d", &b[i].loc, &b[i].h);
  for (int i = 1; i <= n; ++i)
    scanf("%d", a + i);

  for (int i = 1; i <= n; ++i)
    if (Solve(i)) {
      printf("%d\n", i);
      for (int j = 1; j <= m; ++j) printf("%d ", ans[j]);
      return 0;
    }
  puts("-1");

  return 0;
}