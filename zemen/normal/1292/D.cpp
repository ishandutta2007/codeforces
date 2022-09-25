#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int deg(int k, int p) {
  int res = 0;
  while (k > 0) {
    res += k / p;
    k /= p;
  }
  return res;
}

const int M = 5005;
bool np[M];
vector<int> ps;

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  for (int i = 2; i < M; ++i) {
    if (!np[i]) {
      for (int j = 2 * i; j < M; j += i) {
        np[j] = true;
      }
      ps.push_back(i);
    }
  }
  reverse(ps.begin(), ps.end());

  ios::sync_with_stdio(false);
  cin.tie(0);
  
  vector<int> a(M);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[x]++;
  }

  ll res = 0;
  for (int i = 0; i < M; ++i) {
    for (auto p : ps) {
      res += deg(i, p) * (ll) a[i];
    }
  }

  //cerr << "res: " << res << '\n';
  for (auto p : ps) {
    vector<int> d(M);
    for (int i = 0; i < M; ++i) {
      d[i] = deg(i, p);
    }
    int c;
    for (c = 1; ; ++c) {
      int cnt = 0;
      for (int i = 0; i < M; ++i) {
        cnt += (d[i] >= c) * a[i];
      }
      if (cnt * 2 <= n) {
        break;
      }
      res -= 2 * cnt - n;
    }
    --c;
    for (int i = 0; i < M; ++i) {
      if (d[i] != c) {
        a[i] = 0;
      }
    }
  }
  cout << res << '\n';
}