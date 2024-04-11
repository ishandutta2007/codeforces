#include <bits/stdc++.h>
const int N = 300005, K = 30;
int n, a[N], ch[N * K][2], sz[N * K], tot = 1;
long long sum[K][2];
inline void insert(int x, int y) {
  int p = 1;
  for (int k = K - 1; ~k; --k) { 
    int w = x >> k & 1;
    int &q = ch[p][w];
    if (!q) {
      q = ++tot;
    }
    sum[k][w] += sz[ch[p][w ^ 1]];
    ++sz[p = q];
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    insert(a[i], i);
  }
  long long ans = 0, num = 0;
  for (int k = 0; k < K; ++k) {
    if (sum[k][0] <= sum[k][1]) {
      ans += sum[k][0];
    } else {
      ans += sum[k][1];
      num |= 1 << k;
    }
  }
  printf("%lld %lld\n", ans, num);
}