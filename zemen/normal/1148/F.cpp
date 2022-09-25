#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int B = 62;

ll solve(vector<pair<int, ll>>& a, int b = B - 1) {
  if (b < 0) {
    ll sum = 0;
    for (auto p : a) {
      sum += p.first;
    }
    assert(sum < 0);
    return 0;
  }
  ll bit = 1ll << b;
  ll sum1 = 0;
  for (auto p : a) {
    if ((p.second & bit) && (p.second & (bit - 1)) == 0) {
      sum1 += p.first;
    }
  }
  ll res = 0;
  if (sum1 > 0) {
    res ^= bit;
    for (auto& p : a) {
      if (p.second & bit) {
        p.first *= -1;
      }
    }
  }
  return res ^ solve(a, b - 1);
}

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  mt19937 rnd;
  //while (true) {
    //const int V = 100;
    //const int B = 20;
    //const int N = 10;
    //int n = rnd() % N + 1;
    //int b = rnd() % B + 1;
    //vector<pair<int, ll>> val(n);
    //ll sum = 0;
    //for (int i = 0; i < n; ++i) {
      //val[i].first = rnd() % (2 * V + 1) - V;
      //val[i].second = rnd() % ((1 << b) - 1) + 1;
      //sum += val[i].first;
    //}
    //if (sum > 0) {
      //for (auto p : val) {
        //cerr << p.first << ' ' << p.second << '\n';
      //}
      //solve(val);
    //}
  //}
  int n;
  cin >> n;
  vector<pair<int, ll>> val(n);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> val[i].first >> val[i].second;
    sum += val[i].first;
  }
  if (sum < 0) {
    for (int i = 0; i < n; ++i) {
      val[i].first *= -1;
    }
  }
  ll res = solve(val);
  cout << res << '\n';
}