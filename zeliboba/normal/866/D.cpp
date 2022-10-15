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
/*
vi fen;

void add(int i) {
  for (; i < fen.size(); i |= i + 1)
    fen[i]++;
}

int sum(int i) {
  int s = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    s += fen[i];
  return s;
}*/

const int N = 1 << 19;
int t[2 * N], add[2 * N];
 
void update (int v, int tl, int tr, int l, int r, int a) {
	if (l > r)
		return;
	if (l == tl && tr == r) {
		t[v] += a;
    add[v] += a;
//    cerr << "add " << l << ' ' << r << ' ' << a << ' ' << v << ' ' << t[v] << endl;
  } else {
		int tm = (tl + tr) / 2;
    add[2 * v] += add[v];
    add[2 * v + 1] += add[v];
    t[2 * v] += add[v];
    t[2 * v + 1] += add[v];
    add[v] = 0;
		update (v*2, tl, tm, l, min(r,tm), a);
		update (v*2+1, tm+1, tr, max(l,tm+1), r, a);
    t[v] = min(t[2*v], t[2*v + 1]);
	}
//  cerr << v << ' ' << t[v] << ' ' << tl << ' ' << tr << endl;
}
 
ll get_min (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 1e18;
	if (l == tl && tr == r) {
		return t[v];
  } else {
  	int tm = (tl + tr) / 2;
    add[2 * v] += add[v];
    add[2 * v + 1] += add[v];
    t[2 * v] += add[v];
    t[2 * v + 1] += add[v];
    add[v] = 0;
    return min(get_min(v*2, tl, tm, l, min(r,tm)),
               get_min(v*2+1, tm+1, tr, max(l,tm+1), r) );
  }
}

void out(vi v) {
  for (int x : v) cerr << x << ' '; cerr << endl;
}

vi f(vi v) {
  int n = v.size();
  vi res;
  memset(t, 0, sizeof(t));
  memset(add, 0, sizeof(add));
  for (int i = 0; i < n; ++i) {
    update(1, 0, N-1, i, i, i + 1);
  }
  set<int> w;
  for (int x : v) {
    update(1, 0, N-1, x, n - 1, -2);
    if (get_min(1, 0, N-1, x, n-1) >= 0) {
      res.push_back(x);
      w.insert(x);
    } else {
      update(1, 0, N-1, x, n - 1, 1);
      auto it = w.lower_bound(x);
      if (get_min(1, 0, N-1, x, n-1) < 0 && it != w.end()) {
        update(1, 0, N-1, *it, n-1, 1);
        w.erase(it);
      }
    }
  }
//  out(v);
//  out(res);
  return res;
}

vi g(vi v, vi v2) {
  int n = v.size();
  vi used(n);
  set<int> w;
  for (int x : v2) {
    used[x] = 1;
    w.insert(x);
  }
  vi res;
  for (int x : v) if (!used[x]) {
    auto it = w.lower_bound(x);
    if (it != w.end()) {
      w.erase(it);
      res.push_back(x);
    }
  }
//  out(v);
//  out(res);
  return res;
}

ll solve(vi p) {
  int n = p.size();
  vii ts(n);
  for (int i = 0; i < n; ++i) {
    ts.emplace_back(p[i], i);
  }
  sort(ts.rbegin(), ts.rend());
  vi ord(n);
  for (int i = 0; i < n; ++i) ord[i] = ts[i].second;
  vi v1 = f(ord);
  reverse(ord.begin(), ord.end());
//  for (int i = 0; i < n; ++i) ord[i] = n - 1 - ord[i];
  vi v2 = g(ord, v1);
//  for (int i = 0; i < v2.size(); ++i) v2[i] = n - 1 - v2[i];
  ll res = 0;
  for (int i : v1) res += p[i];
  for (int i : v2) res -= p[i];
  return res;
}

ll stupid(vi p) {
  int n = p.size();
  vl d(n + 1, -1e18);
  d[0] = 0;
  for (int x : p) {
    vl nd = d;
    for (int i = 0; i + 1 < d.size(); ++i) {
      nd[i+1] = max(nd[i+1], d[i] - x);
      nd[i] = max(nd[i], d[i+1] + x);
    }
    d.swap(nd);
  }
  return d[0];
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  for (int n = 1; n <= 0; ++n) {
    cerr << n << endl;
    vi p(n);
    for (int test = 0; test < 1000; ++test) {
      for (int i = 0; i < n; ++i) p[i] = rand() % 5;
      ll s1 = solve(p), s2 = stupid(p);
      if (s1 != s2) {
        out(p);
        cerr << s1 << ' ' << s2 << endl;
        assert(s1 == s2);
      }
    }
  }
  int n;
  cin >> n;
  vi p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  cout << solve(p) << endl;
  return 0;
}