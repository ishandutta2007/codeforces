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

const int N = 1 << 16;
int t[2 * N];
int add[2 * N];

void build (const vi & a, int v, int tl, int tr) {
	if (tl == tr) {
		t[v] = a[tl];
//    if (t[v]) cerr << "build " << tl << ' ' << tr << ' ' << v << ' ' << t[v] << endl;
  } else {
		int tm = (tl + tr) / 2;
		build (a, v*2, tl, tm);
		build (a, v*2+1, tm+1, tr);
    t[v] = max(t[2*v], t[2*v + 1]);
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
    t[v] = max(t[2*v], t[2*v + 1]);
	}
//  cerr << v << ' ' << t[v] << ' ' << tl << ' ' << tr << endl;
}
 
int get_max (int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l == tl && tr == r) {
		return t[v];
  } else {
  	int tm = (tl + tr) / 2;
    add[2 * v] += add[v];
    add[2 * v + 1] += add[v];
    t[2 * v] += add[v];
    t[2 * v + 1] += add[v];
    add[v] = 0;
    return max(get_max(v*2, tl, tm, l, min(r,tm)),
               get_max(v*2+1, tm+1, tr, max(l,tm+1), r) );
  }
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vi a(n), p(n, -1), last(n, -1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
    p[i] = last[a[i]];
    last[a[i]] = i;
  }
  vi d(N);
  for (int tt = 0; tt < k; ++tt) {
    memset(t, 0, sizeof(t));
    memset(add, 0, sizeof(add));
    build(d, 1, 0, N - 1);
    vi nd = d;
    for (int i = 0; i < n; ++i) {
      update(1, 0, N - 1, p[i] + 1, i, 1);
      nd[i + 1] = get_max(1, 0, N - 1, 0, i);
//      cerr << t << ' ' << p[i] + 1 << ' ' << i << ' ' << nd[i+1] << endl;
    }
    d.swap(nd);
  }
  printf("%d\n", d[n]);
  return 0;
}