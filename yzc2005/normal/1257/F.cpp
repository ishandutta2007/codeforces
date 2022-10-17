#include <bits/stdc++.h>
const int N = 105, K = 1 << 15;
int n, a[N], pop[K];
int main() {
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  for (int i = 0; i < K; ++i) {
    pop[i] = pop[i >> 1] + (i & 1);
  }
  std::map<std::vector<int>, int> lef;
  for (int x = 0; x < K; ++x) {
    std::vector<int> y;
    for (int i = 1, last = 0; i <= n; ++i) {
      int val = pop[((a[i] >> 15) ^ x) & (K - 1)];
      if (i > 1) {
        y.push_back(val - last);
      }
      last = val;
    }
    lef[y] = x;
  }
  for (int x = 0; x < K; ++x) {
    std::vector<int> y;
    for (int i = 1, last = 0; i <= n; ++i) {
      int val = pop[(a[i] ^ x) & (K - 1)];
      if (i > 1) {
        y.push_back(last - val);
      }
      last = val;
    }
    if (lef.count(y)) {
      printf("%d\n", (lef[y] << 15) | x);
      return 0;
    }
  }
  puts("-1");
  return 0;
}