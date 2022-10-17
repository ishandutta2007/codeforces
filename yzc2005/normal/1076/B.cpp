#include <bits/stdc++.h>
int main() {
  long long n;
  std::cin >> n;
  if (!(n & 1)) return std::cout << n / 2, 0;
  for (int i = 2; 1ll * i * i <= n; ++i) {
    if (n % i == 0) {
      return std::cout << (n - i) / 2 + 1, 0;
    }
  }
  std::cout << 1;
  return 0;
}