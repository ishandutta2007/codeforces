#include <bits/stdc++.h>
const int N = 505;
int main() {
  int n, m; std::cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      int a; std::cin >> a;
      std::cout << 720720 + ((i ^ j) & 1) * a * a * a * a << " \n"[j == m];
    }
  return 0;
}