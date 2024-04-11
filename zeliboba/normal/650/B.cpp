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

char s[1000000];

int f(const vi & v, int a, int b, int t) {
  int n = v.size();
  if (v[0]) t -= b;
  if (t <= 0) return 0;
  --t;
  int it = 1;
  while (it < v.size() && t >= a + v[it]*b + 1) {
    t -= a + v[it]*b + 1;
    ++it;
  }
  int ans = it;
//  cerr << it << ' ' << t << endl;
  for (int i = n-1; i >= 1; --i) {
    while (it > 1 && t < 2*a + v[i]*b + 1) {
      t += a + v[it-1]*b + 1;
      --it;
    }
    t -= 2*a + v[i]*b + 1;
    if (t < 0) break;
    ans = max(ans, it + n - i);
//    cerr << i << ' ' << it << ' ' << t << endl;
  }
  return min(ans, (int)v.size());
}

int main() {
  int n, a, b, T;
  scanf("%d%d%d%d%s", &n, &a, &b, &T, s);
  vi v(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'w') v[i] = 1;
  }
  int ans = f(v, a, b, T);
  if (n > 2) {
    reverse(v.begin() + 1, v.end());
    ans = max(ans, f(v, a, b, T));
  }
  cout << ans << endl;
  return 0;
}