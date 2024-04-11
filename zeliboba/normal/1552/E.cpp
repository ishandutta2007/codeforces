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
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
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
//const int mod = ;

void solve(int n, int k, vi c) {
  vi a(n, -1), b(n);
  vi w(n);
  for (int s = 0; s < n; s += k - 1) {
    vi v;
    for (int i = 0; i < c.size(); ++i) if (c[i] >= s && c[i] < s + k - 1) {
      v.push_back(i);
    }
    int it = 0;
    for (int x = s; x < min(n, s + k - 1); ++x) {
      vi pr(n, -1);
      while (it < v.size() && (pr[c[v[it]]] == -1 || a[c[v[it]]] != -1)) {
        pr[c[v[it]]] = v[it];
        ++it;
      }
      assert(it < v.size());
      a[c[v[it]]] = pr[c[v[it]]];
      b[c[v[it]]] = (v[it]);
      ++it;
    }
  }
  assert(a.size() == n);
  vi x(c.size());
  for (int i = 0; i < a.size(); ++i) {
    //cout << a[i] + 1 << ' ' << b[i] + 1 << endl;
    for (int j = a[i]; j <= b[i]; ++j) ++x[j];
    assert(c[a[i]] == c[b[i]]);
    assert(c[a[i]] == i);
    cout << a[i] + 1 << ' ' << b[i] + 1 << '\n';
  }
  for (int i = 0; i < c.size(); ++i) assert(x[i] <= (n + k - 2) / (k - 1));
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (0) for (int n = 1; n <= 10; ++n) for (int k = 2; k <= 10; ++k) {
    for (int t = 0; t < 1000; ++t) {
      vi c(n * k), ord(n * k);
      for (int i = 0; i < ord.size(); ++i) ord[i] = i;
      random_shuffle(ord.begin(), ord.end());
      for (int i = 0; i < ord.size(); ++i) c[ord[i]] = i / k;
      for (int x : c) cerr << x << ' ';
      cerr << endl;
      solve(n, k, c);
    }
  }
  int n, k;
  cin >> n >> k;
  vi c(n * k);
  for (int i = 0; i < c.size(); ++i) {
    cin >> c[i];
    --c[i];
  }
  solve(n, k, c);
  return 0;
}