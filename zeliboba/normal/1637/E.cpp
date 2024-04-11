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

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T = 1;
  if (!DEBUG) cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n = 300000, m = 0;
    if (!DEBUG) cin >> n >> m;
    vi a(n);
    unordered_map<int, int> cnt;
    for (int i = 0, j = 0; i < 10000; ++i) for (int t = 0; t <= i && j < n; ++t, ++j) {
      a[j] = i;
    }
    for (int i = 0; i < n; ++i) {
      if (!DEBUG) cin >> a[i];
      ++cnt[a[i]];
    }
    vi ts = a;
    sort(ts.begin(), ts.end());
    ts.resize(unique(ts.begin(), ts.end()) - ts.begin());
    vvi bad(ts.size());
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      int s = x + y;
      for (int t : {x, y}) {
        int j = lower_bound(ts.begin(), ts.end(), t) - ts.begin();
        bad[j].push_back(s - t);
      }
    }
    for (int i = 0; i < bad.size(); ++i) sort(bad[i].rbegin(), bad[i].rend());
    vi k, ord(n + 1);
    for (pii p : cnt) {
      k.push_back(p.second);
    }
//    cerr << k.size() << endl;
    sort(k.begin(), k.end());
    k.resize(unique(k.begin(), k.end()) - k.begin());
    for (int i = 0; i < k.size(); ++i) ord[k[i]] = i;
    vvi v(k.size());
    for (pii p : cnt) v[ord[p.second]].push_back(p.first);
    vi sz(v.size());
    for (int i = 0; i < v.size(); ++i) {
      sort(v[i].begin(), v[i].end());
      sz[i] = v[i].size() - 1;
    }
    ll res = 0;
    vi it;
    for (int i = 0; i < ts.size(); ++i) {
      it = sz;
      int cx = cnt[ts[i]];
      int x = ts[i];
      if (v[ord[cx]].back() == x) --it[ord[cx]];
      for (int y : bad[i]) {
        int ind = ord[cnt[y]];
        while (it[ind] >= 0 && (v[ind][it[ind]] == y || v[ind][it[ind]] == x)) --it[ind];
      }
      for (int ind = 0; ind < v.size(); ++ind) if (it[ind] >= 0) res = max(res, (x + v[ind][it[ind]]) * (ll)(cx + k[ind]));
    }
    cout << res << '\n';
  }
  return 0;
}