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
#include <array>
#include <bitset>
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
  int q;
  cin >> q;
  map<ll, ll> c;
  for (int qq = 0; qq < q; ++qq) {
    int t, w;
    ll u, v;
    cin >> t >> u >> v;
    if (t == 1) {
      cin >> w;
      while (u != v) {
        if (u > v) swap(u, v);
        c[v] += w;
        v /= 2;
      }
    } else {
      ll ans = 0;
      while (u != v) {
        if (u > v) swap(u, v);
        if (c.count(v)) ans += c[v];
        v /= 2;
      }
      cout << ans << endl;
    }
  }
  return 0;
}