#include <bits/stdc++.h>
using namespace std;

const int N = 200006;
int a[N];
int pre[N];

void go() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
  }
  int ans = 0;
  for (int i = 0, j = n, tot = 0; j >= 1; --j) {
    tot += a[j];
    while (pre[i] < tot) {
      ++i;
    }
    if (pre[i] == tot && i < j) {
      ans = max(ans, i + (n - j + 1));
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