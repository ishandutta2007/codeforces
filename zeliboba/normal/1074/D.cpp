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

vi p, r, xr;

int getp(int v) {
  if (p[v] == v) return v;
  int pr = getp(p[v]);
  xr[v] ^= xr[p[v]];
  p[v] = pr;
  return pr;
}

bool join(int a, int b, int val) {
  int pa = getp(a);
  int pb = getp(b);
  if (pa == pb) return false;
  if (r[pa] > r[pb]) {
    swap(a, b);
    swap(pa, pb);
  }
  p[pa] = pb;
  if (r[pa] == r[pb]) ++r[pb];
  xr[pa] = val ^ xr[a] ^ xr[b];
  return true;
}

int get_ind(int x, unordered_map<int, int>& ind) {
  if (ind.count(x)) return ind[x];
  int sz = ind.size();
  ind[x] = sz;
  return sz;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int Q;
  cin >> Q;
  r.assign(2 * Q + 2, 0);
  p.resize(r.size());
  for (int i = 0; i < (int)p.size(); ++i) p[i] = i;
  xr.assign(r.size(), 0);
  unordered_map<int, int> ind;
  ind.reserve(r.size());
  int last = 0;
  for (int q = 0; q < Q; ++q) {
    int type, l, r;
    cin >> type >> l >> r;
    l ^= last;
    r ^= last;
    if (l > r) swap(l, r);
    ++r;
    int a = get_ind(l, ind);
    int b = get_ind(r, ind);
    int pa = getp(a), pb = getp(b);
    if (type == 1) {
      int val;
      cin >> val;
      val ^= last;
      if (pa != pb) {
        join(a, b, val);
      }
    } else {
      if (pa == pb) {
        last = (xr[a] ^ xr[b]);
        cout << last << '\n';
      } else {
        cout << "-1\n";
        last = 1;
      }
    }
  }
  return 0;
}