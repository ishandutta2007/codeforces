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

int main() {
  int n;
  cin >> n;
  ll A, ca, cm, m;
  cin >> A >> ca >> cm >> m;
  vii a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  vl s(n + 1);
  for (int i = 0; i < n; ++i) s[i+1] = s[i] + a[i].first;
  ll ma = 0, best = 0, bestmi = 0;
  for (int c = 0; c <= n; ++c) {
    ll rem = m - (c*A - (s.back() - s[n-c]));
    if (rem < 0) break;
    int l = a[0].first, r = A + 1;
    while (r - l > 1) {
      ll x = (l + r) / 2;
      int it = lower_bound(a.begin(), a.end(), pii(x, 0)) - a.begin();
      it = min(it, n-c);
      if (it * x - s[it] <= rem) {
        l = x;
      } else {
        r = x;
      }
    }
    ll cur = c * ca + l * cm;
    if (cur > ma) {
      ma = cur;
      best = c;
      bestmi = l;
    }
  }
  for (int i = 0; i < best; ++i) a[n-i-1].first = A;
  vi res(n);
  for (int i = 0; i < n; ++i) {
    if (a[i].first < bestmi) a[i].first = bestmi;
    res[a[i].second] = a[i].first;
  }
  cout << ma << endl;
  for (int i = 0; i < res.size(); ++i) printf("%d ", res[i]);
  return 0;
}