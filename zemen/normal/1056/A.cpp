#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  const int N = 101;
  bitset<N> b;
  for (int i = 0; i < N; ++i) {
    b[i] = 1;
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    bitset<N> a;
    int r;
    cin >> r;
    for (int j = 0; j < r; ++j) {
      int x;
      cin >> x;
      a[x] = 1;
    }
    b &= a;
  }
  for (int i = 0; i < N; ++i) {
    if (b[i]) {
      cout << i << ' ';
    }
  }
  cout << '\n';
}