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
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;

int d[1505][1505];

void upd(int & a, int b) {
  a = max(a, b);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, s, m, k;
  cin >> n >> s >> m >> k;
  vi a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
/*  vi ts = a;
  sort(ts.begin(), ts.end());
  for (int i = 0; i < n; ++i) {
    a[i] = lower
  }*/
  vii v(s);
  for (int i = 0; i < s; ++i) {
    cin >> v[i].first >> v[i].second;
    --v[i].first; --v[i].second;
    v[i].second *= -1;
  }
  sort(v.begin(), v.end());
  vii nv(1, v[0]);
  for (int i = 1; i < v.size(); ++i) {
    if (v[i].second < nv.back().second) {
      nv.push_back(v[i]);
    }
  }
  v.swap(nv);
  for (pii& p : v) {
    p.second *= -1;
//    cerr << p.first << ' ' << p.second << endl;
  }
  const int MAX = 1e9;
  int l = 0, r = MAX + 1;
  while (r - l > 1) {
    int x = (l + r) / 2;
    vi s(n + 1);
    for (int i = 0; i < n; ++i) {
      s[i+1] = s[i] + (a[i] <= x);
    }
    memset(d, 0, sizeof(d));
    int it = 0, itr = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= m; ++j) {
        upd(d[i + 1][j], d[i][j]);
      }
      while (it < v.size() && v[it].first < i) ++it;
      if (it < v.size() && v[it].first == i) {
        int cnt = s[v[it].second + 1] - s[v[it].first];
        for (int j = 0; j <= m; ++j) {
          upd(d[v[it].second + 1][j + 1], d[i][j] + cnt);
        }
        while (itr < v.size() && v[itr].second < i) ++itr;
        if (itr < it) {
          int rem = s[v[itr].second + 1] - s[i];
          for (int j = 0; j <= m; ++j) {
            upd(d[v[it].second + 1][j + 1], d[v[itr].second + 1][j] + cnt - rem);
          }
        }
      }
    }
    bool ok = false;
    for (int j = 0; j <= m; ++j) if (d[n][j] >= k) {
      ok = true;
    }
    if (ok) r = x;
    else l = x;
  }
  if (r > MAX) r = -1;
  cout << r << endl;
  return 0;
}