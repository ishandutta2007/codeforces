#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int M = 1e6 + 10;
int cnt[M+1];
int d[M+1][3][3];

void uax(int& a, int b) {
  a = max(a, b);
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
  }
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        if (j + k > cnt[i]) {
          continue;
        }
        for (int t = 0; t < 3; ++t) {
          if (j + k + t > cnt[i]) {
            continue;
          }
          int r = t + (cnt[i] - j - k - t) / 3;
          uax(d[i + 1][k][t], d[i][j][k] + r);
        }
      }
    }
  }
  cout << d[M][0][0] << '\n';
}