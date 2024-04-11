#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 300300;
int c[maxn];

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  int n, k;
  cin >> n >> k;
  ll cost = 0;
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    cost -= c[i] * 1ll * i;
  }
  priority_queue<pair<int, int>> o;
  for (int i = 0; i < k; ++i) {
    o.emplace(c[i], i);
  }
  vector<int> tm(n);
  for (int i = k; i < n + k; ++i) {
    if (i < n) {
      o.emplace(c[i], i);
    }
    int cc = o.top().first;
    int id = o.top().second;
    o.pop();
    cost += cc * 1ll * i;
    tm[id] = i;
  }
  cout << cost << '\n';
  for (int t : tm)
    cout << t + 1 << ' ';
  cout << '\n';
}