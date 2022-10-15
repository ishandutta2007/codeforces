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
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

vi p, sz;

int getp(int v) {
  if (p[v] == v) return v;
  return p[v] = getp(p[v]);
}

bool join(int a, int b) {
  a = getp(a);
  b = getp(b);
  if (a == b) return false;
  if (rand() % 2) swap(a, b);
  p[a] = b;
  sz[b] += sz[a];
  return true;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  p.resize(n);
  sz.assign(n, 0);
  for (int i = 0; i < n; ++i) p[i] = i;
  vi x(k);
  for (int i = 0; i < k; ++i) {
    cin >> x[i];
    --x[i];
    sz[x[i]]++;
  }
  vector<array<int, 3>> e(m);
  for (int i = 0; i < m; ++i) {
    cin >> e[i][1] >> e[i][2] >> e[i][0];
    --e[i][1]; --e[i][2];
  }
  sort(e.begin(), e.end());
  for (auto v : e) {
    join(v[1], v[2]);
    int p = getp(v[1]);
//    cerr << v[1] << ' ' << v[2] << ' ' << sz[p] << endl;
    if (sz[p] == k) {
      for (int i = 0; i < k; ++i) cout << v[0] << ' ';
      return 0;
    }
  }
  return 0;
}