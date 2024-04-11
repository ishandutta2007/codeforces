#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int ask(int u, const vector<int>& b) {
  cout << 1 << ' ' << (int) b.size() << ' ' << u;
  for (int x : b) {
    cout << ' ' << x;
  }
  cout << endl;
  int d;
  cin >> d;
  return d;
}

void solve() {
  int n;
  cin >> n;
  vector<int> b(n - 1);
  iota(b.begin(), b.end(), 2);
  int r = ask(1, b);
  while ((int) b.size() > 1) {
    vector<int> b1 = b;
    b1.resize((int) b.size() / 2);
    if (ask(1, b1) == r) {
      b = b1;
    } else {
      b.erase(b.begin(), b.begin() + (int) b.size() / 2);
    }
  }
  int v = b[0];
  b.clear();
  for (int i = 1; i <= n; ++i) {
    if (i != v) {
      b.push_back(i);
    }
  }
  int res = ask(v, b);
  cout << -1 << ' ' << res << endl;
}

signed main() {
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}