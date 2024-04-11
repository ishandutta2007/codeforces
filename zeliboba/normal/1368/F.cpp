#include <stdio.h>
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
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

vi a;

void ask(vi v) {
  cout << v.size() << '\n';
  for (int x : v) {
    cout << x + 1 << ' ';
    a[x] = 1;
  }
  cout << endl;
  int x;
  cin >> x;
  --x;
  for (int i = 0; i < v.size(); ++i) a[(x + i) % a.size()] = 0;
}

void solve(int n) {
  a.assign(n, 0);
  pii ma(0, -1);
  for (int k = 1; k <= n; ++k) {
    ma = max(ma, pii(n - k + 1 - (n + k - 1) / k, -k));
  }
//  cerr << ma.first << ' ' << -ma.second << endl;
  if (ma.first) {
    int k = -ma.second;
    vi need;
    for (int i = 0; i < n; i += k) {
      for (int j = i; j < min(n - 1, i + k - 1); ++j) need.push_back(j);
    }
    assert(need.size() == ma.first + k - 1);
    while (1) {
      vi v;
      for (int i : need) {
        if (v.size() == k) break;
        if (a[i]) continue;
        v.push_back(i);
      }
      if (v.size() < k) break;
      ask(v);
    } 
  }
  cout << 0 << endl;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  solve(n);
  return 0;
}