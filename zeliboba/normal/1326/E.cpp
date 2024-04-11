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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

const int N = 1 << 19;
ll t[2 * N];
ll add[2 * N];

void build (const vi & a, int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
//    if (t[v]) cerr << "build " << tl << ' ' << tr << ' ' << v << ' ' << t[v] << endl;
  } else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
    t[v] = min(t[2*v], t[2*v + 1]);
	}
}
 
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

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi p(n), q(n), invp(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    invp[p[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> q[i];
    --q[i];
  }
  int res = n;
  for (int i = 0; i < n; ++i) {
    while (get_min(1, 0, N - 1, 0, n - 1) >= 0) {
//      auto p = get_min(1, 0, N - 1, 0, n - 1);
//      cerr << res << ' ' << p << ' ' << invp[res] << endl;
      --res;
      assert(res >= 0);
      update(1, 0, N - 1, 0, invp[res], -1);
    }
    cout << res + 1 << ' ';
    update(1, 0, N - 1, 0, q[i], 1);
  }
  return 0;
}