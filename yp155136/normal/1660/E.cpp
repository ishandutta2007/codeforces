#include <bits/stdc++.h>
using namespace std;

const int N = 2006;
int a[N][N];

void go() {
  int n; cin >> n;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c; cin >> c;
      // cin >> a[i][j];
      a[i][j] = c - '0';
      sum += a[i][j];
    }
  }
  int ans = n * n;
  for (int i = 0; i < n; ++i) {
    for (int del : {1}) {
      int tmp = 0;
      for (int j = 0; j < n; ++j) {
        int x = i + del * j;
        int y = j;
        x = (x % n + n) % n;
        tmp += a[x][y];
      }
      ans = min(ans, (n - tmp) + (sum - tmp));
    }
  }
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}