#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  int n;
  cin >> n;
  int cnt[2] = {0, 0};
  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;
    cnt[b == "hard"]++;
  }
  sort(cnt, cnt + 2);
  for (int i = 1; ; ++i) {
    int n = i * i;
    if (cnt[0] > n / 2 || cnt[1] > n - n / 2) {
      continue;
    }
    cout << i << '\n';
    break;
  }
}