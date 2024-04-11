#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q;
  std::cin >> n >> q;
  int s = 1 << n;
  std::vector<long long> sum(2 * s);
  for (int i = 0; i < s; ++i) {
    std::cin >> sum[s + i];
  }
  for (int i = s - 1; i; --i) {
    sum[i] = sum[i << 1] + sum[i << 1 | 1];
  }
  int tag = 0;
  while (q--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int x, k;
      std::cin >> x >> k;
      x = (x - 1) ^ tag;
      int delta = k - sum[s + x];
      for (int i = s + x; i; i >>= 1) {
        sum[i] += delta;
      }
    } else if (op == 2) {
      int k;
      std::cin >> k;
      tag ^= (1 << k) - 1;
    } else if (op == 3) {
      int k;
      std::cin >> k;
      tag ^= (1 << k);
    } else {
      int l, r;
      std::cin >> l >> r;
      --l;
      long long ans = 0; 
      for (int a = s + l, b = s + r, m = tag; a ^ b; a >>= 1, b >>= 1, m >>= 1) {
        if (a & 1) {
          ans += sum[(a++) ^ m];
        }
        if (b & 1) {
          ans += sum[(--b) ^ m];
        }
      }
      std::cout << ans << "\n"; 
    }
  }
  return 0;
}