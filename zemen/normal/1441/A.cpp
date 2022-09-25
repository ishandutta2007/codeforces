#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n, k;
  cin >> n >> k;
  list<int> a;
  vector<list<int>::iterator> pos(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    a.push_back(x);
    pos[x] = prev(a.end());
  }
  vector<char> imp(n);
  vector<int> b(k);
  for (int i = 0; i < k; ++i) {
    cin >> b[i];
    --b[i];
    imp[b[i]] = true;
  }
  const int mod = 998244353;
  int ways = 1;
  for (int i = 0; i < k; ++i) {
    auto it = pos[b[i]];
    int cur = 0;
    if (it != a.begin() && !imp[*prev(it)]) {
      ++cur;
    }
    if (next(it) != a.end() && !imp[*next(it)]) {
      ++cur;
    }
    imp[b[i]] = false;
    a.erase(it);
    ways = (ways * cur) % mod;
  }
  cout << ways << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}