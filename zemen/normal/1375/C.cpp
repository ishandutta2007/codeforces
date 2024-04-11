#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve() {
  int n;
  cin >> n;
  vector<int> st;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    int y = x;
    while (!st.empty() && st.back() < x) {
      y = st.back();
      st.pop_back();
    }
    st.push_back(y);
  }
  cout << (st.size() == 1 ? "YES" : "NO") << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}