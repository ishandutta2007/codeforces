#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int a[1000][1000], b[1000][1000];
char g[1000][1000];
int w, h;


int sum(int a[1000][1000], int r1, int c1, int r2, int c2) {
  if (r1 > r2 || c2 > c2) return 0;
  return a[r2][c2] - a[r2][c1 - 1] - a[r1 - 1][c2] + a[r1 - 1][c1 - 1];
}

int main() {
  scanf("%d%d", &h, &w);
  for (int i = 1; i <= h; ++ i) {
    scanf("%s", g[i] + 1);
  }
  for (int i = 1; i <= h; ++ i) {
    for (int j = 1; j < w; ++ j) {
      if (g[i][j] == '.' && g[i][j + 1] == '.') a[i][j] = 1;
    }
  }
  for (int i = 1; i < h; ++ i) {
    for (int j = 1; j <= w; ++ j) {
      if (g[i][j] == '.' && g[i + 1][j] == '.') b[i][j] = 1;
    }
  }
  for (int i = 1; i <= h; ++ i) {
    for (int j = 1; j <= w; ++ j) {
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
      b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
    }
  }
  int q; scanf("%d", &q);
  for (int _ = 0; _ < q; ++ _) {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    printf("%d\n", sum(a, r1, c1, r2, c2 - 1) + sum(b, r1, c1, r2 - 1, c2));
  }
  return 0;
}