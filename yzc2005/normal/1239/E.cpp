#include <bits/stdc++.h>
const int N = 26, M = 50006;
int n, a[3][N], b[2 * N], f[N][M * N];
int main() {
  std::cin >> n;  
  std::multiset<int> nums;
  for (int i = 1; i <= 2 * n; ++i) {
    std::cin >> b[i];
  }
  std::sort(b + 1, b + 2 * n + 1);
  a[1][1] = b[1], a[2][n] = b[2];
  int sum = 0;
  f[0][0] = 19260817;
  for (int i = 3; i <= 2 * n; ++i) {
    sum += b[i];
    nums.insert(b[i]);
    for (int k = n - 1; k; --k) {
      for (int j = sum; j >= b[i]; --j) {
        if (!f[k][j] && f[k - 1][j - b[i]]) {
          f[k][j] = i;
        }
      } 
    }
  }
  for (int i = sum / 2; ~i; --i) {
    if (f[n - 1][i]) {
      for (int k = n; k != 1; i -= b[f[--k][i]]) {
        int val = b[f[k - 1][i]];
        a[1][k] = val;
        nums.erase(nums.find(val));
      }
    }
  }
  for (int j = n - 1; !nums.empty(); ) {
    int val = *nums.begin();
    a[2][j--] = val;
    nums.erase(nums.find(val)); 
  }
  for (int i = 1; i <= 2; ++i)
    for (int j = 1; j <= n; ++j)
      printf("%d%c", a[i][j], " \n"[j == n]);
  return 0;
}