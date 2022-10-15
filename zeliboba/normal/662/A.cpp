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
  ll all = 0, y = 0;
  vl x(n);
  for (int i = 0; i < n; ++i) {
    //cin >> x[i] >> y;
    scanf("%I64d%I64d", &x[i], &y);
    x[i] ^= y;
    all ^= y;
  }
  x.push_back(all);
  int it = 0;
  bool fail = 0;
  for (int ii = 0; ii < 63; ++ii) {
    ll b = (1LL << ii);
    for (int i = it; i < n; ++i) if (x[i] & b) {
      swap(x[it], x[i]);
      break;
    }
    if (it >= n || !(x[it] & b)) {
      if (x.back() & b) {
        fail = 1;
        break;
      }
      continue;
    }
    for (int i = it + 1; i < x.size(); ++i) if (x[i] & b) {
      x[i] ^= x[it];
    }
    ++it;
  }
  if (fail) {
    cout << "1/1\n";
  } else if (it == 0) {
    cout << "0/1\n";
  } else {
    ll x = (1LL << it);
    cout << x-1 << "/" << x << endl;
  }
  return 0;
}