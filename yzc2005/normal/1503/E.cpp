#include <bits/stdc++.h>
const int P = 998244353;
const int N = 2025, M = N * 2;
int n, m, C[M][N], ans; 
int F(int n, int m) {
  if (n < 0 || m < 0) return 0;
  return C[n + m][n]; 
}
void solve(int n, int m, bool flag) {
  for (int c = 1; c < m; ++c) {
    int sum = 0;
    for (int r = n; r; --r) {
      int c1 = 1ll * F(r - 1, c) * F(n - r, c - 1) % P;
      int c2 = 1ll * F(r, m - c - 1) * F(n - r - 1, m - c) % P;
      if (!flag) sum = (sum + c2) % P;
      ans = (ans + 1ll * sum * c1) % P;
      if (flag) sum = (sum + c2) % P;
    }
  }
}
int main() {
  std::cin >> n >> m;
  for (int i = 0; i < M; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i && j < N; ++j)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
  }
  solve(n, m, false), solve(m, n, true);
  std::cout << ans * 2 % P << "\n";
  return 0;
}