#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 1005;
vector<int> g[maxn];
char used[maxn];
int match[maxn];

bool kuhn(int u) {
  if (used[u]) {
    return false;
  }
  used[u] = true;
  for (int v : g[u]) {
    if (match[v] == -1 || kuhn(match[v])) {
      match[v] = u;
      return true;
    }
  }
  return false;
}

signed main() {
#ifdef LOCAL
  assert(freopen("g.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<ll> a, b;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    if (x * 3 > m) {
      a.push_back(x);
    } else {
      b.push_back(x);
    }
  }
  for (int i = 0; i < (int) a.size(); ++i) {
    for (int j = 0; j < (int) b.size(); ++j) {
      if (a[i] % b[j] == 0 && 2 * a[i] + b[j] <= m) {
        g[i].push_back(j);
        //cerr << "edge " << a[i] << ' ' << b[j] << '\n';
      }
    }
  }
  for (int i = 0; i < (int) b.size(); ++i) {
    match[i] = -1;
  }
  for (int i = 0; i < (int) a.size(); ++i) {
    for (int j = 0; j < (int) a.size(); ++j) {
      used[j] = false;
    }
    if (!kuhn(i)) {
      cout << -1 << '\n';
      return 0;
    }
  }
  cout << n - (int) a.size() << '\n';
  for (int j = 0; j < (int) b.size(); ++j) {
    if (match[j] == -1) {
      cout << b[j] * 3 << ' ' << b[j] * 2 << '\n';
    } else {
      int i = match[j];
      cout << 2 * a[i] + b[j] << ' ' << a[i] + b[j] << '\n';
    }
  }
}