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

void model(vi & a, const vii & v) {
  for (pii p : v) swap(a[p.first], a[p.second]);
}

bool check(int n, const vii & v) {
  vi a(n);
  for (int i = 0; i < n; ++i) a[i] = i;
  model(a, v);
  for (int i = 0; i < n; ++i) if (a[i] != i) return false;
  return true;
}

vii sol0, sol1;

void solve(int n, vii & res) {
  if (n < 4) return;
  solve(n - 4, res);
  for (int i = 0; i + 1 < n-4; i += 2) {
    res.push_back(pii(i, n-4));
    res.push_back(pii(i+1, n-3));
    res.push_back(pii(i+1, n-4));
    res.push_back(pii(i, n-3));
    res.push_back(pii(i, n-2));
    res.push_back(pii(i+1, n-1));
    res.push_back(pii(i+1, n-2));
    res.push_back(pii(i, n-1));
  }
//  cerr << n << ' ' << res.size() << endl;
  if (n % 2) {
    res.push_back(pii(n-5, n-4));
    res.push_back(pii(n-5, n-3));
    res.push_back(pii(n-5, n-2));
    res.push_back(pii(n-4, n-1));
    res.push_back(pii(n-5, n-1));
    for (pii p : sol1) {
      res.push_back(pii(p.first + n-4, p.second + n-4));
    }
  } else {
    for (pii p : sol0) {
      res.push_back(pii(p.first + n-4, p.second + n-4));
    }
  }
//  cerr << n << ' ' << res.size() << ' ' << sol1.size() << endl;
  assert(res.size() == n * (n-1) / 2);
//  assert(check(n, res));
}

void solve0() {
  vii v;
  for (int i = 0; i < 4; ++i) for (int j = i + 1; j < 4; ++j) v.push_back(pii(i,j));
  do {
    if (check(4, v)) {
      sol0 = v;
      break;
    }
  } while (next_permutation(v.begin(), v.end()));
  assert(!sol0.empty());
}

void solve1() {
  vii v;
  for (int i = 0; i < 4; ++i) for (int j = i + 1; j < 4; ++j) if (pii(i, j) != pii(0, 3)) v.push_back(pii(i,j));
  do {
    vi st = {3, 0, 1, 2};
    vi en = {0, 1, 2, 3};
    model(st, v);
    if (st == en) {
      sol1 = v;
      break;
    }
  } while (next_permutation(v.begin(), v.end()));
  assert(!sol1.empty());
}

int main() {
  std::ios::sync_with_stdio(false);
  solve0();
  solve1();
  int n;
  cin >> n;
  if (n * (n - 1) / 2 % 2) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  vii res;
  solve(n, res);
  for (int i = 0; i < res.size(); ++i) {
    cout << min(res[i].first, res[i].second) + 1 << " " << max(res[i].first, res[i].second) + 1 << endl;
  }
  return 0;
}