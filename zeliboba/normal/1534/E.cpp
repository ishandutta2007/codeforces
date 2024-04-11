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

const int DEBUG = 0;
vi hidden;

int ask(const vi &v) {
  cout << "?";
  for (int i : v) {
    cout << ' ' << i + 1;
  }
  cout << endl;
//  for (int i : v) assert(i >= 0);
  int x = 0;
  if (!DEBUG) {
    cin >> x;
  } else {
    for (int i : v) x ^= hidden[i];
  }
  return x;
}

void solve(int n, int k) {
  if (n % 2 && k % 2 == 0) {
    cout << -1 << endl;
    return ;
  }
  if (DEBUG) {
    cerr << n << ' ' << k << endl;
    hidden.resize(n);
    for (int i = 0; i < n; ++i) hidden[i] = rand() % (int)1e9;
  }
  int res = 0;
  if (n % k == 0) {
    vi v(k);
    for (int j = 0; j < n; j += k) {
      for (int i = 0; i < k; ++i) v[i] = i + j;
      res ^= ask(v);
    }
  } else if (k % 2) {
    int t = (n + k - 1) / k;
    if (t % 2 != n % 2) ++t;
    while (1) {
      int t1 = t % 2 ? t : t - 1;
      if ((k * t + t1 - 1) / t1 <= n) break;
      t += 2;
    }
    vvi v(t);
    while (1) {
      int s = 0;
      for (int i = 0; i < v.size(); ++i) s += k - v[i].size();
      if (s == n) {
        int it = 0;
        for (auto& x : v) while (x.size() < k) {
          x.push_back(it++);
        }
        break;
      } else {
        assert(s >= n + 2);
        sort(v.begin(), v.end(), [&](const auto&l, const auto& r){return l.size() < r.size();});
        int c = t;
        while (v[c - 1].size() == k) --c;
        c = min(c, s - n + 1);
        if (c % 2 == 0) --c;
        for (int i = 0; i < c; ++i) {
          v[i].push_back(n - 1);
        }
        --n;
      }
    }
    for (const auto& x : v) res ^= ask(x);
  } else {
    int t = (n + k - 1) / k;
    if (t == 2) ++t;
    vvi v(t);
    while (1) {
      int s = 0;
      for (int i = 0; i < v.size(); ++i) s += k - v[i].size();
      if (s == n) {
        int it = 0;
        for (auto& x : v) while (x.size() < k) {
          x.push_back(it++);
        }
        break;
      } else {
        assert(s >= n + 2);
        sort(v.begin(), v.end(), [&](const auto&l, const auto& r){return l.size() < r.size();});
        v[0].push_back(n - 1);
        v[1].push_back(n - 1);
        v[2].push_back(n - 1);
        --n;
      }
    }
    for (const auto& x : v) res ^= ask(x);
  }
  cout << "! " << res << endl;
  if (DEBUG) {
    int ans = 0;
    for (int i : hidden) ans ^= i;
    assert(ans == res);
  }
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (DEBUG) for (int n = 1; n <= 50; ++n) for (int k = 1; k <= n; ++k) for (int t = 0; t < 100; ++t) {
    solve(n, k);
  }
  int n, k;
  cin >> n >> k;
  solve(n, k);
  return 0;
}