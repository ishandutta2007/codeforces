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

int ind[1000][1000];
int q[100000];

int main() {
  int n;
  cin >> n;
  vi a(n);
  map<int, int> w;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    w[a[i]]++;
  }
  sort(a.begin(), a.end());
  vi c(w.size()), v(w.size());
  int i = 0;
  int res = min(2, n);
  for (const auto & it : w) {
    v[i] = it.first;
    c[i] = it.second;
    if (v[i] == 0) res = max(res, c[i]);
    ++i;
  }
  for (int i = 0; i < v.size(); ++i) for (int j = i; j < v.size(); ++j) {
    int val = v[i]+v[j];
    int t = lower_bound(v.begin(), v.end(), val) - v.begin();
    if (t < v.size() && v[t] == val) {
      ind[i][j] = ind[j][i] = t;
    } else {
      ind[i][j] = ind[j][i] = -1;
    }
  }
  for (int i = 0; i < v.size(); ++i) for (int j = 0; j < v.size(); ++j) if (ind[i][j] != -1) {
    if (v[i] == 0 && v[j] == 0) continue;
    if (i == j && c[i] < 2) continue;
    c[i]--; c[j]--;
    q[0] = i; q[1] = j;
    int x = i, y = j, cnt = 2;
    while (ind[x][y] != -1) {
      x = ind[x][y];
      if (c[x] <= 0) break;
      swap(x, y);
      q[cnt] = y;
      ++cnt;
      --c[y];
    }
//    if (cnt == 5) for (int t = 0; t < cnt; ++t) cerr << v[q[t]] << ' '; cerr << endl;
    res = max(res, cnt);
    for (int t = 0; t < cnt; ++t) ++c[q[t]];
  }
  cout << res << endl;
  return 0;
}