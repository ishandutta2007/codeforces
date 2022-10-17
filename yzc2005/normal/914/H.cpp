#include <bits/stdc++.h>
using namespace std;
using ui = unsigned int;
const int N = 205;
ui n, d, p, C[N][N], dp[N][N], sum[N];
int main() {
  cin >> n >> d >> p; 
  for (int i = 0; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
  }
  sum[1] = dp[1][0] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int cnt = 1; cnt <= d; ++cnt) {
      for (int j = 1; j < i; ++j) {
        int cur = 1ull * dp[j][cnt - 1] * sum[i - j] % p;
        dp[i][cnt] = (dp[i][cnt] + 1ull * cur * C[i - 2][j - 1]) % p;
      }
      if (cnt != d) sum[i] = (sum[i] + dp[i][cnt]) % p;
    } 
  } // rooted trees, id_father < id, number of children cnt
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int x = 0; x <= d; ++x) {
      for (int y = 0; y <= d - x; ++y) {
        if (y == 1) continue;
        ans = (ans + 1ull * dp[i][x] * dp[n - i + 1][y]) % p;
      }
    }
  }
  cout << 2ull * n * (n - 1) * ans % p << endl;
  return 0;
}