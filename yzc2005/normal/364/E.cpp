#include <bits/stdc++.h>
using namespace std;
const int N = 2505, K = 10;
int n, m, k, sum[N][N], lef[K], rig[K];
char a[N][N];
long long ans;
inline int get(int x1, int y1, int x2, int y2) {
  return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
} 
void solve(int lx, int rx, int ly, int ry) {
  if (lx == rx && ly == ry) {
    ans += (a[lx][ly] == k);
    return;
  }
  if (ry - ly > rx - lx) {
    int mid = ly + ry >> 1;
    solve(lx, rx, ly, mid);
    solve(lx, rx, mid + 1, ry);
    for (int i = lx; i <= rx; ++i) {
      for (int x = 0; x <= k + 1; ++x) {
        lef[x] = ly - 1;
        rig[x] = ry + 1;
      }
      for (int j = i; j >= lx; --j) {
        for (int x = 0; x <= k + 1; ++x) {
          for (; get(j, lef[x] + 1, i, mid) >= x && lef[x] < mid; ++lef[x]); 
          for (; get(j, mid + 1, i, rig[x] - 1) >= x && rig[x] > mid + 1; --rig[x]);
        }
        for (int x = 0; x <= k; ++x) {
          ans += (lef[x] - lef[x + 1]) * (rig[k - x + 1] - rig[k - x]);
        }
      }
    }
  } else {
    int mid = lx + rx >> 1; 
    solve(lx, mid, ly, ry);
    solve(mid + 1, rx, ly, ry);
    for (int i = ly; i <= ry; ++i) {
      for (int x = 0; x <= k + 1; ++x) {
        lef[x] = lx - 1;
        rig[x] = rx + 1;
      }
      for (int j = i; j >= ly; --j) {
        for (int x = 0; x <= k + 1; ++x) {
          for (; get(lef[x] + 1, j, mid, i) >= x && lef[x] < mid; ++lef[x]);
          for (; get(mid + 1, j, rig[x] - 1, i) >= x && rig[x] > mid + 1; --rig[x]);
        }
        for (int x = 0; x <= k; ++x) {
          ans += (lef[x] - lef[x + 1]) * (rig[k - x + 1] - rig[k - x]);
          
        }
      }
    } 
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", a[i] + 1);
    for (int j = 1; j <= m; ++j) {
      a[i][j] -= '0';
      sum[i][j] = a[i][j];
    }
  }
  for (int i = 1; i <= n + 1; ++i) {
    for (int j = 1; j <= m + 1; ++j) {
      sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]; 
    }
  }
  solve(1, n, 1, m);
  printf("%lld\n", ans);
  return 0;
}