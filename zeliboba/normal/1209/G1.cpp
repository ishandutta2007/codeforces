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

const int N = 200000;
vi p;

int getp(int v) {
  if (p[v] == v) return v;
  return p[v] = getp(p[v]);
}

void join(int a, int b) {
  a = getp(a);
  b = getp(b);
  p[a] = b;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, Q;
  cin >> n >> Q;
  vi a(n);
  vvi w(N + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    w[a[i]].push_back(i);
  }
  p.resize(n);
  for (int i = 0; i < n; ++i) p[i] = i;
  vii q;
  for (int t = 0; t < w.size(); ++t) if (w[t].size() > 0) {
    q.emplace_back(w[t][0], w[t].back());
  }
  sort(q.begin(), q.end());
  vii v;
  if (!q.empty()) v.push_back(q[0]);
  for (pii p : q) {
    if (v.back().second < p.first) {
      v.push_back(p);
    } else {
      v.back().second = max(v.back().second, p.second);
    }
  }
  int res = 0;
  for (pii p : v) {
    int ma = 0;
    for (int i = p.first; i <= p.second; ++i) ma = max(ma, (int)w[a[i]].size());
    res += p.second - p.first + 1 - ma;
  }
  cout << res << endl;
  return 0;
}