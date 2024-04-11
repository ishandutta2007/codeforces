#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

ll mi(const vl & v) {
  ll res = v[0];
  for (auto x : v) res = min(res, x);
  return res;
}

queue<int> q[5][5];
int n, k, b, c;

ll f(ll base, ll x) {
    return (base - x) / 5 * b + (base - x) % 5 * c;
}

int main() {
  cin >> n >> k >> b >> c;
  vi t(n);
  for (int i = 0; i < n; ++i) scanf("%d", &t[i]);
  sort(t.begin(), t.end());
  b = min(b, 5*c);
  vl x(5), base(5);
  ll ans = 1e18;
  for (int i = 0; i < n; ++i) {
    vl nbase(5);
    for (int r = 0; r < 5; ++r) {
      nbase[r] = t[i];
      while ((nbase[r] - r) % 5) nbase[r] += 1;
    }
    for (int r = 0; r < 5; ++r) {
      x[r] += (nbase[r] - base[r]) / 5 * b * min(k, i) + (nbase[r] - t[i]) * c;
      q[r][(t[i]%5+5) % 5].push(t[i]);
    }
    base.swap(nbase);
    if (i >= k) {
      for (int r = 0; r < 5; ++r) {
        int best = 0;
        ll ma = -1e18;
        for (int r1 = 0; r1 < 5; ++r1) if (!q[r][r1].empty()) {
          ll val = f(base[r], q[r][r1].front());
          if (val > ma) {
            ma = val;
            best = r1;
          }
        }
        ll val = q[r][best].front();
        x[r] -= f(base[r], val);
        q[r][best].pop();
      }
    }
    if (i >= k-1) ans = min(ans, mi(x));
  }
  cout << ans << endl;
  return 0;
}