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

vi p;

int getp(int v) {
  if (p[v] == v) return v;
  return p[v] = getp(p[v]);
}

void join(int a, int b) {
  a = getp(a);
  b = getp(b);
  if (a == b) return;
  if (rand() % 2) swap(a, b);
  p[a] = b;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  p.resize(n + m);
  for (int i = 0; i < p.size(); ++i) p[i] = i;
  vii v(q);
  for (int i = 0; i < q; ++i) {
    cin >> v[i].first >> v[i].second;
    --v[i].first;
    --v[i].second;
    join(v[i].first, v[i].second + n);
  }
  int c = 0;
  for (int i = 0; i < p.size(); ++i) if (getp(i) == i) ++c;
  cout << c - 1 << endl;
/*  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  q = v.size();
  vi x(n), y(m);
  for (int i = 0; i < q; ++i) {
    ++x[v[i].first];
    ++y[v[i].second];
  }
  int c = 0;
  for (int i = 0; i < q; ++i) {
    if (x[v[i].first] == 1 && y[v[i].second] == 1) {
      ++c;
    }
  }
  int cx = 0, cy = 0;
  for (int i = 0; i < n; ++i) cx += x[i] == 0;
  for (int i = 0; i < m; ++i) cy += y[i] == 0;
  cout << max(m + n - 1 - q, max(cx, cy)) << endl;*/
  return 0;
}