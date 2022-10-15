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
const int mod = 1e9 + 7;

vi p, was;
set<int> s;

int getp(int v) {
  if (p[v] == v) return v;
  return p[v] = getp(p[v]);
}

bool join(int a, int b) {
  a = getp(a);
  b = getp(b);
  if (a == b || (was[a] && was[b])) return 0;
  p[a] = b;
  if (was[a]) {
    was[b] = was[a];
  }
  return 1;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  vl pw(1e6, 1);
  for (int i = 1; i < pw.size(); ++i) pw[i] = pw[i - 1] * 2 % mod;
  int n, m;
  cin >> n >> m;
  was.assign(m, 0);
  p.resize(m);
  for (int i = 0; i < p.size(); ++i) p[i] = i;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    vi x(k);
    for (int j = 0; j < k; ++j) {
      cin >> x[j];
      --x[j];
    }
    if (k == 1) {
      int pr = getp(x[0]);
      if (!was[pr]) {
        was[pr] = i + 1;
        s.insert(i + 1);
      }
    }
    if (k == 2) {
      if (join(x[0], x[1])) {
        s.insert(i + 1);
      }
    }
  }
  cout << pw[s.size()] << ' ' << s.size() << endl;
  for (int i : s) cout << i << ' ';
  cout << endl;
  return 0;
}