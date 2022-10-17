#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, q, a[N], ans[N], sum[N], lg[N];
vector<pair<int, int>> queries[N];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    a[i] = i - a[i];
  }
  for (int i = 1; i <= q; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    queries[n - y].push_back({x + 1, i});
  }
  for (int i = 2; i <= n; ++i) {
    lg[i] = lg[i >> 1] + 1;
  } 
  for (int i = 1, cnt = 0; i <= n; ++i) {
    if (a[i] >= 0 && a[i] <= cnt) {
      int pos = 0, cur = cnt;
      for (int k = lg[i]; ~k; --k) {
        if ((pos | (1 << k)) <= i && cur + sum[pos | (1 << k)] >= a[i]) {
          pos |= 1 << k;
          cur += sum[pos];       
        }
      }
      for (++pos; pos <= n; pos += pos & -pos) {
        --sum[pos];
      }
      ++cnt;
    }
    for (auto p : queries[i]) {
      int pos = p.first, id = p.second;
      ans[id] = cnt;
      for (; pos; pos -= pos & -pos) {
        ans[id] += sum[pos];
      }
    }
  }
  for (int i = 1; i <= q; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}