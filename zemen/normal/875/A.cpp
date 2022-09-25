#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int sd(int x) {
  string s = to_string(x);
  int res = 0;
  for (auto c : s) {
    res += c - '0';
  }
  return res;
}

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<int> res;
  for (int i = max(1, n - 1000); i <= n; ++i) {
    int w = i + sd(i);
    if (w == n) {
      res.push_back(i);
    }
  }
  cout << int(res.size()) << '\n';
  for (int x : res)
    cout << x << ' ';
  cout << '\n';
}