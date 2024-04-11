#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, vector<int>> pos;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  vector<int> b(n);
  while (!pos.empty()) {
    vector<int> p;
    for (auto it = pos.begin(); it != pos.end(); ) {
      p.push_back(it->second.back());
      it->second.pop_back();
      if (it->second.empty()) {
        it = pos.erase(it);
      } else {
        ++it;
      }
    }
    for (int i = 0; i < (int) p.size(); ++i) {
      int j = (i + 1) % (int) p.size();
      b[p[i]] = a[p[j]];
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << b[i] << ' ';
  }
  cout << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("f1.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}