#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxk = 3e6;
vector<pair<int, int>> in[maxk];
vector<pair<int, int>> out[maxk];
ll bin[maxk];
ll bout[maxk];
int n;

const int B = maxk - 100;

const ll infl = 1e12;
void calc(vector<pair<int, int>>* qs, ll* best) {
  vector<ll> cost(n, infl);
  ll total = infl * n;
  for (int i = 0; i < B + 5; ++i) {
    for (auto ev : qs[i]) {
      int id = ev.first;
      ll w = ev.second;
      if (cost[id] > w) {
        total -= cost[id];
        cost[id] = w;
        total += cost[id];
      }
    }
    best[i] = total;
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  int m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    int d, f, t, c;
    cin >> d >> f >> t >> c;
    if (t == 0) {
      in[d].emplace_back(f - 1, c);
    } else if (f == 0) {
      out[B - d].emplace_back(t - 1, c);
    } else
      assert(false);
  }
  calc(in, bin);
  calc(out, bout);
  ll res = 2e18;
  for (int i = 0; i < 1e6 + 100; ++i) {
    int j = B - (i + k + 1);
    res = min(res, bin[i] + bout[j]);
  }
  if (res >= infl)
    cout << -1 << '\n';
  else
    cout << res << '\n';
}