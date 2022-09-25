#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 200200;
int a[maxn];
int b[maxn];
vector<pair<int, int>> v;

signed main() {
#ifdef LOCAL
  assert(freopen("j.in", "r", stdin));
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    int p;
    cin >> p;
    v.emplace_back(b[i], p);
  }
  sort(v.begin(), v.end());

  a[n] = 0;
  vector<int> st{n};
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] > a[st.back()]) {
      st.push_back(i);
    }
  }
  while (!v.empty() && v.back().first > a[st.back()]) {
    v.pop_back();
  }

  ll bal = 0;
  priority_queue<int> g;
  for (int i = 0; i < n; ++i) {
    //cerr << "bd " << a[i] << '\n';
    bal += a[i];
    if (st.back() != i) {
      continue;
    }
    st.pop_back();
    while (!v.empty() && v.back().first > a[st.back()]) {
      g.push(v.back().second);
      //cerr << "got " << v.back().second << '\n';
      bal -= v.back().second;
      v.pop_back();
    }
    while (bal < 0) {
      bal += g.top();
      g.pop();
    }
  }
  cout << g.size() << '\n';
}