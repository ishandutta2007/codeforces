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
typedef pair<ll, ll> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

const int N = 1 << 18;
ll add[2 * N];
pii mi[2 * N];

void upd(int i) {
  pii a = mi[2 * i], b = mi[2 * i + 1];
  if (pii(a.first, -a.second) < pii(b.first, -b.second)) mi[i] = a;
  else mi[i] = b;
}

void update (int v, int tl, int tr, int l, int r, ll a) {
  if (l > r)
    return;
  if (l == tl && tr == r) {
    mi[v].first += a;
    add[v] += a;
    //    cerr << "add " << l << ' ' << r << ' ' << a << ' ' << v << ' ' << t[v] << endl;
  } else {
    int tm = (tl + tr) / 2;
    add[2 * v] += add[v];
    add[2 * v + 1] += add[v];
    mi[2 * v].first += add[v];
    mi[2 * v + 1].first += add[v];
    add[v] = 0;
    update (v*2, tl, tm, l, min(r,tm), a);
    update (v*2+1, tm+1, tr, max(l,tm+1), r, a);
    upd(v);
    //t[v] = min(t[2*v], t[2*v + 1]);
  }
//  cerr << v << ' ' << mi[v].first << ' ' << mi[v].second << endl;
  //  cerr << v << ' ' << t[v] << ' ' << tl << ' ' << tr << endl;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  for (int i = N; i < 2 * N; ++i) mi[i] = pii(1e18, i);
  vl s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    mi[i + N] = pii(s[i], i);
  }
  for (int i = N - 1; i >= 0; --i) upd(i);
  vi p(n);
  for (int i = 0; i < n; ++i) {
//    cerr << i << ' ' << mi[1].second << endl;
    int j = mi[1].second;
    p[j] = i + 1;
    update(1, 0, N - 1, j + 1, n - 1, -i - 1);
    update(1, 0, N - 1, j, j, 1e18);
  }
  for (int x : p) cout << x << ' ';
  cout << endl;
  return 0;
}